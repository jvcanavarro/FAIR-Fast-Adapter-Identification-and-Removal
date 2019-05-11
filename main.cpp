#include "Parameters.cpp"

int main(int argc, char *const argv[])
{	
	// Parameters
	Parameters parameters(argc, argv);
	if (parameters.parseParameters())
	{
		; 
	}	
	return 0;
}	