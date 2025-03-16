#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

int main() {
    int pya;
    std::cin >> pya;
    std::vector<std::string> arre;

    while (pya) {
        pya--;
        std::string x;
        std::cin >> x;
        std::transform(x.begin(), x.end(), x.begin(), ::tolower);
        arre.push_back(x);
    }

    std::string oString;
    std::cin >> oString;
    char letter1;
    std::cin >> letter1;
    letter1 = std::tolower(letter1);
    char letter2 = (letter1 == 'a') ? 'b' : 'a';

    std::set<int> setcito;

    for (const auto& x : arre) {
        std::string lowerOString = oString;
        std::transform(lowerOString.begin(), lowerOString.end(), lowerOString.begin(), ::tolower);
        size_t pos = lowerOString.find(x);
        while (pos != std::string::npos) {
            for (int i = pos; i < pos + x.length(); ++i) {
                setcito.insert(i);
            }
            pos = lowerOString.find(x, pos + 1);
        }
    }

    std::transform(oString.begin(), oString.end(), oString.begin(), [](unsigned char c) { return std::tolower(c); });

    for (int i : setcito) {
        char letter = (oString[i] == tolower(letter1)) ? letter2 : (oString[i] == toupper(letter1) ? toupper(letter2) : oString[i]);
        oString[i] = letter;
    }

    std::cout << oString << std::endl;

    return 0;
}
