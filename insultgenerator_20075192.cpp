#include "insultgenerator_20075192.h";
#include <string>

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






