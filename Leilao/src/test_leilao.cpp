#include <iostream>
#include "catch.hpp"
#include "Leilao.hpp"
#include "Usuario.hpp"

TEST_CASE("Testando se o leilão impede dois lances seguidos da mesma pessoa"){
    //Preparando para o teste (Arrange - Given)
    Leilao leilao("Azeite de Oliva");
    Usuario Biel("Gabriel");
    Usuario Maily("Maily");

    Lance lance1(Biel, 1250);
    Lance lance2(Biel, 1500);
    Lance lance3(Maily, 1200);
    Lance lance4(Biel, 2000);
    Lance lance5(Biel, 3000);
    Lance lance6(Biel, 3500);
    Lance lance7(Maily, 5000);
    
    //Executando o código a ser testado (Act - When)
    leilao.recebeLance(lance1);
    leilao.recebeLance(lance2);
    leilao.recebeLance(lance3);
    leilao.recebeLance(lance4);
    leilao.recebeLance(lance5);
    leilao.recebeLance(lance6);
    leilao.recebeLance(lance7);

    //Verificando se o código se comportou como esperado (Assert - Then)
    float ultLance = leilao.recuperaLances().back().recuperaValor();
    REQUIRE(leilao.recuperaLances().size() == 4);
    REQUIRE(leilao.recuperaLances()[1].recuperaValor() == 1200);
    std::cout << "Leiloando: " << leilao.getDescricao() << std::endl;
    std::cout << "Último lance: " << ultLance << std::endl;
}
 