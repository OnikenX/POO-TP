#include "utils.hpp"


Piloto::Piloto ( std::string nome, int n_dia, int n_mes, int n_ano )
{
    //verificar se o nome é unico
    this->nome = nome;
    this->n_dia = n_dia;
    this->n_mes = n_mes;
    this->n_ano = n_ano;
}

int Piloto::meter(Carro * ameter){
    if(aconduzir != NULL)
        return 1;
    if(ameter->getspeed() != 0)
        return 2;
    
    aconduzir = ameter;
    return 0;
}
    
int Piloto::tirar(){
   if(aconduzir != NULL)
        return 2;
    
    aconduzir = NULL;
    return 0;
}
