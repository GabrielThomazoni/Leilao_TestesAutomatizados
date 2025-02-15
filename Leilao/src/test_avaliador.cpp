#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include "Avaliador.hpp"

TEST_CASE("Testando o maior lance de um leilão com 2 lances, independente da ordem de lances") {

    //Preparando para o teste (Arrange - Given)
    Leilao leilao1("Playstation 3 novo");
    Lance lance1(Usuario("Gabriel"), 250);
    Lance lance2(Usuario("Thomaz"), 500);
    leilao1.recebeLance(lance1);
    leilao1.recebeLance(lance2);

    Avaliador leiloeiro;

    //Executando o código a ser testado (Act - When)
    leiloeiro.avalia(leilao1);

    //Verificando se o código se comportou como esperado (Assert - Then)
    float resEsperado = 500;
    REQUIRE(leiloeiro.getMaiorLance() == resEsperado);

    std::cout << "Maior lance foi: " << leiloeiro.getMaiorLance() << std::endl;

} 