#include "PairedFASTQFile.cpp"

class Parameters
{
private:
	string version, single, forward, reverse, interlaced, adapter, forwardAdapter, reverseAdapter, outputDir;
	bool onlyIdentify , onlyRemove, trim, trimQuality, ready;
	int minQuality, threads, phredOffset;

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
	int getPhredOffset();
};

Parameters::Parameters(int argc, char *const argv[])
{
	this->version = "1.0";
	bool help = false, version = false;
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
		time_t rawtime;
		time(&rawtime);

		outputDir = outputDir + "/" + ctime(&rawtime);
		outputDir.erase(outputDir.length() - 1);
		outputDir.append(".fastq");

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
		if (single.length() != 0)
		{
			SingleFASTQFile s_fastq;
			if (s_fastq.openFASTQInput(single) && s_fastq.openFASTQOutput(outputDir))
			{
				if (onlyIdentify)
				{
					cerr << "Adapter (Single FIle)" << s_fastq.identifyAdapter() << endl;
					return true;
				}

				while(s_fastq.hasNext())
				{
					if (onlyRemove)
					{
						s_fastq.write()
					}
				}
			}
		}
	}
}
void Parameters::printHelp()
{	
	// cout << ifstream("Help.md").rdbuf() << endl;
	cerr << endl << "FAIR v1.0" << endl << endl;
    cerr << "Fast Adapter Identification & Removal" << endl << endl;
	cerr << "Usage: " << argv[0] << " [options] -o <output_dir> " << endl << endl;
	cerr << "Basic options:" << endl;
	cerr << "    -o/--output <output_dir>    Folder to store all the files generated during the assembly (required)." << endl;
    cerr << "    -p/--partitions <int>       Number of partitions [default: 16]" << endl;
    cerr << "    -w/--whole                  Use whole dataset to merge [default: off]" << endl;
    cerr << "    --iontorrent                This flag is required for IonTorrent data." << endl;
    cerr << "    -h/--help                   Prints this usage message." << endl;
    cerr << "    -v/--version                Prints version info" << endl << endl;
	cerr << "Input data:" << endl;
	cerr << "    -f/--forward <filename>     File with forward paired-end reads." << endl;
	cerr << "    -r/--reverse <filename>     File with reverse paired-end reads." << endl;
    cerr << "    -s/--single <filename>      File with unpaired reads." << endl << endl;
    cerr << "Advanced options:" << endl;
    cerr << "    -t/--threads <int>          Number of threads [default: 4]" << endl;
    cerr << "    -k/--kmers <int>            Number of kmers to run the assembly [default: 3]" << endl << endl;
	cerr << "Please, report bugs to: jvcanavarro@gmail.com" << endl;
	cerr << "Software homepage: <https://github.com/jvcanavarro/FAIR-Fast-Adapter-Identification-and-Removal>" << endl << endl;
}
void Parameters::printVersion()
{
	cerr << endl << "FAIR - Fast Adapter Identification & Removal v1.0" << endl << endl;
	cerr << "Copyright (C) 2019 Federal University of Para." << endl;
	cerr << "License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>." << endl;
	cerr << "This is free software: you are free to change and redistribute it." << endl;
	cerr << "There is NO WARRANTY, to the extent permitted by law." << endl << endl;
	cerr << "Written by João V. Canavarro." << endl << endl;
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
	return onlyIdentify;
}
bool Parameters::removeOnly()
{
	return onlyRemove;
}
bool Parameters::trimm()
{
	return trim;
}
bool Parameters::trimmQuality()
{
	return trimQuality;
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