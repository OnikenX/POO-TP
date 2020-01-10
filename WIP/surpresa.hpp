#ifndef SURPRESA_HPP
#define SURPRESA_HPP

#include "piloto.hpp"

class Surpresa:public Piloto{
    float matar=0.05;
public:
    Surpresa(std::string nome);
};

#endif