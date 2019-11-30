
all: 
	$(info apenas o "modo1" e "test" estam disponivel para compilar)


modo1: modo1.cpp carro.cpp global.cpp dgv.cpp piloto.cpp
	$(info compiling modo 1)
	g++ modo1.cpp carro.cpp global.cpp dgv.cpp piloto.cpp  -o modo1 -g

test:
	clear && g++ utils.cpp modo1.cpp -o vroom -g && echo compilacao completa &&./vroom && echo