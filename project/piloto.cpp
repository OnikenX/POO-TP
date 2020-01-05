#include "headers/piloto.hpp"

Piloto::Piloto(std::string nome)
{
    //verificar se o nome é unico
    this->nome = nome;
    this->aconduzir = NULL;
}

int Piloto::meter(Carro *ameter=NULL)
{
    if (ameter == NULL)
    {
        this->aconduzir = NULL;
        return 0;
    }
    if (aconduzir != NULL)
        return 1;
    if (ameter->getspeed() != 0)
        return 2;

    aconduzir = ameter;
    return 0;
}
/*
int Piloto::tirar()
{
    if (aconduzir != NULL)
        return 2;

    aconduzir = NULL;
    return 0;
};
*/
std::string Piloto::getnome()
{
    return this->nome;
};

void Piloto::getasstring()
{
    std::cout << "O Piloto " << nome;
    if (aconduzir == NULL)
        std::cout << " não tem um carro para conduzir." << std::endl;
    else
    {
        std::cout << " conduz o carro cujo o id é " << aconduzir->getid() << "." << std::endl;
    }
};

Carro * Piloto::getcarro()
{
    return aconduzir;
};
