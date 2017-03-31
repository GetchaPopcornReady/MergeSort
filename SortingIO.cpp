#include "SortingIO.h"
using namespace std;

void valuesIntoArray(std::vector<long>& vect, std::string file)
{

	ifstream inputFile;
	inputFile.open(file.c_str());

	
	int counter = 0;
	int number;


	if(inputFile.good())
	{
		while(inputFile >> number)
		{
			vect.push_back(number);
		}
	}
	else
	{
		cout << "error opening file" << endl;
	}


}


void outputToTextFile(std::vector<long> vect, std::string file)
{

	ofstream outputFile;

	outputFile.open(file.c_str());

	if(outputFile.good())
	{
		for(int i = 0; i < vect.size(); i++)
		{
			outputFile << vect.at(i) << endl;
		}
	}
	else
	{
		cout << "error opening file" << endl;
	}

}

