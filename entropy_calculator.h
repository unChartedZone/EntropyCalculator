#ifndef ENTROPY_CALCULATOR_H
#define ENTROPY_CALCULATOR_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class entropy_calculator {

public:
    //ctor
    entropy_calculator();

    //dtor
    ~entropy_calculator();

    void read_file(string filename);
    void find_characters();
    void print_file(); //Just to test if the whole file is there

private:
    vector<string> lines;
    vector<string> found_characters;
};
#endif
