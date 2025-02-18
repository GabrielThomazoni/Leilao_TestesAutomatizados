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

	std::sort(lances.begin(), lances.end(), ordenaLances);
	size_t tamanho = lances.size() > 3 ? 3 : lances.size();
	maior3Lances = std::vector<Lance>(lances.begin(), lances.begin() + tamanho);

}

float Avaliador::getMaiorLance() const{
	return maiorLance;
}

float Avaliador::getMenorLance() const{
	return menorLance;
}

bool Avaliador::ordenaLances(const Lance& lance1, const Lance& lance2){
	return lance1.recuperaValor() > lance2.recuperaValor();
}

std::vector<Lance> Avaliador::getMaior3Lances() const{
	return maior3Lances;
}