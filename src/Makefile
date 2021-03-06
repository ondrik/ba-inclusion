
CPPFLAGS=-std=c++17 -O2 -Wall -Wextra #-Wl,-no_pie
OBJ=obj
GCC=g++
SUFF=-lboost_regex

complement: ranker ranker-tight ranker-composition

test: test-parser test-kv-compl test-sch-compl test-process test-nfa-prop \
	test-sch-red-compl test-sch-hard test-simulation

test-parser: units/test-parser.cpp $(OBJ)/BuchiAutomataParser.o \
	$(OBJ)/BuchiAutomaton.o $(OBJ)/BuchiAutomatonSpec.o $(OBJ)/RankFunc.o \
	$(OBJ)/AutGraph.o $(OBJ)/Simulations.o $(OBJ)/AuxFunctions.o
	$(GCC) $(CPPFLAGS) -o units/$@ $^ $(SUFF)

test-kv-compl: units/test-kv-compl.cpp $(OBJ)/BuchiAutomataParser.o \
	$(OBJ)/BuchiAutomaton.o $(OBJ)/BuchiAutomatonSpec.o $(OBJ)/RankFunc.o \
	$(OBJ)/AutGraph.o $(OBJ)/Simulations.o $(OBJ)/AuxFunctions.o
	$(GCC) $(CPPFLAGS) -o units/$@ $^ $(SUFF)

test-hoa-parser: units/test-hoa-parser.cpp $(OBJ)/BuchiAutomataParser.o \
	$(OBJ)/BuchiAutomaton.o $(OBJ)/BuchiAutomatonSpec.o $(OBJ)/RankFunc.o \
	$(OBJ)/AutGraph.o $(OBJ)/Simulations.o $(OBJ)/AuxFunctions.o
	$(GCC) $(CPPFLAGS) -o units/$@ $^ $(SUFF)

test-sch-compl: units/test-sch-compl.cpp $(OBJ)/BuchiAutomataParser.o \
	$(OBJ)/BuchiAutomaton.o $(OBJ)/BuchiAutomatonSpec.o $(OBJ)/RankFunc.o \
	$(OBJ)/AutGraph.o $(OBJ)/Simulations.o $(OBJ)/AuxFunctions.o
	$(GCC) $(CPPFLAGS) -o units/$@ $^ $(SUFF)

compl-check: units/compl-check.cpp $(OBJ)/BuchiAutomataParser.o \
	$(OBJ)/BuchiAutomaton.o $(OBJ)/BuchiAutomatonSpec.o $(OBJ)/RankFunc.o \
	$(OBJ)/AutGraph.o $(OBJ)/Simulations.o $(OBJ)/AuxFunctions.o
	$(GCC) $(CPPFLAGS) -o units/$@ $^ $(SUFF)

test-sch-hard: units/test-sch-hard.cpp $(OBJ)/BuchiAutomataParser.o \
	$(OBJ)/BuchiAutomaton.o $(OBJ)/BuchiAutomatonSpec.o $(OBJ)/RankFunc.o \
	$(OBJ)/AutGraph.o $(OBJ)/Simulations.o $(OBJ)/AuxFunctions.o
	$(GCC) $(CPPFLAGS) -o units/$@ $^ $(SUFF)

test-sch-red-compl: units/test-sch-red-compl.cpp $(OBJ)/BuchiAutomataParser.o \
	$(OBJ)/BuchiAutomaton.o $(OBJ)/BuchiAutomatonSpec.o $(OBJ)/RankFunc.o \
	$(OBJ)/AutGraph.o $(OBJ)/Simulations.o $(OBJ)/AuxFunctions.o
	$(GCC) $(CPPFLAGS) -o units/$@ $^ $(SUFF)

test-sch-opt-compl: units/test-sch-opt-compl.cpp $(OBJ)/BuchiAutomataParser.o \
	$(OBJ)/BuchiAutomaton.o $(OBJ)/BuchiAutomatonSpec.o $(OBJ)/RankFunc.o \
	$(OBJ)/AutGraph.o $(OBJ)/Simulations.o $(OBJ)/AuxFunctions.o
	$(GCC) $(CPPFLAGS) -o units/$@ $^ $(SUFF)

test-nfa-prop: units/test-nfa-prop.cpp $(OBJ)/BuchiAutomataParser.o \
	$(OBJ)/BuchiAutomaton.o $(OBJ)/BuchiAutomatonSpec.o $(OBJ)/RankFunc.o \
	$(OBJ)/AutGraph.o $(OBJ)/Simulations.o $(OBJ)/AuxFunctions.o
	$(GCC) $(CPPFLAGS) -o units/$@ $^ $(SUFF)

test-process: units/test-process.cpp $(OBJ)/BuchiAutomataParser.o \
	$(OBJ)/BuchiAutomaton.o $(OBJ)/BuchiAutomatonSpec.o $(OBJ)/RankFunc.o \
	$(OBJ)/AutGraph.o $(OBJ)/Simulations.o $(OBJ)/AuxFunctions.o
	$(GCC) $(CPPFLAGS) -o units/$@ $^ $(SUFF)

