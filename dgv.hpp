
#ifndef DVG_HPP
#define DVG_HPP

#include "utils.hpp"
#include "carro.hpp"
#include "piloto.hpp"
/*
        -------------- NOTAS DO JOTA ----------
DVG

É  a  entidade  que  tem  o  registo  de  todos  os  carros  e  pilotos  e  a  responsável  direta  pela  existência  destes objetos. Será esta a entidade  alvo de backup  caso o utilizador  assim o determine  (ver na seção de comandos).

Tem a informação de onde esta o carro então faz a conecção dos carros com autodromo por exemplo
*/

class dgv
{
    char idusavel[26];

public:

    std::vector<Carro *> carros;
    std::vector<Piloto *> pilotos;

    dgv();

    //                      gerir carros
    //  criacao de um carro
    int criarcarro(std::string marca, float max_energia, float start_energia, int max_speed, std::string modelo);

    int rmcarro(char idcarro);

    //gerir pilotos
    int criarpiloto(std::string nome, int n_dia, int n_mes, int n_ano);

    //          carregamento de files
    //carrega carros
    int carregarC(std::string filename);
    //carrega pilotos
    int carregarP(std::string filename);

    //              display everything
    //mostrar todos os carros
    void mostratodosC();

    //          save to files
    //
};

#endif //DVG_HPP
