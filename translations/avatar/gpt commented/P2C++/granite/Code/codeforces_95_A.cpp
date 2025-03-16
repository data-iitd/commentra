
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main() {
    int pya;
    std::cin >> pya;
    std::vector<std::string> arre;
    for (int i = 0; i < pya; i++) {
        std::string str;
        std::cin >> str;
        arre.push_back(str);
    }
    std::string oString;
    std::cin >> oString;
    std::string lowString = oString;
    std::transform(lowString.begin(), lowString.end(), lowString.begin(), ::tolower);
    char letter1;
    std::cin >> letter1;
    char letter2 = (letter1 == 'a')? 'b' : 'a';
    std::vector<bool> valid(oString.length(), false);
    std::set<int> setcito;
    for (const auto& str : arre) {
        size_t pos = 0;
        while (true) {
            pos = lowString.find(str, pos);
            if (pos == std::string::npos) {
                break;
            }
            for (int i = pos; i < pos + str.length(); i++) {
                valid[i] = true;
            }
            pos++;
        }
    }
    std::string result = oString;
    for (int i = 0; i < oString.length(); i++) {
        if (valid[i]) {
            char letter = (oString[i] == letter1)? letter2 : letter1;
            result[i] = (oString[i] >= 'a' && oString[i] <= 'z')? letter : std::toupper(letter);
        }
    }
    std::cout << result << std::endl;
    return 0;
}

