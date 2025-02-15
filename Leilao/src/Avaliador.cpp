#include "Avaliador.hpp"

void Avaliador::avalia(Leilao leilao){
	std::vector<Lance> lances = leilao.recuperaLances();
	for (Lance lance : lances){
		if(lance.recuperaValor() > maiorLance){
			maiorLance = lance.recuperaValor();
		} 
		if(lance.recuperaValor() < menorLance){
			menorLance = lance.recuperaValor();
		}
	} 
}

float Avaliador::getMaiorLance() const{
	return maiorLance;
}

float Avaliador::getMenorLance() const{
	return menorLance;
}