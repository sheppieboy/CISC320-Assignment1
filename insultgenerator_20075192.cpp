#include "insultgenerator_20075192.h";
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

//File Exception class implementation
FileException::FileException(const string& file_error) : file_error(file_error){};

//what function for outputting file_error string
string& FileException::what(){
    return file_error;
}

//Num Insults Out of Bounds class implementation
NumInsultsOutOfBounds::NumInsultsOutOfBounds(const string& num_error) : num_error(num_error){};

//what function for outputting num_error string
string& NumInsultsOutOfBounds::what(){
    return num_error;
}


//Insult Generator class implementation

//constructor

InsultGenerator::InsultGenerator(){}


void InsultGenerator::initialize(){
        ifstream fileIn("InsultsSource.txt");

        if (fileIn.fail()) {
            throw FileException("Unable to open the file.");
        }

        string line;
        while (getline(fileIn, line)) {
            
            istringstream iss(line);
            
            string word1, word2, word3;

            if (!(iss >> word1 >> word2 >> word3)) {
                throw FileException("Error reading file content.");
            }

            first_column.push_back(word1);
            second_column.push_back(word2);
            third_column.push_back(word3);
        }

        fileIn.close();
}





