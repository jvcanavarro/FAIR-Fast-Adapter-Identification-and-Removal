#include "PairedFASTQFile.cpp"

class Parameters
{
private:
	string version, single, forward, reverse, interlaced, adapter, forwardAdapter, reverseAdapter;
	bool onlyIdentify , onlyRemove, trim, trimQuality, ready;
	int minQuality, threads, phredOffset;
	string outputDir;
public:
	Parameters(int argc, char *const argv[]);
	bool parseParameters();
	void printHelp();
	void printVersion();
	string getOutputDir();
	string getSingle();
	string getForward();
	string getReverse();
	string getInterlaced();
	bool identifyOnly();
	bool removeOnly();
	bool trimm();
	bool trimmQuality();
	int getMinQuality();
	string getAdapter();
	string getForwardAdapter();
	string getReverseAdapter();
	int getThreads();
	int getPhredOffset();	// Quality
};

Parameters::Parameters(int argc, char *const argv[])
{
	bool help = false, version = false;
	this->version = "1.0";
	onlyIdentify = false;
	onlyRemove = false;
	trim = false;
	trimQuality = false;
	threads = 4;
	phredOffset = 0;
	ready = true;
	for(int i = 1; i < argc; i++) {
		string argument(argv[i]);
		if(argument == "--help" || argument == "-h") {
			help = true;
			continue;
		} else if(argument == "--version" || argument == "-v") {
			version = true;
			continue;
		} else if(argument == "--forward" || argument == "-f") {
			forward = argv[i + 1];
			continue;
		} else if (argument == "--reverse" || argument == "-r") {
			reverse = argv[i + 1];
			continue;
		} else if (argument == "--single" || argument == "-s") {
			single = argv[i + 1];
			continue;
		} else if (argument == "--interlaced" || argument == "-i") {
			interlaced = argv[i + 1];
			continue;
		} else if (argument == "--only-identify") {
			onlyIdentify = true;
			continue;
		} else if (argument == "--only-remove") {
			onlyRemove = true;
			continue;
		} else if (argument == "--trim") {
			trim = true;
			continue;
		} else if (argument == "--trim-quality") {
			trimQuality = true;
			continue;
		} else if (argument == "--min-quality") {
			minQuality = atoi(argv[i + 1]);
			continue;
		} else if (argument == "--threads" || argument == "-t") {
			threads = atoi(argv[i + 1]);
			continue;
		} else if (argument == "-phred-offset") {
			phredOffset = atoi(argv[i + 1]);
			continue;
		} else if (argument == "--adapter") {
			adapter = argv[i + 1];
			continue;
		} else if (argument == "--forward-adapter") {
			forwardAdapter = argv[i + 1];
			continue;
		} else if (argument == "--reverse-adapter"){
			reverseAdapter = argv[i + 1];
			continue;
		} else if (argument == "--output" || argument == "-o") {
			outputDir = argv[i + 1];
			continue;
		}
	}
	const char *oDir = outputDir.c_str();
	DIR* dir = opendir(oDir);
	if(help) {
        printHelp();
        ready = false;
    } else if(version) {
        printVersion();
        ready = false;
    } else if(outputDir.length() == 0 || (single.length() == 0 && (forward.length() == 0 || reverse.length() == 0))) {
        printHelp();
        ready = false;
	} else if(dir){
		// directory exists.
		// Parameters::outputDir += "/results.fastq" ;
		time_t rawtime;
		time(&rawtime);
		cout << ctime(&rawtime);
		outputDir = outputDir + "/" + ctime(&rawtime);
		outputDir.erase(outputDir.length() - 1);
		outputDir.append(".fastq");
		cout << outputDir << endl;
		// cout << "Added results.fastq" << endl;
		closedir(dir);
	} else if (ENOENT == errno){
		cerr << "Directory Does Not Exist." << endl;
		ready = false;
	}
}

bool Parameters::parseParameters()
{
	if (ready)
	{
		PairedFASTQ pairedData;
		PairedFASTQFile pff;
		if (pff.openFASTQInputFile(forward, reverse) && pff.openFASTQOutputFile(outputDir))
		{
			while(pff.hasNext())
			{
				// open method
				pairedData = pff.getNext();
				// write method

			}

			return true;
		} else return false;

	}
}
void Parameters::printHelp()
{	
	cout << ifstream("Help.md").rdbuf() << endl;
}
void Parameters::printVersion()
{
	cout << "FAIR - Fast Adapter Idenification and Removal v" << version <<  endl;
}
string Parameters::getOutputDir()
{
	return outputDir;
}
string Parameters::getSingle()
{
	return single;
}
string Parameters::getForward()
{
	return forward;
}
string Parameters::getReverse()
{
	return reverse;
}
string Parameters::getInterlaced()
{
	return interlaced;
}
bool Parameters::identifyOnly()
{
	if (onlyIdentify) return true;
	else return false;
}
bool Parameters::removeOnly()
{
	if (onlyRemove) return true;
	else return false;
}
bool Parameters::trimm()
{
	if (trim) return true;
	else return false;
}
bool Parameters::trimmQuality()
{
	if (trimQuality) return true;
	else return false;
}
int Parameters::getMinQuality()
{
	return minQuality;
}
string Parameters::getAdapter()
{
	return adapter;
}
string Parameters::getForwardAdapter()
{
	return forwardAdapter;
}
string Parameters::getReverseAdapter()
{
	return reverseAdapter;
}
int Parameters::getThreads()
{
	return threads;
}
int Parameters::getPhredOffset()
{
	return phredOffset;
}