
#include <cstdlib>
#include <iostream>
#include <set>
#include <map>
#include <fstream>
#include <chrono>
#include <iomanip>

#include "Compl-config.h"
#include "Complement/Options.h"
#include "Complement/BuchiAutomatonSpec.h"
#include "Automata/BuchiAutomaton.h"
#include "Automata/BuchiAutomataParser.h"
#include "Algorithms/Simulations.h"

using namespace std;

struct Params
{
  string output;
  string input;
};

int main(int argc, char *argv[])
{
  BuchiAutomataParser parser;
  Params params = { .output = "", .input = ""};
  ifstream os;

  if(argc == 2)
  {
    params.input = string(argv[1]);
  }
  else if(argc == 4 && strcmp(argv[2], "-o") == 0)
  {
    params.input = string(argv[1]);
    params.output = string(argv[3]);
  }
  else
  {
    cerr << "Unrecognized arguments" << endl;
    return 1;
  }

  string filename(params.input);
  os.open(params.input);
  if(os)
  {
    // const char* rabitpath_cstr = std::getenv("RABITEXE");
    // std::string rabitpath = (nullptr == rabitpath_cstr)? RABITEXE : rabitpath_cstr;

    BuchiAutomaton<string, string> ba = parser.parseBaFormat(os);
    //string cmd = "java -jar " + rabitpath + " " + filename + " " + filename + " -dirsim";
    Simulations sim;
    // istringstream strr(Simulations::execCmd(cmd));
    //
    // ba.setDirectSim(sim.parseRabitRelation(strr));
    auto ranksim = sim.directSimulation<string, string>(ba, "-1");
    ba.setDirectSim(ranksim);
    auto cl = set<std::string>();
    auto t1 = std::chrono::high_resolution_clock::now();

    ba.computeRankSim(cl);
    BuchiAutomaton<int, int> ren = ba.renameAut();
    BuchiAutomatonSpec sp(ren);
    ComplOptions opt = { .cutPoint = true, .CacheMaxState = 6, .CacheMaxRank = 8 };
    sp.setComplOptions(opt);
    BuchiAutomaton<StateSch, int> comp;
    try
    {
      comp = sp.complementSchOpt();
    }
    catch (const std::bad_alloc&)
    {
      os.close();
      cerr << "Memory error" << endl;
      return 2;
    }

    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();

    cerr << "Generated states: " << comp.getStates().size() << "\nGenerated trans: " << comp.getTransitions().size() << endl;

    map<int, int> id;
    for(auto al : comp.getAlphabet())
      id[al] = al;

    BuchiAutomaton<int, int> renCompl = comp.renameAutDict(id);
    renCompl.removeUseless();
    cerr << "States: " << renCompl.getStates().size() << "\nTransitions: " << renCompl.getTransitions().size() << endl;

    if(params.output != "")
    {
      ofstream ch;
      ch.open(params.output);
      if(!ch)
      {
        cerr << "Cannot open the output file" << endl;
        return 1;
      }
      ch << renCompl.toString();
      ch.close();
    }

    cerr << std::fixed;
    cerr << std::setprecision(2);
    cerr << "Time: " << (float)(duration/1000.0) << std::endl;

    cout << renCompl.toHOA();
  }
  os.close();
  return 0;
}
