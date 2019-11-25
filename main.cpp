#include "utils.hpp"

//comparar comandos
bool cmpcmd ( char * longcmd, char * shortcmd, char * compare )
{
    return ( ( strcmp ( compare, longcmd ) ==0 ) || ( strcmp ( compare,  shortcmd ) ==0 ) );
}




int main ( int ncmd, char ** argv )
{
    cmdlineprinc();
    return 0;
}
