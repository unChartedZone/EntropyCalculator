#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <math.h>
#include "entropy_calculator.h"
#include "entropy_error.h"

using namespace std;

int main(int argc,char *argv[]) {
    if(argc != 2) {
        cout << "Error, you must supply the name of the file " <<
            "to process at the command line." << endl;
        exit(1);
    }
    string filename = argv[1];
    try{
        entropy_calculator calculator;
        calculator.read_file(filename);
        calculator.find_characters();
        calculator.calculate_t();
        calculator.calculate_probability();
        calculator.calculate_entropies();
        calculator.sum_of_entropies();
        calculator.print_data();
    }
    catch(entropy_error except){
        cout << "**Sorry,error " << except.getMessage() << endl;
    }

    return 0;
}

entropy_calculator::entropy_calculator() {
    T = 0;
    sum = 0;
    lines.clear();
    probabilities.clear();
    entropies.clear();
    found_characters.clear(); //Just to be sure
    special_characters.clear(); //Just to be sure
    german_selected = true;
}

entropy_calculator::~entropy_calculator() {

}

void entropy_calculator::read_file(string filename) {
    ifstream infile(filename.c_str());
    string line;
    if(!infile) throw entropy_error("Error opening file");
    while (!infile.eof()) {
        getline(infile,line);
        lines.push_back(line);
    }
    infile.close();
}

void entropy_calculator::find_characters() {
    string str; //will hold current string
    for(unsigned int i = 0; i < lines.size(); i++) {
        str = lines[i];
        if (german_selected) {
            str = remove_german_a(str);
            str = remove_german_b(str);
            str = remove_german_o(str);
            str = remove_german_u(str);
        }
        else {
            str = remove_special_n(str);
            str = remove_special_i(str);
            str = remove_special_o(str);
            str = remove_other_o(str);
            str = remove_special_u(str);
            str = remove_special_e(str);
            str = remove_special_a(str);
        }
        //All special characters should have been removed by now
        for(int j = 0; j < str.length(); j++) {
            char current = str[j];
            if(!isalpha(current)) continue; //Check to see if valid character
            current = toupper(current);
            iter = found_characters.find(current);
            if(iter == found_characters.end()) {
                found_characters[current] = 1;
                continue;
            }
            iter->second++;
            continue;
        }
    }
}

string entropy_calculator::remove_special_n(string s) {
    bool can_stil_contian = true;
    int counter = 1;
    while(can_stil_contian) {
        int position = s.find(accentedN);
        if(position == -1) {
            can_stil_contian = false;
            continue;
        }
        //Found an accented n then
        spec_iter = special_characters.find(accentedN);
        if(spec_iter == special_characters.end()){
            special_characters[accentedN] = 1;
            s.erase(position,accentedN.length());
            continue;
        }
        spec_iter->second++;
        s.erase(position,accentedN.length());
        continue;
    }
    return s;
}

string entropy_calculator::remove_special_i(string s) {
    bool can_stil_contian = true;
    int counter = 1;
    while(can_stil_contian) {
        int position = s.find(accentedI);
        if(position == -1) {
            can_stil_contian = false;
            continue;
        }
        //Found an accented n then
        spec_iter = special_characters.find(accentedI);
        if(spec_iter == special_characters.end()){
            special_characters[accentedI] = 1;
            s.erase(position,accentedI.length());
            continue;
        }
        spec_iter->second++;
        s.erase(position,accentedI.length());
        continue;
    }
    return s;
}

string entropy_calculator::remove_special_o(string s) {
    bool can_stil_contian = true;
    int counter = 1;
    while(can_stil_contian) {
        int position = s.find(accentedO);
        if(position == -1) {
            can_stil_contian = false;
            continue;
        }
        //Found an accented n then
        spec_iter = special_characters.find(accentedO);
        if(spec_iter == special_characters.end()){
            special_characters[accentedO] = 1;
            s.erase(position,accentedO.length());
            continue;
        }
        spec_iter->second++;
        s.erase(position,accentedO.length());
        continue;
    }
    return s;
}

string entropy_calculator::remove_other_o(string s) {
    bool can_stil_contian = true;
    int counter = 1;
    while(can_stil_contian) {
        int position = s.find(otherAccentedO);
        if(position == -1) {
            can_stil_contian = false;
            continue;
        }
        //Found an accented n then
        spec_iter = special_characters.find(otherAccentedO);
        if(spec_iter == special_characters.end()){
            special_characters[otherAccentedO] = 1;
            s.erase(position,otherAccentedO.length());
            continue;
        }
        spec_iter->second++;
        s.erase(position,otherAccentedO.length());
        continue;
    }
    return s;
}

string entropy_calculator::remove_special_u(string s) {
    bool can_stil_contian = true;
    int counter = 1;
    while(can_stil_contian) {
        int position = s.find(accentedU);
        if(position == -1) {
            can_stil_contian = false;
            continue;
        }
        //Found an accented n then
        spec_iter = special_characters.find(accentedU);
        if(spec_iter == special_characters.end()){
            special_characters[accentedU] = 1;
            s.erase(position,accentedU.length());
            continue;
        }
        spec_iter->second++;
        s.erase(position,accentedU.length());
        continue;
    }
    return s;
}

string entropy_calculator::remove_special_e(string s) {
    bool can_stil_contian = true;
    int counter = 1;
    while(can_stil_contian) {
        int position = s.find(accentedE);
        if(position == -1) {
            can_stil_contian = false;
            continue;
        }
        //Found an accented n then
        spec_iter = special_characters.find(accentedE);
        if(spec_iter == special_characters.end()){
            special_characters[accentedE] = 1;
            s.erase(position,accentedE.length());
            continue;
        }
        spec_iter->second++;
        s.erase(position,accentedE.length());
        continue;
    }
    return s;
}

