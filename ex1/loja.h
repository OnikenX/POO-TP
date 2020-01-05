#ifndef LOJA_H
#define LOJA_H
#include "imovel.h"
class Loja : public Imovel
{

public:
    Loja(int area);

};

std::ostream& operator<<(std::ostream &out, const Imovel &a);

#endif //LOJA_H