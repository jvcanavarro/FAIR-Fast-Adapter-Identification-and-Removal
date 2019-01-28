#include "SingleFASTQ.cpp"

int main (){
	setlocale(LC_ALL, "Portuguese");
	singleFASTQ single;
	vector <int> test;
	test = single.convertQualityToInteger();
	// for (int i = 0; i < test.size() ; i++) cout << test[i] << endl;
	return 0;
} 