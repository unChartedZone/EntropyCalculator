#ifndef ENTROPY_ERROR_H
#define ENTROPY_ERROR_H
#include <string>

using namespace std;

class entropy_error {

public:
    entropy_error(string s) {
        message = s;
        }

    entropy_error() {
        message = "An error has occurred";
        }

    string getMessage() {
        return message;
    }

private:
    string message;
};
#endif
