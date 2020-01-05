#include "headers/dgv.hpp"

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
            Piloto *ponteiro = carros[i]->getpiloto();
            if (ponteiro != NULL)
                ponteiro->meter(NULL);
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

int dgv::rmpiloto(std::string nome)
{
    int i = 0;
    for (auto it = pilotos.begin(); it != pilotos.end(); ++it, ++i)
    {
        if (pilotos[i]->getnome() == nome)
        {

            Carro *ponteiro = pilotos[i]->getcarro();
            if (ponteiro != NULL)
                ponteiro->meter(NULL);

            //delete carros[i];
            pilotos.erase(it);
            break;
        }
    }
    return 0;
}

//              gerir pilotos
//criacao de um piloto
int dgv::criarpiloto(std::string nome,std::string tipo)
{

    std::ostringstream nomeaux;
    static int contador;
    int i = 0;
    auto it = pilotos.begin();
    for (; it != pilotos.end(); ++i, ++it)
    {
        if (pilotos[i]->getnome() == nome){
            nomeaux << nome << contador << ' ';
            nome = nomeaux.str();
            contador++;
        }
    }
    if(tipo == "rapido"){
        pilotos.push_back(new Rapido(nome));
        return 0;
    } else if(tipo == "crazy"){
        pilotos.push_back(new Crazy(nome));
        return 0;
    } else if(tipo == "surpresa"){
        pilotos.push_back(new Surpresa(nome));
        return 0;
    } else{
    pilotos.push_back(new Piloto(nome));
    return 0;
    }
}

int dgv::carregarC(std::string filename)
{
    /*
    FILE *f = fopen(filename.c_str(), "r");
    if (f == NULL)
    {
        printf("Erro a abrir ficheiro %s.\n", filename.c_str());
        // erro 5 - erro a abrir o ficheiro
        return 5;
    }
    */
    std::ifstream myfile(filename);
    int erro;
    std::string line, capacidadeInicial, capacidadeMaxima, marca, modeloA, modelo;

    if (myfile) // same as: if (myfile.good())
    {
        while (std::getline(myfile, line)) // same as: while (getline( myfile, line ).good())
        {
            std::istringstream bufi(line);
            std::stringstream oss;

            bufi >> capacidadeInicial;
            // std::stoi( capacidadeInicial ); conversor String(s) to Int(i)
            bufi >> capacidadeMaxima;
            // std::stoi( capacidadeMaxima ); conversor String(s) to Int(i)
            bufi >> marca;
            while (bufi >> modeloA)
            {
                oss << modeloA << " ";
                modelo = oss.str();
            }
            if ((erro = criarcarro(marca, std::stof(capacidadeMaxima), std::stof(capacidadeInicial), 100, modelo)) != 0)
            {
                return erro;
            }
        }
        myfile.close();
    }
    else
        std::cout << "problemas a abrir o ficheiro\n";

    return 0;
};

int dgv::carregarP(std::string filename)
{
    std::ifstream myfile(filename);
    int erro;
    std::string line, tipo, nomepa, nomep;

    if (myfile) // same as: if (myfile.good())
    {
        while (std::getline(myfile, line)) // same as: while (getline( myfile, line ).good())
        {
            std::istringstream bufi(line);
            std::stringstream oss;

            bufi >> tipo;
            while (bufi >> nomepa)
            {
                oss << nomepa << " ";
                nomep = oss.str();
            }
            if ((erro = criarpiloto(nomep,tipo)) != 0)
            {
                return erro;
            }
        }
        myfile.close();
    }
    else
        std::cout << "problemas a abrir o ficheiro\n";

    return 0;
};

void dgv::mostratodosC()
{
    for (int i = 0; i < carros.size(); ++i)
        carros[i]->getasstring();
};

void dgv::mostratodosP()
{
    for (int i = 0; i < pilotos.size(); ++i)
        pilotos[i]->getasstring();
};

void dgv::entranocarro(char idcarro, std::string nome)
{

    int i = 0, j = 0, idexiste = 0, pexiste = 0;

    for (auto it = carros.begin(); it != carros.end(); ++it, ++i)
    {
        if (carros[i]->getid() == idcarro)
        {
            idexiste = 1;
            if (carros[i]->getpiloto() == nullptr)
            {
            
            for (auto it = pilotos.begin(); it != pilotos.end(); ++it, ++j)
            {
                if (pilotos[j]->getnome() == nome)
                {
                    pexiste = 1;
                    if (pilotos[j]->getcarro() != nullptr)
                    {
                        std::cout << "o piloto ja tem um carro" << std::endl;
                    }
                    else{
                    
                    pilotos[j]->meter(carros[i]);
                    carros[i]->meter(pilotos[j]);
                    }
                }
            }
            break;
            }
            else
            {
                std::cout << "o carro ja tem piloto" << std::endl;
            }
            
        }
    }
    if (idexiste == 0)
    {
        std::cout << "o id nao existe\n";
    }
    if (pexiste == 0 &&  carros[i]->getpiloto() == nullptr)
    {
        std::cout << "o piloto nao existe\n";
    }
}

void dgv::saidocarro(char idcarro)
{
    int i = 0, idexiste = 0;
    Piloto *ponteiro = NULL;
    for (auto i = 0; i < carros.size(); ++i)
    {
        if (carros[i]->getid() == idcarro)
        {
            idexiste = 1;
            if ((ponteiro = carros[i]->getpiloto()) != NULL)
            {
                ponteiro->meter(NULL);
                carros[i]->meter(NULL);
            }else{
                std::cout << "este carro nao tem piloto." << std::endl; 
            }
            break;
        }
    }
    if (idexiste == 0)
    {
        std::cout << "o id nao existe\n";
    }
}
