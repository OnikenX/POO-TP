#include "utils.hpp"

using namespace std;
 /*
int insere()
{
    printf ( "\n" );
    printf ( "👉 " );
    fflush ( stdout );
    return 0;
}
*/

int cmdlineprinc(global glbl)
{
/*
       --------  NOTAS -------------
    
    Comandos

Modo 1 –Define  o  que existe:  carros,  autódromos,  condutores,  com  todas  as  suas  características. Também  deve ser possível  adicionar eretirar  quaisquer  destes  elementos,  assim  como fazer entrar  e sair  pilotos  em  carros. Será  possível  fazer  ainda,  backup/recuperação  para/da  memória  da  direção  geral de viação.

Modo 2 –Simulação de um campeonato: o simulador  permite  escolher os autódromos e a sua ordem no campeonato. Todos os carros que tenham piloto participam  em todas corridas enquanto  estiverem em condições de participar.Deve ser mantida  uma pontuação para cada condutor.
*/

/*
    char  raw[200];
    char * cmd[10];
    int ncmd = 0 ;
    std::cout << "Bem vindo a linha de comandos do VROOM,\n insira help ou h para pedir ajuda e dicas.\n";
    insere();
    while ( std::fgets ( raw,200, stdin ) ) {
        if ( raw[0]!='\n' ) {
            ncmd=0;
            raw[std::strlen ( raw ) - 1] = '\0'; //trocar o \n por \0 para dizer o limite da cmd
            cmd[ncmd] = std::strtok ( raw, " " );
            while ( ( cmd[++ncmd] = std::strtok ( NULL," " ) ) !=NULL );


            //for ( int i = 0; i< ncmd; i++ ) printf ( "\nargv[%d] = %s \n", i, argv[i] );
            //std::cout << cmd[0];

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
                
        }
        insere();
    }
*/

    string cmd,conheco;
    
    std::cout << "comando> ";
    fflush(stdout);
    getline(std::cin,cmd);
    
    
    std::istringstream bufi(cmd);

    std::ostringstream oss;
    
    std::string str,letraTipo,tipo,nomep,capacidadeInicial,capacidadeMaxima,marca,modelo,numeroC,comp,nomeA,nomepa,modeloA,nomefich,letraCarro;
    string copia;
    while(bufi>>str){
        copia=str;
        if(copia=="carregaP"){
            bufi>>nomefich;
            glbl.direcao.carregarP(nomefich);
        }
            // <NomeFicheiro> vai buscar pilotos ao ficheiro ("tipo nome")
        if(copia=="carregaC"){
            bufi>>nomefich;
            glbl.direcao.carregarC(nomefich);
        }
            // <NomeFicheiro> vai buscar os carros ao ficheiro("capacidadeInicial capacidadeMaxima marca modelo")
        if(copia=="carregaA"){
            bufi>>nomefich;
            glbl.carregarA(nomefich);
        }
            // <NomeFicheiro> vai buscar os autodromos ao ficheiro("N comprimento nome")
        if(copia=="cria"){
            // <letraTipo>(p;c;a) <dados do objeto>(se c -> capacidadeInicial ;capacidadeMaxima ;marca ;modelo)
            bufi>>letraTipo;
            if(letraTipo=="p"){
                bufi>>tipo;
                while(bufi>>nomepa){
                oss << nomepa << " ";
                nomep = oss.str();
                }
                std::cout<< tipo << endl << nomep; 
            }
            if(letraTipo=="c"){
                bufi>>capacidadeInicial;
                // std::stoi( capacidadeInicial ); conversor String(s) to Int(i)
                bufi>>capacidadeMaxima;
                // std::stoi( capacidadeMaxima ); conversor String(s) to Int(i)
                bufi>>marca;
                while(bufi>>modeloA){
                oss << modeloA << " ";
                modelo = oss.str();
                }
            }
                std::cout << capacidadeInicial << endl << capacidadeMaxima << endl << marca << endl << modelo;
        }

            if(letraTipo=="a"){
                bufi>>numeroC;// numero de carros
                // std::stoi( numeroC ); conversor String(s) to Int(i)
                bufi>>comp;
                // std::stoi( comp ); conversor String(s) to Int(i)
                bufi>>nomeA;

                //std::cout << numeroC << endl << comp << endl << nomeA;
            }
            if(copia=="apaga"){
                bufi>>letraTipo;
                if(letraTipo=="p"){
                    while(bufi>>nomepa){
                        oss << nomepa << " ";
                        nomep = oss.str();
                    }
                }
                if(letraTipo=="c"){
                    bufi>>letraCarro;
                }
                if(letraTipo=="a"){
                    bufi>>nomeA;
                }
            }
            // <letraTipo> <identificador> (se c a letra dele ; se p ou a o nome)
            if(copia=="entranocarro"){
                bufi>>letraCarro;
                while(bufi>>nomepa){
                        oss << nomepa << " ";
                        nomep = oss.str();
                    }
            }
            // <letraCarro> <nomePiloto>
            if(copia=="saidocarro"){
                bufi>>letraCarro;
            }
            // <letraCarro>
            if(copia=="lista"){}
            // - Mostra no ecrã a informação relativa aos carros, aos pilotos e aos autódromos, bem
            // como quem está em que carro e mais o que for relevante saber acerca destas entidades.
            if(copia=="campeonato"){}
            //|comando para entrar no modo 2| cmdCamp(bufi,str);
    }
    return 0;    
}
        
    
    


