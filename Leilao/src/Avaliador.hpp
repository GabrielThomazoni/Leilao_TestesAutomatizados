#pragma once
#include "Leilao.hpp"


class Avaliador
{
private:
    float maiorLance=0;
public:
    void avalia(Leilao);
    float getMaiorLance() const;
};

