#include "carro.hpp"

char CarroIdused = a;

Carro::Carro(std::string, std::string, char, unsigned int, unsigned int,unsigned int){
    
};

int Carro::travar(){
    if(this->speed > 0){--this->speed;return 0;}
    return -1;
}

int Carro::acelarar(){
    if (this->speed < this->maxspeed){++this->speed;return 0;}
    return -1;
}
