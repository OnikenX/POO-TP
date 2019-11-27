#ifndef ANTODROMO_HPP
#define ANTODROMO_HPP
#pragma once

#include "utils.hpp"
#include "carro.hpp"
#include "piloto.hpp"
//Antodromo
class atd{
    //o autodromo tem uma pista e uma garagem contida nele que nao existe em mais nenhum contexto sem ele

    //este tem um nome que serve como identificacao
    std::string nome;

    //comprimento da pista
    int comprimento;

    //array de carros
    Carro * car_pertencentes;

    //


public:
    //se acontecer algum dessastre ao autodromo, todos os carros que lhe pertencem iram ficar com um dano irremediavel
    
    
}
#endif //ANTODROMO_HPP
