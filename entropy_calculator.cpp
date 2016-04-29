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
        calcualtor.print_file();
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
            special_characters[accentedN] = counter++;
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

void entropy_calculator::print_file() {
    for(unsigned int i = 0; i < lines.size(); i++) {
        cout << lines[i] << endl;
    }
}
