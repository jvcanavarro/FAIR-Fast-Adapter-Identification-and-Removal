#include "Parameters.cpp"

int search(unsigned char *x, int m, unsigned char *y, int n);

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