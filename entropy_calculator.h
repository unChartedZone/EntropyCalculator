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
    void calculate_t();
    void calculate_probability();
    void calculate_entropies();
    void sum_of_entropies();
    void print_data();


 private:

    float T; //Number of letters
    float sum;
    string accentedN = "ñ";
    string accentedI = "í";
    string accentedO = "õ";
    string otherAccentedO = "ó";
    string accentedU = "ú";
    string accentedE = "é";
    string accentedA = "á";


    vector<string> lines;
    vector<float> probabilities;
    vector<float> entropies;
    map<char,int > found_characters; //first is the character,the int is it's occurrence
    map<string,int> special_characters;
    map<char,int>::iterator iter;
    map<string,int>::iterator spec_iter;

    string remove_special_n(string s);
    string remove_special_i(string s);
    string remove_special_o(string s);
    string remove_other_o(string s);
    string remove_special_u(string s);
    string remove_special_e(string s);
    string remove_special_a(string s);

};
#endif
