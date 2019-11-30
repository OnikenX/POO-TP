
#ifndef GLOBAL_H
#define GLOBAL_H

#include <vector>
#include "dgv.hpp"
#include "carro.hpp"
#include "piloto.hpp"
#include "autodromo.hpp"

class global
{
public:
    dgv direcao;
    //vetor de autodromos
    vector<atd*> autodromos;
    
    carregaA(std::string filename);
};

#endif //GLOBAL_H
