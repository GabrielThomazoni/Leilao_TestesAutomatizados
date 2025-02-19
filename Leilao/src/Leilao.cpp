#include "Leilao.hpp"

Leilao::Leilao(std::string descricao): descricao(descricao)
{
    
}

bool Leilao::lanceValido(const Lance& lance){
    return lance.recuperaValor() > 0 && lance.getUsuario() != lances.back().getUsuario();
}

const std::vector<Lance>& Leilao::recuperaLances() const
{
    return lances;
}

void Leilao::recebeLance(const Lance& lance)
{
    if(lances.empty() || lanceValido(lance)){
        lances.push_back(lance);
    }
}

std::string Leilao::getDescricao() const{
    return descricao;
}
