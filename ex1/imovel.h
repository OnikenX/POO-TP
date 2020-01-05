#ifndef IMOVEL_H
#define IMOVEL_H

#include <string>
#include <sstream>

class Imovel
{
    int area, andar, preco, codigo;
    static int conta;
public:
    int getArea();
    int getAndar();
    int getPreco();
    int getCodigo();
    int setAndar(int andar);
    int setPreco(int preco);
    int setCodigo(int codigo);
    virtual std::string getAsString() const;

    virtual ~Imovel(){};
};

#endif //IMOVEL_H