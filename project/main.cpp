#include "./headers/utils.hpp"
#include "./headers/global.hpp"
//comparar comandos
/*bool cmpcmd ( char * longcmd, char * shortcmd, char * compare )
{
    return ( ( strcmp ( compare, longcmd ) ==0 ) || ( strcmp ( compare,  shortcmd ) ==0 ) );
}
*/

int main ( int argc, char ** argv )
{
    int debug = 0;
    std::string nome;
    if(argc > 1){
        debug = 1;
        std::string debuging = argv[1];
        if(debuging =="-d"){
            debug = 1;
        }
        for(int i = 0; i < argc; ++i)
        printf("%s\n", argv[i]);
    }

    global a(debug);

    if(debug == 1){
        a.direcao.carregarP("pilotos");
            a.direcao.carregarC("popos");
            a.carregaA("autodromos");
            //a.listcars();
            nome = "christian toto ";
            //std::cout << nome << std::endl;
            a.direcao.entranocarro('a', nome);
            nome = "jesus maria ";
            //std::cout << nome << std::endl;
            a.direcao.entranocarro('b',nome);
    }

    a.cmdlineprinc();
    //dgv a;
    //std::string carrosfile = "popos";
    //a.carregarC(carrosfile);
    //a.mostratodosC();
}
