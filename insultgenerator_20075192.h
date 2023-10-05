#ifndef InsultGenerator_H
#define InsultGenerator_H
#include <string>
#include <vector>
#include <set>

class FileException {
public:
    //constructor
    FileException(const std::string& file_error);

    //function to output to user the file error string
   std::string& what();

private:

    //the file error string
    std::string file_error;
};

class NumInsultsOutOfBounds {
public:
    //constructor
    NumInsultsOutOfBounds(const std::string& num_error);

    //what() function is a standard function for excepts and outputs the error string
    std::string& what();
private:

    //the num insults out of bounds string
    std::string num_error;
};

class InsultGenerator{
public:
    //constructor
    InsultGenerator();

    //we use a void function, initialize, to load all the source phrases from the InsultsSource.txt file into the attributes.
    void initialize();

    //a function that generates a single shakespearean insult and the outputs is a string
    std::string talkToMe();

    //a function that generates an input of type int number of insults and outputs a vector of strings with the insults
    std::vector<std::string> generate(const int number_of_insults);

    //generates the requested number of unique insults and saves them to the filename, as a by product it returns a vector of strings with the insults
    std::vector<std::string> generateAndSave(const std::string str_insult, const int number_insults);

private:
    //a function that returns a random integer
    int getRandomInt();

    //the string vectors of each column in the input txt file
    std::vector<std::string> first_column, second_column, third_column;

    // we are going to use a set of string insults to avoid duplicates in the set
    std::set<std::string> nonduplicate_results;
};

#endif