string entropy_calculator::remove_special_a(string s) {
    bool can_stil_contian = true;
    int counter = 1;
    while(can_stil_contian) {
        int position = s.find(accentedA);
        if(position == -1) {
            can_stil_contian = false;
            continue;
        }
        //Found an accented n then
        spec_iter = special_characters.find(accentedA);
        if(spec_iter == special_characters.end()){
            special_characters[accentedA] = 1;
            s.erase(position,accentedA.length());
            continue;
        }
        spec_iter->second++;
        s.erase(position,accentedA.length());
        continue;
    }
    return s;
}

string entropy_calculator::remove_german_a(string s) {
    bool can_stil_contian = true;
    int counter = 1;
    while(can_stil_contian) {
        int position = s.find(germanA);
        if(position == -1) {
            can_stil_contian = false;
            continue;
        }
        //Found an accented n then
        spec_iter = special_characters.find(germanA);
        if(spec_iter == special_characters.end()){
            special_characters[germanA] = 1;
            s.erase(position,germanA.length());
            continue;
        }
        spec_iter->second++;
        s.erase(position,germanA.length());
        continue;
    }
    return s;
}

string entropy_calculator::remove_german_b(string s) {
    bool can_stil_contian = true;
    int counter = 1;
    while(can_stil_contian) {
        int position = s.find(germanB);
        if(position == -1) {
            can_stil_contian = false;
            continue;
        }
        //Found an accented n then
        spec_iter = special_characters.find(germanB);
        if(spec_iter == special_characters.end()){
            special_characters[germanB] = 1;
            s.erase(position,germanB.length());
            continue;
        }
        spec_iter->second++;
        s.erase(position,germanB.length());
        continue;
    }
    return s;
}

string entropy_calculator::remove_german_o(string s) {
    bool can_stil_contian = true;
    int counter = 1;
    while(can_stil_contian) {
        int position = s.find(germanO);
        if(position == -1) {
            can_stil_contian = false;
            continue;
        }
        //Found an accented n then
        spec_iter = special_characters.find(germanO);
        if(spec_iter == special_characters.end()){
            special_characters[germanO] = 1;
            s.erase(position,germanO.length());
            continue;
        }
        spec_iter->second++;
        s.erase(position,germanO.length());
        continue;
    }
    return s;
}

string entropy_calculator::remove_german_u(string s) {
    bool can_stil_contian = true;
    int counter = 1;
    while(can_stil_contian) {
        int position = s.find(germanU);
        if(position == -1) {
            can_stil_contian = false;
            continue;
        }
        //Found an accented n then
        spec_iter = special_characters.find(germanU);
        if(spec_iter == special_characters.end()){
            special_characters[germanU] = 1;
            s.erase(position,germanU.length());
            continue;
        }
        spec_iter->second++;
        s.erase(position,germanU.length());
        continue;
    }
    return s;
}




void entropy_calculator::print_file() {
    for(unsigned int i = 0; i < lines.size(); i++) {
        cout << lines[i] << endl;
    }
}

void entropy_calculator::calculate_t() {
    map<char,int>::iterator temp;
    for(temp = found_characters.begin(); temp != found_characters.end(); temp++) {
        int current = temp->second;
        T = T + current;
    }
    map<string,int>::iterator temp2;
    for(temp2 = special_characters.begin(); temp2 != special_characters.end();temp2++) {
        int current = temp2->second;
        T = T + current;
    }

    cout << "This is T: " << T << endl;
}

void entropy_calculator::calculate_probability() {
//    T = found_characters.size() + special_characters.size();
    for(iter = found_characters.begin(); iter != found_characters.end();iter++) {
        int currentOccurrence = iter->second;
        currentOccurrence = (double)currentOccurrence;
        double temp = currentOccurrence/T;
        probabilities.push_back(temp);
    }
    for(spec_iter = special_characters.begin(); spec_iter != special_characters.end();spec_iter++) {
        int currentOccurrence = spec_iter->second;
        currentOccurrence = (double)currentOccurrence;
        double temp = currentOccurrence/T;
        probabilities.push_back(temp);
    }
}

void entropy_calculator::calculate_entropies() {
    for(int i = 0; i < probabilities.size();i++) {
        float temp = log2(probabilities[i]);
        cout << "Log2 of entropy " << temp << endl;
        float current = probabilities[i] * temp;
        entropies.push_back(current);
    }
}

void entropy_calculator::sum_of_entropies() {
    for(int i = 0; i < entropies.size(); i++) {
        sum = sum + entropies[i];
    }
    sum *= -1;
}

void entropy_calculator::print_data() {
    int counter = 0;
    for(iter = found_characters.begin(); iter != found_characters.end();iter++) {
        cout << iter->first << ": " << iter->second
            << "\tProbablity: " << setprecision(5) << fixed << probabilities[counter] << "\tEntropy: " << setprecision(5) << fixed << entropies[counter] <<endl;
        counter++;
    }
    for(spec_iter = special_characters.begin();spec_iter != special_characters.end();++spec_iter) {
        cout << spec_iter->first << ": " << spec_iter->second
            << "\tProbability: " << setprecision(5) << fixed << probabilities[counter] << "\tEntropy: " << setprecision(5) << fixed << entropies[counter] << endl;
        counter++;
    }

//    cout << "Probabilites: " << endl;
//    cout << "#############" << endl;
//    for(int i = 0; i < probabilities.size();i++) {
//        cout << probabilities[i] << endl;
//    }
//    cout << "#########################" << endl;
//    cout << "# of normal characters " << found_characters.size() << endl;
//    cout << "# of special characters " << special_characters.size() << endl;
    cout << endl;
    cout << "This is the sum: " << fixed << sum << endl;
}






