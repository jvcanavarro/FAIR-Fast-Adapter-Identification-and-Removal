#include "Parameters.cpp"

int main(int argc, char *const argv[])
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
	
	// Parameters
	Parameters parameters;
  	parameters.parseParameters(argc, argv);
  
	return 0;
}