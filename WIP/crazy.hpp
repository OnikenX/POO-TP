/*
Tipo Crazy Driver 
    ->só começa a corrida no segundo x(entre 1 e 5)
    ->ciclo a cada segundo de perguntar o seu lugar
    ->Se não estiver em 1o ou ultimo , aceler
    ->Se estiver em primeiro,mantém a velocidade.
    ->Se estiver em ultimo ,fica de mau  humor e trava.
    ->Se notar que perdeu lugares desde o segundo anterior(ciclo) acelera 2m/s , a menos que esteja em ultimo
    ->Se o carro ficar sem energia , entra em panico e acende o sinal de emergência.
    ->5% de chance de danificar irremediavelmente o carro,quando acontece o lugar atrás tambem fica com o carro irremediavelmente danificado(fudido)
*/
#ifndef CRAZY_HPP
#define CRAZY_HPP

#include "piloto.hpp"

class Crazy:public Piloto{
    float estragar;
    
public:
    Crazy(std::string nome);
};

#endif