#include "Usuario.hpp"

Usuario::Usuario(std::string nome): nome(nome)
{
}

std::string Usuario::recuperaNome() const
{
    if(nome.find(" ") != std::string::npos){
        return nome.substr(0, nome.find(" "));
    }else return nome.substr(0, nome.find_first_of("."));
}

std::string Usuario::recuperaSobrenome() const {
    if(nome.find(" ") != std::string::npos){
        return nome.substr(nome.find(" ") +1, nome.size());
    }else return "Não informado";
    
}