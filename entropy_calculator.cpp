#include <iostream>
#include <vector>
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
        calcualtor.print_file();
    }
    catch(entropy_error except){
        cout << "**Sorry,error " << except.getMessage() << endl;
    }

    return 0;
}

entropy_calculator::entropy_calculator() {
    lines.clear();
    found_characters.clear();
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

    }
}

void entropy_calculator::print_file() {
    for(unsigned int i = 0; i < lines.size(); i++) {
        cout << lines[i] << endl;
    }
}
