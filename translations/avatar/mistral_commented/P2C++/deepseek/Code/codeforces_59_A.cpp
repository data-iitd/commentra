#include <iostream>
#include <string>

int main() {
    std::string txt;
    std::getline(std::cin, txt);

    int cu = 0;
    int cl = 0;

    for (char z : txt) {
        if (islower(z)) {
            cl += 1;
        } else if (isupper(z)) {
            cu += 1;
        }
    }

    if (cu > cl) {
        for (char &z : txt) {
            z = toupper(z);
        }
    } else {
        for (char &z : txt) {
            z = tolower(z);
        }
    }

    std::cout << txt << std::endl;

    return 0;
}
