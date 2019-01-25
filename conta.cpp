// Colinha OOP C++
#include <iostream>
using namespace std;

class Conta
{
	int numero;
	string nome;
	float saldo;
public:
	void inicializa(string n, float s);
	void deposita(float valor);
	void consulta();
	int saque(float valor);
};
				
void Conta::inicializa(string n, float s)
{
	nome = n;
	saldo = s;
	if (saldo < 0) cout << "Erro na Criação da Conta!!!" << endl;
}

void Conta::deposita(float valor)
{
	saldo += valor;
}

void Conta::consulta()
{
	cout << "Cliente: " << nome << endl;
	cout << "Saldo Atual: " << saldo << endl;
	cout << "Número da COnta: " << numero << endl;
}

int Conta::saque(float valor)
{
	if (saldo < valor) return 0;
	else{
		saldo -= valor;
		return 1;
	}
}
