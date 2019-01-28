#include "SingleFASTQ.cpp"

int main (){
	singleFASTQ single;
	vector <int> test;
	test = single.convertQ33ToInteger();
	// for (int i = 0; i < test.size() ; i++) cout << test[i] << endl;
	test = single.convertQ64ToInteger();
	// for (int i = 0; i < test.size() ; i++) cout << test[i] << endl;
	return 0;
} 