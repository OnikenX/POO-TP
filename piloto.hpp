//um piloto é um pequeno robô que simula o comportamento de um piloto real. possui as seguintes caracteristicas

//tem nome, data de nascimento que é constranste

//os nomes sao unicos, na criacao esta propriadade tem de ser verificado como tal e se nao o for deve ser modada para que seja unica


/*
            --------   NOTAS DO JOTA   ---------
classe Piloto

string nome (terá um metudo para garantir que será unico modificando-o automaticamente)

Interage com as ações do carro , por exemplo acelerar , travar ou segue ordens vindas de fora.

EntraNoCarro(id_carro);

SaiDoCarro();

Tipo Crazy Driver 
    ->só começa a corrida no segundo x(entre 1 e 5)
    ->ciclo a cada segundo de perguntar o seu lugar
    ->Se não estiver em 1o ou ultimo , aceler
    ->Se estiver em primeiro,mantém a velocidade.
    ->Se estiver em ultimo ,fica de mau  humor e trava.
    ->Se notar que perdeu lugares desde o segundo anterior(ciclo) acelera 2m/s , a menos que esteja em ultimo
    ->Se o carro ficar sem energia , entra em panico e acende o sinal de emergência.
    ->5% de chance de danificar irremediavelmente o carro,quando acontece o lugar atrás tambem fica com o carro irremediavelmente danificado(fudido)

Piloto Rápido

    ->começa no 1o segundo da corrida
    -> acelera continuamente até ver que a energia restante do carro atingiu metade da capacidade max.A partir deste estado ele só acelera de 3 em 3 segundos
    -> a cada 10s tem uma prob de 10% de sofrer um ataque de panico e caso tenha o ataque ativa o botão de emergência.

Piloto Surpresa

    -> Fazer piloto original
*/

//
#ifndef PILOTO_HPP_INCLUDED
#define PILOTO_HPP_INCLUDED

#pragma once

#include "utils.hpp"
#include "carro.hpp"

//piloto
class Piloto{
    
    //nome do piloto
    std::string nome;

    //data de nascimento/fabricaçao do piloto
    int n_dia, n_mes, n_ano;

    Carro * aconduzir = NULL;

public:
    Piloto(std::string nome, int n_dia, int n_mes, int n_ano);

    //meter no carro e tirar do carro
    int meter ( Carro * ameter );
    int tirar();


    //estafucnao da o nome
    std::string getnome();
    //esta funcao guarda num array de 3 inteiros a data de nacimento do piloto 
    void getnasc(int nasc[3]);


};

#endif // PILOTO_HPP_INCLUDED
