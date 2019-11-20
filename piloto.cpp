 
#include "piloto.hpp"


plt::plt(std::string nome, int n_dia, int n_mes, int n_ano){
    //verificar se o nome é unico
    this->nome = nome;
    
    //verificia a data
        // verficar data de aniversario
    if (piloto.Dnas > 28 && (piloto.Mnas == (2))) {
        printf("Erro: Data de nascimento impossivel.\n");
        return 2;
    }
    if (piloto.Dnas > 31 && (piloto.Mnas == 4 || piloto.Mnas == 6 ||
            piloto.Mnas == 9 || piloto.Mnas == 11)) {

        printf("Erro: Data de nascimento impossivel.\n");
        return 2;
    }
    if (piloto.Dnas > 30) {
        printf("Erro: Data de nascimento impossivel.\n");
        return 2;
    }
    if (piloto.Mnas > 12) {
        printf("Erro: Data de nascimento impossivel.\n");
        return 2;
    }

    // verficar caracteristicas do piloto
    if (piloto.exp < 0.0) {
        printf("Erro: Experiencia menor que 0\n");
        return 3;
}
