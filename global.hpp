#ifndef GLOBAL_H
#define GLOBAL_H


#include <vector>
#include "dgv.hpp"
#include "autodromo.hpp"

class global
{

public:
    dgv direcao;
    //vetor de autodromos
    std::vector<atd*> autodromos;

    

    int addA(int N, int comprimento, std::string nome);

    void mostratodosA();

    int cmdlineprinc();

    int campeonatocmd(std::string Aindex);

    //remover o autodromo
    int rmautodromo(std::string nome);
    

    
    int carregaA(std::string filename);

};

#endif //GLOBAL_H
