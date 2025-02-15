#pragma once
#include "Leilao.hpp"
#include <limits.h>


class Avaliador
{
private:
    float maiorLance=INT_MIN;
    float menorLance=INT_MAX;
public:
    void avalia(Leilao);
    float getMaiorLance() const;
    float getMenorLance() const;
};

