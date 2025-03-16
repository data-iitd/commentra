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
        std::string temp;
        std::cin >> temp;
        std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        arre.push_back(temp);
    }
    std::string oString;
    std::cin >> oString;
    std::transform(oString.begin(), oString.end(), oString.begin(), ::tolower);
    char letter1;
    std::cin >> letter1;
    char letter2 = (letter1 == 'a') ? 'b' : 'a';
    std::vector<int> valid(oString.size(), 0);
    std::set<int> setcito;
    for (const auto& x : arre) {
        size_t pos = 0;
        while ((pos = oString.find(x, pos)) != std::string::npos) {
            for (size_t i = pos; i < pos + x.size(); ++i) {
                setcito.insert(i);
            }
            pos += 1;
        }
    }
    std::vector<char> oStringVec(oString.begin(), oString.end());
    for (int i : setcito) {
        char letter = (oString[i] != letter1) ? letter1 : letter2;
        oStringVec[i] = (std::islower(oStringVec[i])) ? letter : std::toupper(letter);
    }
    for (char x : oStringVec) {
        std::cout << x;
    }
    std::cout << std::endl;
    return 0;
}
