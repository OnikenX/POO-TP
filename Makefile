all: vroom

dependecies = project/*.cpp
#project/surpresa.cpp project/rapido.cpp project/crazy.cpp

vroom: $(dependecies)
	g++ $(dependecies) -o vroom $(CXXFLAGS) -lncurses

project/%.o: project/%.cpp
	$(CXX) -c $< $(CXXFLAGS) -lncurses

debug: CXXFLAGS += -g -Wall
debug: vroom

clear:
	rm project/*.o vroom

