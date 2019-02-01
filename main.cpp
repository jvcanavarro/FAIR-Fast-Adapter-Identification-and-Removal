#include "SingleFASTQFile.cpp"

int main(int argc, char **argv)
{
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
	// Terminal arguments test
	cout << "You have entered " << argc << " arguments:" << "\n"; 
  
    for (int i = 1; i < argc; ++i) cout << argv[i] << "\n"; 
	return 0;
} 