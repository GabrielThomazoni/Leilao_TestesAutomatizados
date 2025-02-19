#pragma once
#include <vector>
#include <string>
#include "Lance.hpp"

class Leilao
{
private:
    std::vector<Lance> lances;
    std::string descricao;

    bool lanceValido(const Lance& lance);

public:
    Leilao(std::string descricao);
    const std::vector<Lance>& recuperaLances() const;
    void recebeLance(const Lance& lance);
    std::string getDescricao() const;
};


