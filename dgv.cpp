
#include <string>
#include <vector>
#include <iterator>
#include "dgv.hpp"
#include "carro.hpp"
#include "piloto.hpp"

dgv::dgv(){
    for(char i = 'a'; i<= 'z'; ++i)
        idusavel[i-'a']=i;
}

int dgv::criarcarro ( std::string marca, char id, unsigned int eneria, unsigned int max_energia,unsigned int start_energia, std::string modelo )
{
    //faz o id certo
    
    char idforcar=0;
    for (char i = 'a'; i<= 'z'; ++i)
        if(idusavel[i-'a']!=0){
            idforcar = idusavel[i-'a'];
            idusavel[i-'a']=0;
            break;
        }
    if(idforcar == 0)
        idforcar = '?';
    carros.push_back ( new Carro ( marca,idforcar,eneria, max_energia,start_energia,  modelo ));
    return 0;


};

int dgv::rmcarro(char idcarro){
    
    int i = 0;
    char idfromcar;
    for(auto it = carros.begin(); it != carros.end(); ++it, ++i){
        if(carros[i]->getid() == idcarro){
            //delete carros[i];
            idfromcar = carros[i]->getid();
            carros.erase(it);
            break;
        }
    }
    
    if(('a' <= idfromcar) && (idfromcar <= 'z'))
        idusavel[idfromcar - 'a'] = idfromcar;
}


