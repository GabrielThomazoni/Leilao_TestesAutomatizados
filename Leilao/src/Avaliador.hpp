#pragma once
#include "Leilao.hpp"
#include <limits.h>
#include <algorithm>


class Avaliador
{
private:
    float maiorLance=INT_MIN;
    float menorLance=INT_MAX;
    std::vector<Lance> maior3Lances;

    static bool ordenaLances(const Lance&, const Lance&);

public:
    void avalia(Leilao);
    float getMaiorLance() const;
    float getMenorLance() const;
    std::vector<Lance> getMaior3Lances() const;
};

