#include "Lance.hpp"

Lance::Lance(Usuario usuario, float valor): usuario(usuario), valor(valor)
{
}

float Lance::recuperaValor() const
{
    return valor;
}

std::string Lance::getUsuario() const{
    return usuario.recuperaNome();
}
