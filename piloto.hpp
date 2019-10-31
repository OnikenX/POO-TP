//um piloto é um pequeno robô que simula o comportamento de um piloto real. possui as seguintes caracteristicas

//tem nome, data de nascimento que é constranste

//os nomes sao unicos, na criacao esta propriadade tem de ser verificado como tal e se nao o for deve ser modada para que seja unica

//
#include <string>

class Piloto {
    //nome do piloto
    const std::string nome;

    //data de nascimento/fabricaçao do piloto
    const int n_dia, n_mes, n_ano;

    Carro aconduzir;
}