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

int insere()
{
  printf ( "\n" );
  printf ( "👉 " );
  fflush ( stdout );
  return 0;
}

//comparar comandos
bool cmpcmd(char * longcmd, char * shortcmd, char * compare){
    return  ( (strcmp(compare, longcmd)==0) || (strcmp( compare,  shortcmd)==0 ) );
}

int cmdlineprinc()
{
  char  raw[200];
  char * argv[10];
  int argc = 0 ;
  printf ( "Bem vindo a linha de comandos do gestor do msgdist,\n insira help ou h para pedir ajuda e dicas.\n" );
  insere();
  while ( std::fgets ( raw ,200, stdin ) )
    {
      if (raw[0]!='\n' )
        { 
          argc=0;
          raw[std::strlen(raw) - 1] = '\0'; //trocar o \n por \0 para dizer o limite da cmd
          argv[argc] = std::strtok( raw, " " );

          while (     (argv[++argc] = std::strtok ( NULL," " ))!=NULL  );
          
          
          //for ( int i = 0; i< argc; i++ ) printf ( "\nargv[%d] = %s \n", i, argv[i] );
        
          
          if (cmpcmd((char *)"shutdown",(char *) "s", argv[0]))
            {
              printf ( "\tight imma head out\n" );
              return 0;
            }else  if(cmpcmd((char *)"help",(char *) "h", argv[0])){
              printf ( "    Comandos disponiveis:\n"
                       "help ou h - - - - - - - este ecra\n"
                       "shutdown ou s - - - - - terminar o sistema MSGDIST\n" );
            }else
            //outros comandos
            std::cout << "Comando " << argv[0] <<  "não encontrado.\n";
            }
      insere();
        }
    

  return 0;
}


int main(/*int argc, char ** argv*/){
    
    cmdlineprinc();
    
    return 0;
}
