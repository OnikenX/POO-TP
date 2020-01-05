#include "imovel.h"
#include <sstream>


int Imovel::getArea()
{
    return area;
}

int Imovel::getAndar()
{
    return andar;
}
int Imovel::getPreco()
{
    return preco;
}

int Imovel::getCodigo()
{
    return codigo;
}

int Imovel::setAndar(int andar)
{
    this->andar = andar;
    return 0;
}

int Imovel::setPreco(int preco)
{
    this->preco = preco;
    return 0;
}
int Imovel::setCodigo(int codigo)
{
    this->codigo = codigo;
    return 0;
}

std::string Imovel::getAsString() const
{
    std::ostringstream os;
    os << area << "," << andar << "," << preco << "," << codigo;
    return os.str();
}