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
	string file = "amostra1.fastq";
	if (sfile.openFASTQInput(file) == true)
	{
		while (sfile.hasNext())
		{
			single = sfile.getNext();
			cout << single << endl;
		}
	}
	
	// Parameters
	Parameters parameters;
  	parameters.parseParameters(argc, argv);
  
	return 0;
}	