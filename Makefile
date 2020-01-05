all: vroom

dependecies = project/dgv.o project/carro.o project/piloto.o project/global.o project/main.o project/autodromo.o

vroom: $(dependecies)
	g++ $(dependecies) -o vroom $(CXXFLAGS)

project/%.o: %.cpp
	$(CXX) -c $< $(CXXFLAGS)

debug: CXXFLAGS += -g -Wall
debug: vroom

clear:
	rm project/*.o vroom

