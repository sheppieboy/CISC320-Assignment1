#include "insultgenerator_20075192.h";
#include <string>

using namespace std;

FileException::FileException(const string& file_error) : file_error(file_error){};

string& FileException::what(){
    return file_error;
}

NumInsultsOutOfBounds::NumInsultsOutOfBounds(const string& num_error) : num_error(num_error){};



