#ifndef APART_H
#define APART_H




class Apart : public Imovel
{
    int quantos;

public:
    Apart(int area, int andar, int quantos);

    virtual std::string stringGetAsString() const;

};

#endif //APART_H