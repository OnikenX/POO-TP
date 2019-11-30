
#include <string>
#include <vector>
#include <iterator>
#include "dgv.hpp"
#include "carro.hpp"
#include "piloto.hpp"

dgv::dgv()
{
    for (char i = 'a'; i <= 'z'; ++i)
        idusavel[i - 'a'] = i;
}

//                      gerir carros
//  criacao de um carro
int dgv::criarcarro(std::string marca, float max_energia, float start_energia, int max_speed, std::string modelo)
{
    //faz o id certo

    char idforcar = 0;
    for (char i = 'a'; i <= 'z'; ++i)
        if (idusavel[i - 'a'] != 0)
        {
            idforcar = idusavel[i - 'a'];
            idusavel[i - 'a'] = 0;
            break;
        }
    if (idforcar == 0)
        idforcar = '?';
    carros.push_back(new Carro(marca, idforcar, max_energia, start_energia, max_speed, modelo));
    return 0;
};

int dgv::rmcarro(char idcarro)
{

    int i = 0;
    char idfromcar;
    for (auto it = carros.begin(); it != carros.end(); ++it, ++i)
    {
        if (carros[i]->getid() == idcarro)
        {
            //delete carros[i];
            idfromcar = carros[i]->getid();
            carros.erase(it);
            break;
        }
    }

    if (('a' <= idfromcar) && (idfromcar <= 'z'))
        idusavel[idfromcar - 'a'] = idfromcar;
    return 0;
}

//              gerir pilotos
//criacao de um piloto
int dgv::criarpiloto(std::string nome, int n_dia, int n_mes, int n_ano)
{

    int i = 0;
    auto it = pilotos.begin();
    for (; it != pilotos.end(); ++i, ++it)
    {
        if (pilotos[i]->getnome() == nome)
            nome += "1";
    }

    pilotos.push_back(new Piloto(nome, n_dia, n_mes, n_ano));

    return 0;
}

int dgv::carregarC(std::string filename)
{

    FILE *f = fopen(filename.c_str(), "r");
    if (f == NULL)
    {
        printf("Erro a abrir ficheiro %s.\n", filename.c_str());
        // erro 5 - erro a abrir o ficheiro
        return 5;
    }
    int erro;

    char marca_c[100], modelo_c[100];
    std::string marca, modelo;
    float max_energia, start_energia;
    int max_speed;
    while (fscanf(f, "%f %f %s %99[^\n]", marca_c, &start_energia, &max_energia, &max_speed, modelo_c) == 5)
    {
        //printf("%s %f %f %d %s",marca_c, start_energia, max_energia, max_speed, modelo_c);
        modelo = modelo_c;
        marca = marca_c;

        if ((erro = criarcarro(marca, max_energia, start_energia, max_speed, modelo)) != 0)
            return erro;
    }
    fclose(f);

    return 0;
};

int dgv::carregarP(std::string filename)
{
FILE *f = fopen(filename.c_str(), "r");
    if (f == NULL)
    {
        printf("Erro a abrir ficheiro %s.\n", filename.c_str());
        // erro 5 - erro a abrir o ficheiro
        return 5;
    }
    int erro;

    char tipo_p[20], nome_p[100];
    std::string tipo, nome;
    while (fscanf(f, "%s %99[^\n]", tipo_p,nome_p) == 2)
    {
        //printf("%s %s",tipo_p,nome_p);
        tipo = tipo_p;
        nome = nome_p;

        if ((erro = criarpiloto(tipo,nome)) != 0)
            return erro;
    }
    fclose(f);

    return 0;
};

void dgv::mostratodosC(){
    for (int i=0; i<carros.size() ; ++i)
        carros[i]->getasstring();
};
