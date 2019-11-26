
#ifndef DVG_HPP
#define DVG_HPP

#include "utils.hpp"
#include "carro.hpp"
/*
        -------------- NOTAS DO JOTA ----------
DVG

É  a  entidade  que  tem  o  registo  de  todos  os  carros  e  pilotos  e  a  responsável  direta  pela  existência  destes objetos. Será esta a entidade  alvo de backup  caso o utilizador  assim o determine  (ver na seção de comandos).

Tem a informação de onde esta o carro então faz a conecção dos carros com autodromo por exemplo
*/

class dgv
{
    char idusavel[26];
    std::vector<Carro*> carros;
    std::vector<Piloto*> pilotos;
public:
    dgv();
    
    //                      gerir carros
    //  criacao de um carro
    int criarcarro ( std::string marca, char id, unsigned int eneria, unsigned int max_energia,unsigned int start_energia, std::string modelo ="modelo base" );
    
    int rmcarro(char idcarro);
    
    //gerir pilotos
    int criarpiloto (std::string nome,  int n_dia, int n_mes, int n_ano)
    

};

#endif //DVG_HPP
