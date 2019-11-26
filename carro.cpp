#include "carro.hpp"

//construtor
Carro::Carro ( std::string marca, char id, float max_energia,float start_energia, std::string modelo)
{
    this->start_energia = this->energia = start_energia;
    this->modelo = modelo;
    this->max_energia = max_energia;
    this->marca = marca;
    this->speed = 0;
}

//gets
char Carro::getid(){
    return this->id;
}

int Carro::getenergia()
{
    return this->energia;
}

int Carro::getmax_energia()
{
    return max_energia;
}

int Carro::getstart_energia()
{
    return start_energia;
}

int Carro::getspeed()
{
    return speed;
}

int Carro::getmaxspeed()
{
    return maxspeed;
}

int Carro::travar()  
{
        if(energia == 0)
            --this->speed;
    if ( this->speed > 0 ) {
        --this->speed;
        return 0;
    }
    return -1;
}

int Carro::acelarar()
{
    if(energia == 0)
        return 0;
    if ( this->speed < this->maxspeed ) {
        ++this->speed;
        return 0;
    }
    return -1;
}

int Carro::carregamento(int encher){
    if (getspeed()>0)
        return 1;
    
    if((energia += encher)> max_energia)
        energia = max_energia;
        return 0;
}

void Carro::calculargasto(){
    if (energia > 0 || speed > 0)
        energia = energia - (speed * 0.1);
}


