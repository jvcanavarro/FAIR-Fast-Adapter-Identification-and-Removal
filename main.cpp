#include "Parameters.cpp"

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
	
	// Parameters
	//Parameters parameters;

//	cout << "You have entered " << argc << " arguments:" << "\n"; 
  
    for (int i = 0; i < argc; ++i) cout << argv[i] << "\n"; 
    sfile.closeOutput();
	return 0;
}