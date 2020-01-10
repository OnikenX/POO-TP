#ifndef GLOBAL_H
#define GLOBAL_H

#include "autodromo.hpp"
#include "utils.hpp"
#include "dgv.hpp"

class global
{

public:
    dgv direcao;
    //vetor de autodromos
    std::vector<atd *> autodromos;
    int debuging;

    int addA(int N, int comprimento, std::string nome);

    void mostratodosA();

    int cmdlineprinc();

    int campeonatocmd(std::vector<atd *> campautos);

    //remover o autodromo
    int rmautodromo(std::string nome);

    void listcars();

    int carregaA(std::string filename);

    global(int debug);

    global();
};

#endif //GLOBAL_H
