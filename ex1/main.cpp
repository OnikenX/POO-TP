/*
ficha 7 - ex 1 

                    imovel - class pai
                   -comum

loja                                apartamento     => classes filhos
    area                                area
    preco                               preco
    andar - r/c                         andar
    codigo                              quantos
                                        codigo


*/
#include <iostream>
#include <string>

#include "imovel.h"
#include "loja.h"
#include "apart.h"

int main()
{
    Loja a(100);
    Apart b(200, 2, 4);
    std::cout << a.getPreco() << std::endl; //-> 1500
    std::cout << b.getPreco() << std::endl; //-> 2000
    std::cout << "this is a get as string" << std::endl;
    std::cout << a.getAsString()<< std::endl;
    std::cout << "this is the end of a get as string" << std::endl;
    b.getAsString();
    std::cout << "overloading de operadores" << std::endl;
    std::cout << a << std::endl;            // LOJA 1, 100, 1500, r/c
    //std::cout << b << std::endl;            // AP 2, 200, 2000, 2, 4
}
