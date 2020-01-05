
#include "imovel.h"
#include "apart.h"
#include <string>
#include <sstream>

Apart::Apart(int area, int andar, int quantos)
{
    setPreco(10 * area);
};

std::string Apart::stringGetAsString() const{
    std::ostringstream os;
    os << "AP: " << Imovel::getAsString()<< "," << quantos;
    return os.str();
}

