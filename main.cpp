#include "SingleFASTQFile.cpp"

int main (){
	SingleFASTQ single;
	SingleFASTQFile sfile;
	vector <int> test;
	test = single.convertQ33ToInteger();
	// for (int i = 0; i < test.size() ; i++) cout << test[i] << endl;
	test = single.convertQ64ToInteger();
	// for (int i = 0; i < test.size() ; i++) cout << test[i] << endl;
	bool open;
	string file = "amostra1.fastq";
	open = sfile.openFASTQInput(file);
	cout << open << endl;
	return 0;
} 