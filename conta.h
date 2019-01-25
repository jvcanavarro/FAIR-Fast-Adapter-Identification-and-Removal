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