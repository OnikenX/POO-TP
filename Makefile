all: vroom

vroom: dgv.o carro.o piloto.o global.o main.o autodromo.o
	g++ main.o carro.o global.o dgv.o piloto.o autodromo.o -o vroom $(CXXFLAGS)

%.o: %.cpp
	$(CXX) -c $< $(CXXFLAGS)

debug: CXXFLAGS += -g -Wall
debug: vroom

clear:
	rm *.o vroom

