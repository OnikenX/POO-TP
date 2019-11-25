
all: vroom

vroom: main.cpp
	g++ main.cpp carro.cpp global.cpp dgv.cpp  -o vroom -g