test-simulation: units/test-simulation.cpp $(OBJ)/BuchiAutomataParser.o \
	$(OBJ)/BuchiAutomaton.o $(OBJ)/BuchiAutomatonSpec.o $(OBJ)/RankFunc.o \
	$(OBJ)/AutGraph.o $(OBJ)/Simulations.o $(OBJ)/AuxFunctions.o
	$(GCC) $(CPPFLAGS) -o units/$@ $^ $(SUFF)

ranker: ranker.cpp $(OBJ)/BuchiAutomataParser.o \
	$(OBJ)/BuchiAutomaton.o $(OBJ)/BuchiAutomatonSpec.o $(OBJ)/RankFunc.o \
	$(OBJ)/AutGraph.o $(OBJ)/Simulations.o $(OBJ)/AuxFunctions.o $(OBJ)/ranker-general.o
	$(GCC) $(CPPFLAGS) -o $@ $^ $(SUFF)

ranker-sim: ranker-sim.cpp $(OBJ)/BuchiAutomataParser.o \
	$(OBJ)/BuchiAutomaton.o  $(OBJ)/Simulations.o $(OBJ)/BuchiAutomatonSpec.o \
	$(OBJ)/RankFunc.o $(OBJ)/AutGraph.o $(OBJ)/AuxFunctions.o
	$(GCC) $(CPPFLAGS) -o $@ $^ $(SUFF)

ranker-composition: ranker-composition.cpp $(OBJ)/ranker-general.o $(OBJ)/AuxFunctions.o \
	$(OBJ)/RankFunc.o $(OBJ)/BuchiAutomaton.o $(OBJ)/BuchiAutomataParser.o \
	$(OBJ)/Simulations.o   $(OBJ)/AutGraph.o  $(OBJ)/BuchiAutomatonSpec.o
	$(GCC) $(CPPFLAGS) -o ranker-composition $^ $(SUFF)

ranker-tight: ranker-tight.cpp $(OBJ)/AuxFunctions.o $(OBJ)/ranker-general.o \
	$(OBJ)/RankFunc.o $(OBJ)/BuchiAutomaton.o $(OBJ)/BuchiAutomataParser.o \
	$(OBJ)/Simulations.o   $(OBJ)/AutGraph.o  $(OBJ)/BuchiAutomatonSpec.o
	$(GCC) $(CPPFLAGS) -o $@ $^ $(SUFF)

$(OBJ)/ranker-general.o: Ranker-general.cpp $(OBJ)/BuchiAutomataParser.o \
	$(OBJ)/BuchiAutomaton.o $(OBJ)/BuchiAutomatonSpec.o $(OBJ)/RankFunc.o \
	$(OBJ)/AutGraph.o $(OBJ)/Simulations.o $(OBJ)/AuxFunctions.o
	$(GCC) $(CPPFLAGS) -c -o $@ $<

$(OBJ)/BuchiAutomataParser.o: Automata/BuchiAutomataParser.cpp \
	Automata/BuchiAutomataParser.h $(OBJ)/BuchiAutomaton.o
	$(GCC) $(CPPFLAGS) -c -o $@ $<

$(OBJ)/BuchiAutomaton.o: Automata/BuchiAutomaton.cpp Automata/BuchiAutomaton.h \
	Complement/StateSch.h Complement/StateKV.h Complement/RankFunc.h Automata/APSymbol.h \
	$(OBJ)/AutGraph.o $(OBJ)/AuxFunctions.o
	$(GCC) $(CPPFLAGS) -c -o $@ $<

$(OBJ)/RankFunc.o: Complement/RankFunc.cpp Complement/RankFunc.h
	$(GCC) $(CPPFLAGS) -c -o $@ $<

$(OBJ)/Simulations.o: Algorithms/Simulations.cpp Algorithms/Simulations.h \
	$(OBJ)/BuchiAutomaton.o
	$(GCC) $(CPPFLAGS) -c -o $@ $<

$(OBJ)/AutGraph.o: Automata/AutGraph.cpp Automata/AutGraph.h
	$(GCC) $(CPPFLAGS) -c -o $@ $<

$(OBJ)/AuxFunctions.o: Algorithms/AuxFunctions.cpp Algorithms/AuxFunctions.h
	$(GCC) $(CPPFLAGS) -c -o $@ $<

$(OBJ)/BuchiAutomatonSpec.o: Complement/BuchiAutomatonSpec.cpp \
	Automata/BuchiAutomaton.h Complement/StateKV.h Complement/StateSch.h \
	Complement/BuchiAutomatonSpec.h Complement/Options.h $(OBJ)/RankFunc.o \
	$(OBJ)/AuxFunctions.o $(OBJ)/BuchiAutomaton.o
	$(GCC) $(CPPFLAGS) -c -o $@ $<

clean:
	rm -f obj/*.o units/test-parser units/test-kv-compl units/test-sch-red-compl \
	units/test-sch-compl units/test-nfa-prop units/test-sch-hard \
	units/test-simulation units/test-process units/test-simulation ranker \
	units/test-hoa-parser ranker-composition ranker-sim ranker-tight
