#include "carro.hpp"

char CarroIdused = a;

Carro::Carro(std::string marc, std::string mod = "base", char ide, unsigned int ener, unsigned int maxen,unsigned int start_energia){
    
};

int Carro::travar(){
    if(this->speed > 0){--this->speed;return 0;}
    return -1;
}

int Carro::acelarar(){
    if (this->speed < this->maxspeed){++this->speed;return 0;}
    return -1;
}
