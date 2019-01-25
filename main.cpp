#include <iostream>
#include <locale.h>
#include "SingleFASTQ.h"
using namespace std;

int main (){
	setlocale(LC_ALL, "Portuguese");
	printf("Hello World\n");
	T teste;
	teste.test=  3;
	printf("%d\n", teste.test);
	return 0;
}