#include "SortingIO.h"
#include "stdlib.h"

using namespace std;
using std::vector;

void merge(vector<long>& a, vector<long>& b, int size, int left, int middle);
void mergeSort(vector<long>& a, int size);

int main(int argc, char *argv[]) {
	int size;
	vector<long> myVector;

	std::string inputFileName;
	std::string outputFileName;

	if (argc != 3)
	{
		std::cout << "Please include the input file name followed by the output file name...";
		exit(0);
	}

	inputFileName = argv[1];
	outputFileName = argv[2];

	valuesIntoArray(myVector, inputFileName);
	size = myVector.size();
	mergeSort(myVector, size);
	outputToTextFile(myVector, outputFileName);
}

void merge(vector<long>& a, vector<long>& b, int size, int left, int middle) {
	int right = middle + middle - left;
	if (right > size) {
		right = size;
	}
	int i = left;
	int j = middle;
	int k = left;
	while (i < middle && j < right) {
		if (a[i] < a[j]) {
			b.push_back(a[i]);
			i++;
		}
		else {
			b.push_back(a[j]);
			j++;
		}
	}
	while (i < middle) {
		b.push_back(a[i]);
		i++;
	}
	while (j < right) {
		b.push_back(a[j]);
		j++;
	}
	for (i = left; i < right; ++i) {
		a[i] = b[i];
	}

}

void mergeSort(vector<long>& a, int size) {
	vector<long> b;
	for (int i = 1; i < size; i *= 2) {
		b.resize(0);
		for (int left = 0, middle = i; middle < size; left = middle + i, middle = left + i) {
			merge(a, b, size, left, middle);
		}
	}
}
