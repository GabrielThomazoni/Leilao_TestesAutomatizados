#include <iostream>
#include "catch.hpp"
#include "Usuario.hpp"

TEST_CASE("Testando usuários com nome composto, retornando só o primeiro"){

    //Preparando para o teste (Arrange - Given)
    Usuario Gabriel("Gabriel Thomazoni");

    //Executando o código a ser testado (Act - When)
    std::string primeiroNome = Gabriel.recuperaNome();
    std::string sobrenome = Gabriel.recuperaSobrenome();

    //Verificando se o código se comportou como esperado (Assert - Then)
    REQUIRE(primeiroNome == "Gabriel");
    REQUIRE(sobrenome == "Thomazoni");
    std::cout << "Primeiro nome: " << Gabriel.recuperaNome() << std::endl;
    std::cout << "Sobrenome: " << Gabriel.recuperaSobrenome() << std::endl;
}