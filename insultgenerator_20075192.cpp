#include "insultgenerator_20075192.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <random>

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

// afunction to generate a random integer in the size of the column vectors to get an index in the column
int InsultGenerator::getRandomInt(){
    
    //Seed the random number generator from OS
    random_device rd; 
    
    //use Mersenne Twister pseudo random number generator
    mt19937 gen(rd());

    //define the distribution for generating random ints, the column size should be used -1
    uniform_int_distribution<int> distribution(0, first_column.size() - 1);

    return distribution(gen);
    
}

//talk to me function to output a randomly generated string insult
string InsultGenerator::talkToMe(){
    int n1, n2, n3;
    n1 = getRandomInt();
    n2 = getRandomInt();
    n3 = getRandomInt();

    string output_insult;
    output_insult = "Thou "+first_column[n1] + " " + second_column[n2] + " " + third_column[n3]+"!";
    return output_insult;
}

// generate() generates the requested number of unique insults. and outputs a vector 
vector<string> InsultGenerator::generate(int number_of_insults){
    if(number_of_insults > 10000 || number_of_insults < 1){
        throw NumInsultsOutOfBounds("Out of bounds integer used for insults.");
        //return empty vector
        return vector<string>();
    }
    //use a set to efficiently stop duplication of insults
    set<string>nonduplicate_results;

    while(nonduplicate_results.size() < number_of_insults){
        string temp(talkToMe());
        nonduplicate_results.insert(temp);
    }

    vector<string> final_insults; // store results in this
    final_insults.reserve(nonduplicate_results.size()); // allocate proper amount of space

    //insert results into the final results vector<string>
    for (const std::string& insult : nonduplicate_results) {
        final_insults.push_back(insult);
    }

    return final_insults;

}


//generates the requested number of unique insults and saves them to the filename, as a by product it returns a vector of strings with the insults
vector<string> InsultGenerator::generateAndSave(string filename, int bound) {
    //use odfstream
	ofstream outputFile(filename);
    //create set to stop duplicates again
	
    set<string> nonduplicate_results;
	
    if (bound < 1 || bound > 10000) {
		throw NumInsultsOutOfBounds("The integer you selected is out of bounds.");
		return vector<string>();
	}
	else {
		while (bound > nonduplicate_results.size()) {
			string generated_insult = talkToMe();
			nonduplicate_results.insert(generated_insult);
			outputFile << generated_insult;
			outputFile << "\n";
		} 
	}
	vector<string> final_insults; // store results in this
    final_insults.reserve(nonduplicate_results.size()); // allocate proper amount of space

    //insert results into the final results vector<string>
    for (const std::string& insult : nonduplicate_results) {
        final_insults.push_back(insult);
    }

    return final_insults;
}





