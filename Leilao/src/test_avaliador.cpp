#include <iostream>
#include "catch.hpp"
#include "Avaliador.hpp"

Leilao criaLeilaoPS3(){
    Leilao leilao("PS3");
    Lance lance2(Usuario("Thomaz"), 500);
    Lance lance1(Usuario("Gabriel"), 250);
    Lance lance3(Usuario("Ezequiel"), 400);
    Lance lance4(Usuario("Deysi"), 350);
    Lance lance5(Usuario("Leila"), 650);
    leilao.recebeLance(lance1);
    leilao.recebeLance(lance2);
    leilao.recebeLance(lance3);
    leilao.recebeLance(lance4);
    leilao.recebeLance(lance5);
    
    return leilao;
}

Leilao criaLeilaoTV(){
    Leilao leilao("TV 4K");
    Lance lance1(Usuario("Matheus"), 250);
    Lance lance2(Usuario("Max"), 500);
    Lance lance3(Usuario("Ezequiel"), 400);
    Lance lance4(Usuario("Deysi"), 350);
    Lance lance5(Usuario("Leila"), 650);
    leilao.recebeLance(lance1);
    leilao.recebeLance(lance2);
    leilao.recebeLance(lance3);
    leilao.recebeLance(lance4);
    leilao.recebeLance(lance5);
    
    return leilao;
}

Leilao testaMaior3Lances(){
    Leilao leilao("PCzão");
    Lance lance1(Usuario("Jéssica"), 2000);
    Lance lance2(Usuario("Maxuel"), 5500);
    Lance lance3(Usuario("Ezequiel"), 4000);
    Lance lance4(Usuario("Deysi"), 3500);
    Lance lance5(Usuario("Leila"), 6500);    
    
    leilao.recebeLance(lance1);
    leilao.recebeLance(lance2);
    leilao.recebeLance(lance3);
    leilao.recebeLance(lance4);
    leilao.recebeLance(lance5);
    
    return leilao;
}

/* TEST_CASE("Testando o MAIOR lance de um leilão com 2 lances, independente da ordem de lances") {

//Preparando para o teste (Arrange - Given)
Leilao leilao = criaLeilaoPS3();
Avaliador leiloeiro;

//Executando o código a ser testado (Act - When)
leiloeiro.avalia(leilao);

//Verificando se o código se comportou como esperado (Assert - Then)
float resEsperado = 500;
REQUIRE(leiloeiro.getMaiorLance() == resEsperado);

std::cout << "Maior lance foi: " << leiloeiro.getMaiorLance() << std::endl;

} 

TEST_CASE("Testando o MENOR lance de um leilão com 2 lances, independente da ordem de lances") {

//Preparando para o teste (Arrange - Given)
Leilao leilao = criaLeilaoTV();
Avaliador leiloeiro;

//Executando o código a ser testado (Act - When)
leiloeiro.avalia(leilao);

//Verificando se o código se comportou como esperado (Assert - Then)
float resEsperado = 250;
REQUIRE(leiloeiro.getMenorLance() == resEsperado);

std::cout << "Menor lance foi: " << leiloeiro.getMenorLance() << std::endl;

}  */

TEST_CASE("Testando o MAIOR e o MENOR lances") {
    
    Avaliador leiloeiro;
    
    SECTION("Leiloes pegando Maior e Menor lance"){
        Leilao leilao = GENERATE(criaLeilaoTV(), criaLeilaoPS3()); //Só funciona se os leiloes tiverem os mesmo valores dos lances

        SECTION("Testando Maior e Menor lance"){
            leiloeiro.avalia(leilao);
            float valMaiorEsperado = 650;
            float valMenorEsperado = 250;
            REQUIRE(leiloeiro.getMaiorLance() == valMaiorEsperado);
            REQUIRE(leiloeiro.getMenorLance() == valMenorEsperado);
            std::cout << "Leiloando: " << leilao.getDescricao() << std::endl;
            std::cout << "Maior lance foi: " << leiloeiro.getMaiorLance() << std::endl;
            std::cout << "Menor lance foi: " << leiloeiro.getMenorLance() << std::endl;
        }
    }
    
    SECTION("Testando os três MAIORES lances, recebendo eles em ordem decrescente, em um leilão com 5 lances independente da ordem dos lances"){
        //Preparando para o teste (Arrange - Given)
        Leilao leilao = testaMaior3Lances();
        
        //Executando o código a ser testado (Act - When)
        leiloeiro.avalia(leilao);
        
        //Verificando se o código se comportou como esperado (Assert - Then)
        std::vector<Lance> maior3Lances = leiloeiro.getMaior3Lances();
        REQUIRE(maior3Lances.size() == 3);
        REQUIRE(maior3Lances[0].recuperaValor() == 6500);
        REQUIRE(maior3Lances[1].recuperaValor() == 5500);
        REQUIRE(maior3Lances[2].recuperaValor() == 4000);
        
        std::cout << "Leiloando: " << leilao.getDescricao() << std::endl;
        std::cout << "Primeiro maior lance: " << maior3Lances[0].recuperaValor() << std::endl;
        std::cout << "Segundo maior lance: " << maior3Lances[1].recuperaValor() << std::endl;
        std::cout << "Terceiro maior lance: " << maior3Lances[2].recuperaValor() << std::endl;
    }
    
} 