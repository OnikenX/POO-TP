//cosiderar adicionar outras entidades

//nao é obrigatorio haver uma relação entidade - class
/*
#include <iostream>
#include "antodromo.hpp"
#include "carro.hpp"
#include "corrida.hpp"
#include "garagem.hpp"
#include "piloto.hpp"
#include "pista.hpp"
*/

#include "utils.hpp"

int insere() {
    printf ( "\n" );
    printf ( "👉 " );
    fflush ( stdout );
    return 0;
}

//comparar comandos
bool cmpcmd ( char * longcmd, char * shortcmd, char * compare ) {
    return ( ( strcmp ( compare, longcmd ) ==0 ) || ( strcmp ( compare,  shortcmd ) ==0 ) );
}

int cmdlineprinc() {
    char  raw[200];
    char * cmd[10];
    int ncmd = 0 ;
    std::cout << "Bem vindo a linha de comandos do gestor do msgdist,\n insira help ou h para pedir ajuda e dicas.\n";
    insere();
    while ( std::fgets ( raw,200, stdin ) ) {
        if ( raw[0]!='\n' ) {
            ncmd=0;
            raw[std::strlen ( raw ) - 1] = '\0'; //trocar o \n por \0 para dizer o limite da cmd
            cmd[ncmd] = std::strtok ( raw, " " );
            while ( ( cmd[++ncmd] = std::strtok ( NULL," " ) ) !=NULL );


            //for ( int i = 0; i< ncmd; i++ ) printf ( "\nargv[%d] = %s \n", i, argv[i] );
            std::cout << cmd[0];

            /*if ( cmpcmd ( ( char * ) "shutdown", ( char * ) "s", cmd[0] ) ) {
                std::cout << "\tight imma head out\n";
                return 0;
            }
            if ( cmpcmd ( ( char * ) "help", ( char * ) "h", cmd[0] ) ) {
                std::cout << "    Comandos disponiveis:\n" <<
                         "help ou h - - - - - - - este ecra\n" <<
                         "shutdown ou s - - - - - terminar o sistema MSGDIST\n";
            } 
            if (cmpcmd ( ( char * ) "carro", ( char * ) "c", cmd[0] )) {
                //chamar a criação do carro;
            }
            if (cmpcmd ( ( char * ) "piloto", ( char * ) "p", cmd[0] )) {
                //chamar a criação do carro;
            }
            if (cmpcmd ( ( char * ) "autodromo", ( char * ) "a", cmd[0] )) {
                //chamar a criação do carro;
            }
            else
                //outros comandos
                std::cout << "Comando " << argv[0] <<  "não encontrado.\n";
                */
        }
        insere();
    }


    return 0;
}


int main ( /*int ncmd, char ** argv*/ ) {

    std::vector<Carro> carros;
    std::vector<plt> pilotos;
    
    cmdlineprinc();
    
    return 0;
}
