#include <iostream>
#include <string>

char* generateString() {
    std::string sb;
    for (int i = 1; i <= 1000; i++) {
        sb += std::to_string(i);
    }
    char* charArray = new char[sb.length() + 1];
    std::strcpy(charArray, sb.c_str());
    return charArray;
}

int main() {
    int n;
    std::cin >> n;
    char* generatedString = generateString();
    std::cout << generatedString[n - 1] << std::endl;
    delete[] generatedString; // Free the allocated memory
    return 0;
}

// <END-OF-CODE>
