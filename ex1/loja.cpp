#include "loja.h"
#include <string>
#include <sstream>

std::ostream & operator<< (std::ostream & out, const Imovel & a){
    out << a.getAsString();
    return out;
}

Loja::Loja(int area){
    setPreco(area * 15 );
};

