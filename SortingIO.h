#ifndef SORTINGIO_H
#define SORTINGIO_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector> 

void valuesIntoArray(std::vector<long>& vect, std::string file);

void outputToTextFile(std::vector<long> vect, std::string file);
#endif