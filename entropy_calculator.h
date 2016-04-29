#ifndef ENTROPY_CALCULATOR_H
#define ENTROPY_CALCULATOR_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <map>

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
    string accentedN = "ñ";
    string accentedI = "í";
    string accentedO = "õ";
    string accentedU = "ú";
    string accentedE = "é";

    string remove_special_n(string s);
    string remove_special_i(string s);


    vector<string> lines;
    map<char,int > found_characters; //first is the character,the int is it's occurrence
    map<string,int> special_characters;
    map<char,int>::iterator iter;
    map<string,int>::iterator spec_iter;
};
#endif
