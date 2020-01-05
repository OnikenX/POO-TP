#include "./headers/autodromo.hpp"

atd::atd( int N, int comprimento, std::string nome){

    this->nome = nome;
    this->max_cars = N;
    this->comprimento = comprimento;

}


std::string atd::getnome(){
    return nome;
}

int atd::getN(){
    return max_cars;
}

int atd::getcomprimento(){
    return comprimento;
}

void atd::getasstring(){

    std::cout << "O autodromo " << nome << " tem a capacidade maxima de " << max_cars << "carros e uma pista com comprimento de " <<comprimento << "." << std::endl;

};

/*
void atd::limpaCarros(){

    int i = 0;
    for (auto it = car_pertencentes.begin(); it != car_pertencentes.end(); ++it, ++i){
        car_pertencentes[i]=NULL;
    }

}
*/
