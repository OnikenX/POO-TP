
#include <iostream>
#include <sstream>
#include <fstream>
#include "global.hpp"

int global::addA(int N, int comprimento, std::string nome)
{
    if (N < 0 || comprimento < 0)
    {
        std::cout << "nao pode haver valores negativos para o autodromo" << std::endl;
        return 1;
    }
    int i = 0;
    static int count = 1;
    std::ostringstream nomeaux;
    for (auto it = autodromos.begin(); it != autodromos.end(); ++it, ++i)
    {
        if (autodromos[i]->getnome() == nome)
        {
            nomeaux << nome << count;
            nome = nomeaux.str();
            count++;
        }
    }

    autodromos.push_back(new atd(N, comprimento, nome));
    return 0;
};

void global::mostratodosA()
{
    for (int i = 0; i < autodromos.size(); ++i)
    {
        autodromos[i]->getasstring();
    }
};

int global::cmdlineprinc()
{
/*
        --------  NOTAS -------------
    
    Comandos

    Modo 1 –Define  o  que existe:  carros,  autódromos,    condutores,  com  todas  as  suas  características. Também    deve ser possível  adicionar eretirar  quaisquer  destes      elementos,  assim  como fazer entrar  e sair  pilotos  em   carros. Será  possível  fazer  ainda,  backup/recuperação    para/da  memória  da  direção  geral de viação.

    Modo 2 –Simulação de um campeonato: o simulador  permite    escolher os autódromos e a sua ordem no campeonato. Todos os  carros que tenham piloto participam  em todas corridas   enquanto  estiverem em condições de participar.Deve ser   mantida  uma pontuação para cada condutor.


    
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

            if ( cmpcmd ( ( char * ) "shutdown", ( char * ) "s", cmd[0] ) ) {
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
    int i, f;

    std::string cmd;

    std::vector<atd*> campautos;

    std::string str, letraTipo, tipo, nomep, capacidadeInicial, capacidadeMaxima, marca, modelo, numeroC, comp, nomeA, nomepa, modeloA, nomefich, letraCarro, copia,lixo,autocamp;

    for (;;)
    {
        std::cout << "comando> ";
        fflush(stdout);
        std::getline(std::cin, cmd);

        std::istringstream bufi(cmd);
        std::ostringstream oss;
        std::ostringstream Aindex;

        while (bufi >> str)
        {
            copia = str;
            if (copia == "carregaP")
            {
                bufi >> nomefich;
                direcao.carregarP(nomefich);
            }
            else
                // <NomeFicheiro> vai buscar pilotos ao ficheiro ("tipo nome")
                if (copia == "carregaC")
            {
                bufi >> nomefich;
                direcao.carregarC(nomefich);
            }
            else
                // <NomeFicheiro> vai buscar os carros ao ficheiro("capacidadeInicial capacidadeMaxima marca modelo")
                if (copia == "carregaA")
            {
                bufi >> nomefich;
                carregaA(nomefich);
            }
            else
                // <NomeFicheiro> vai buscar os autodromos ao ficheiro("N comprimento nome")
                if (copia == "cria")
            {
                // <letraTipo>(p;c;a) <dados do objeto>(se c -> capacidadeInicial ;capacidadeMaxima ;marca ;modelo)
                bufi >> letraTipo;
                if (letraTipo == "p")
                {
                    bufi >> tipo;
                    while (bufi >> nomepa)
                    {
                        oss << nomepa << " ";
                        
                    }
                    nomep = oss.str();
                    direcao.criarpiloto(nomep);
                    //std::cout<< tipo << endl << nomep;
                }
                else if (letraTipo == "c")
                {
                    bufi >> capacidadeInicial;
                    // std::stoi( capacidadeInicial ); conversor String(s) to Int(i)
                    bufi >> capacidadeMaxima;
                    // std::stoi( capacidadeMaxima ); conversor String(s) to Int(i)
                    bufi >> marca;
                    while (bufi >> modeloA)
                    {
                        oss << modeloA << " ";
                        
                    }
                    modelo = oss.str();
                    direcao.criarcarro(marca, std::stof(capacidadeMaxima), std::stof(capacidadeInicial), 100, modelo);
                }else

                    if (letraTipo == "a")
                    {
                        bufi >> numeroC; // numero de carros
                        // std::stoi( numeroC ); conversor String(s) to Int(i)
                        bufi >> comp;
                        // std::stoi( comp ); conversor String(s) to Int(i)
                        bufi >> nomeA;

                        addA(std::stoi(numeroC), std::stoi(comp), nomeA);

                        //std::cout << numeroC << endl << comp << endl << nomeA;
                    }
                     //std::cout << capacidadeInicial << endl << capacidadeMaxima << endl << marca << endl << modelo;
            }
            else if (copia == "apaga")
            {
                bufi >> letraTipo;
                if (letraTipo == "p")
                {
                    while (bufi >> nomepa)
                    {
                        oss << nomepa << " ";
                        
                    }
                    nomep = oss.str();
                    direcao.rmpiloto(nomep);
                }
                if (letraTipo == "c")
                {
                    bufi >> letraCarro;

                    direcao.rmcarro(letraCarro[0]);
                }
                if (letraTipo == "a")
                {
                    bufi >> nomeA;
                    rmautodromo(nomeA);
                }
            }
            else
                // <letraTipo> <identificador> (se c a letra dele ; se p ou a o nome)
                if (copia == "entranocarro")
            {
                bufi >> letraCarro;
                while (bufi >> nomepa)
                {
                    oss << nomepa << " ";
                    
                }
                    nomep = oss.str();
                    direcao.entranocarro(letraCarro[0], nomep);
            }
            else
                // <letraCarro> <nomePiloto>
                if (copia == "saidocarro")
            {
                bufi >> letraCarro;
                direcao.saidocarro(letraCarro[0]);                
            }
            else
                // <letraCarro>
                if (copia == "lista")
            {
                std::cout << std::endl;
                if (direcao.carros.size() == 0)
                    std::cout << "Não existem carros." << std::endl;
                else
                {
                    std::cout << "\tCARROS:" << std::endl;
                    direcao.mostratodosC();
                }
                std::cout << std::endl;
                if (direcao.pilotos.size() == 0)
                    std::cout << "Não existem pilotos." << std::endl;
                else
                {
                    std::cout << "\tPILOTOS:" << std::endl;
                    direcao.mostratodosP();
                }
                std::cout << std::endl;
                if (autodromos.size() == 0)
                    std::cout << "Não existem autodromos." << std::endl;
                else
                {
                    std::cout << "\tAUTODROMOS:" << std::endl;
                    mostratodosA();
                }
                std::cout << std::endl;
            }
            else
                // - Mostra no ecrã a informação relativa aos carros, aos pilotos e aos autódromos, bem
                // como quem está em que carro e mais o que for relevante saber acerca destas entidades.
                if (copia == "campeonato")
            {
                f = 0;
                while(bufi >>  autocamp){
                    ++f;
                    i=0;
                    for (auto it = autodromos.begin();it != autodromos.end(); ++it, ++i)
                    {
                        if (autodromos[i]->getnome() == autocamp)
                        {
                            campautos.push_back(autodromos[i]);
                        }
                    }
                    

                }
                if(f == campautos.size)
                    campeonatocmd(campautos);
            }
            else
                //|comando para entrar no modo 2| cmdCamp(bufi,str);
                if (copia == "sair")
            {
                return 0;
            }
            else{
                std::cout << "\tO comando não existe" << std::endl;
                while (bufi >> lixo){}
            }
        }
    }
    return 0;
};

int global::carregaA(std::string filename){
    std::ifstream myfile(filename);
    int erro;
    std::string line,numeroC,comp,nomeA;
    std::stringstream oss;
    if (myfile) // same as: if (myfile.good())
    {
        while (std::getline(myfile, line)) // same as: while (getline( myfile, line ).good())
        {
            std::istringstream bufi(line);

            bufi >> numeroC; // numero de carros
                        // std::stoi( numeroC ); conversor String(s) to Int(i)
            bufi >> comp;
                        // std::stoi( comp ); conversor String(s) to Int(i)
            bufi >> nomeA;
            if ((erro = addA(std::stoi(numeroC), std::stoi(comp), nomeA)) != 0)
            {
                return erro;
            }
        }
        myfile.close();
    }
    else
        std::cout << "insira o nome do file\n";

    return 0;
};

int global::rmautodromo(std::string nome){
        int i = 0;
    for (auto it = autodromos.begin(); it != autodromos.end(); ++it, ++i)
    {
        if (autodromos[i]->getnome() == nome)
        {
            autodromos.erase(it);
            break;

        }
    }
    return 0;
};

int global::campeonatocmd(std::vector<atd*> Aindex){
    std::vector<atd*> autodromoscamp;
    for(int i = 0;i < Aindex.size();i++){
        std::cout << Aindex[i]->getnome; //debug
    }
    return 0;
};

global::global(int debug){
        debuging = debug;
};