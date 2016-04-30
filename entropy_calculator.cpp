#include <iostream>
#include <vector>
#include <map>
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
        entropy_calculator calcualtor;
        calcualtor.read_file(filename);
        calcualtor.find_characters();
//        calcualtor.print_file();
        calcualtor.print_data();
    }
    catch(entropy_error except){
        cout << "**Sorry,error " << except.getMessage() << endl;
    }

    return 0;
}

entropy_calculator::entropy_calculator() {
    lines.clear();
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
        str = remove_special_n(str);
        str = remove_special_i(str);
        str = remove_special_o(str);
        str = remove_other_o(str);
        str = remove_special_u(str);
        str = remove_special_e(str);
        str = remove_special_a(str);
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


void entropy_calculator::print_file() {
    for(unsigned int i = 0; i < lines.size(); i++) {
        cout << lines[i] << endl;
    }
}

void entropy_calculator::print_data() {
    for(iter = found_characters.begin(); iter != found_characters.end();iter++) {
        cout << iter->first << ": " << iter->second << endl;
    }
    for(spec_iter = special_characters.begin();spec_iter != special_characters.end();++spec_iter) {
        cout << spec_iter->first << ": " << spec_iter->second << endl;
    }
}


