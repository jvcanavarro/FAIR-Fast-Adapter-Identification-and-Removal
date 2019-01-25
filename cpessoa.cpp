#include "conta.cpp"

int main (){
	Conta MinhaConta;
	Conta *OutraConta;

	// Erro: o saldo só é acessado por meio dos métodos
	// MinhaConta.saldo = 10; 

	MinhaConta.inicializa("Fulano", 10.25);
	OutraConta->inicializa("Beltrado", 220.00);

	MinhaConta.deposita(12.75);
	MinhaConta.consulta();
	MinhaConta.saque(15.00);
	MinhaConta.consulta();

	OutraConta->consulta();
	return 0;
}