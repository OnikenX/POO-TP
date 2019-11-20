//um piloto é um pequeno robô que simula o comportamento de um piloto real. possui as seguintes caracteristicas

//tem nome, data de nascimento que é constranste

//os nomes sao unicos, na criacao esta propriadade tem de ser verificado como tal e se nao o for deve ser modada para que seja unica

//
#ifndef PILOTO_HPP_INCLUDED
#define PILOTO_HPP_INCLUDED

#pragma once

#include <string>
#include "carro.hpp"

//piloto
class plt {
    //nome do piloto
    const std::string nome;

    //data de nascimento/fabricaçao do piloto
    const int n_dia, n_mes, n_ano;

    crr * aconduzir = NULL;

private:
    plt ( std::string nome, int n_dia, int n_mes, int n_ano );

    //meter no carro e tirar do carro
    int meter ( crr * ameter );
    int tirar();

};

#endif // PILOTO_HPP_INCLUDED
