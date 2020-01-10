/*Piloto Rápido

    ->começa no 1o segundo da corrida
    -> acelera continuamente até ver que a energia restante do carro atingiu metade da capacidade max.A partir deste estado ele só acelera de 3 em 3 segundos
    -> a cada 10s tem uma prob de 10% de sofrer um ataque de panico e caso tenha o ataque ativa o botão de emergência.
*/
#ifndef RAPIDO_HPP
#define RAPIDO_HPP

#include "piloto.hpp"

class Rapido:public Piloto{
    float panico=0.10;
public:
    Rapido(std::string nome);
};

#endif