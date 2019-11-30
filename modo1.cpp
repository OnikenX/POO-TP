#include "utils.hpp"
#include "global.hpp"
//comparar comandos
bool cmpcmd ( char * longcmd, char * shortcmd, char * compare )
{
    return ( ( strcmp ( compare, longcmd ) ==0 ) || ( strcmp ( compare,  shortcmd ) ==0 ) );
}




int main ( int argc, char ** argv )
{
    global a;
    cmdlineprinc(a);
    //dgv a;
    //std::string carrosfile = "popos";
    //a.carregarC(carrosfile);
    //a.mostratodosC();

}
