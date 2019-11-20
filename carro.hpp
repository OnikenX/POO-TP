#ifndef CARRO_HPP_INCLUDED
#define CARRO_HPP_INCLUDED

//pode estar parado ou em movimento, quando neste deve ter uma volcidade(m/s)

/*
em movimento o carro pode:
    manter volcidade
    acelarar
        primir o acelerador acelera 1 m/s²
    decelarar/travar
        primir o travao trava 1m/s²
*/

//os carros tem uma volcidade maxima que é um dos parametros de contrucao de um carro , essa volcidade nunca deve ser ultrapassada pelo carro e nunca serà inferior a 0

//mover consome 0.1mah/s por cada m/s(por exemplo, se estiver a andar a 80m/s ele consome 8mAh/s)
//se tiver sem bateria o carra vai parando como se estivese a travar(acelera -1m/s²), se estiver a travar ao mesmo tempo ele trava a 2m/s²

//tem um sinal de emergencia que pode ser ligado a qualquer volcidade(provavel que nao deve conseguir quando não tem bateria)

//o carro só anda com 1 piloto, este pode sair só quando o carro está parado

//o carro tem de ter uma noçao de tempo para fazer as operações descritas

/*
um carro pode ficar irremediavelmente danificado, com isto ele fica imediatamente com volcidade 0 e só aceitará estes comandos:
    tirar de um autodromo
    continuar a existir
    remover a sua existencia
    se o carro estiver com dano irreparavel o piloto, se estiver la dentro, perde a vida
*/

//um carro danificado nao aceita condutor
#include <string>

//carro
class Carro{

    //possui marca(obigatorio) e modelo(def: "modelo base")
    std::string marca, modelo ="base";

    //a identificação dos carros é feita com letras(de a a z) automaticamente;???aqueles que estiverem a mais ficam com a letra '?' ????
    char id;

    //os carros são eletricos (enegia quantificada em mAh), deve estar parado para carregar, o carregamento é n e este tem de ser maior que zero; a capacidade maxima, que não é ultrapassada quando está a ser carregado, e a capacidade inicial são caracteristicas de quando este é fabricado.
    unsigned int energia, max_energia, start_energia, speed = 0, maxspeed;
    
    //dano do carro
        //0 - sem dano
        //
    int dano;

public:
    Carro(std::string marc, unsigned int ide, std::string mod = "base");

    ~Carro();
    

    Carro();


    Carro(std::string marc, std::string mod = "base", char ide, unsigned int ener, unsigned int maxen,unsigned int start_energia);

    
    int travar();
    
    int acelarar();

    

};

#endif // CARRO_HPP_INCLUDED
