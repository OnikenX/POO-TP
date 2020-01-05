#include "./headers/carro.hpp"

//construtor
Carro::Carro(std::string marca, char id, float max_energia, float start_energia, int max_speed, std::string modelo)
{
    this->start_energia = this->energia = start_energia;
    this->modelo = modelo;
    this->max_energia = max_energia;
    this->marca = marca;
    this->speed = 0;
    this->max_speed = max_speed;
    this->id = id;
    this->condutor = NULL;
}

//gets
char Carro::getid()
{
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
    return max_speed;
}

int Carro::travar()
{
    if (energia == 0)
        --this->speed;
    if (this->speed > 0)
    {
        --this->speed;
        return 0;
    }
    return -1;
}

int Carro::acelarar()
{
    if (energia == 0)
        return 0;
    if (this->speed < this->max_speed)
    {
        ++this->speed;
        return 0;
    }
    return -1;
}

int Carro::carregamento(int encher)
{
    if (getspeed() > 0)
        return 1;

    if ((energia += encher) > max_energia)
        energia = max_energia;
    return 0;
    return 2;
}

void Carro::calculargasto()
{
    if (energia > 0 || speed > 0)
        energia = energia - (speed * 0.1);
}

void Carro::getasstring()
{
    std::cout << "O carro cujo o id é '" << id << "', tem a marca " << marca << ", o modelo " << modelo << ", energia de " << energia << ", energia maxima " << max_energia << " e uma volcidade maxima de " << max_speed;
    if (getpiloto() != NULL)
        std::cout << " e é conduzido pelo piloto " << getpiloto()->getnome() << "." << std::endl;
    else
        std::cout << " e não tem piloto." << std::endl;
}

int Carro::meter(Piloto *aentrar)
{
    if (aentrar == NULL)
    {
        condutor = NULL;
        return 0;
    }

    if (condutor != NULL)
    {
        std::cout << "Já tem condutor" << std::endl;
        return 1;
    }

    if (speed != 0)
        return 2;

    condutor = aentrar;
    return 0;
}

Piloto *Carro::getpiloto()
{
    return condutor;
}
