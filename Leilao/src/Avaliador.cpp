#include "Avaliador.hpp"

void Avaliador::avalia(Leilao leilao){
	std::vector<Lance> lances = leilao.recuperaLances();
	for (Lance lance : lances){
		if(lance.recuperaValor() > maiorLance){
			maiorLance = lance.recuperaValor();
		}
	} 
}

float Avaliador::getMaiorLance() const{
	return maiorLance;
}