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

    std::string lowString = oString;
    std::transform(lowString.begin(), lowString.end(), lowString.begin(), ::tolower);

    char letter1;
    std::cin >> letter1;
    letter1 = std::tolower(letter1);

    char letter2 = (letter1 == 'a') ? 'b' : 'a';

    std::vector<int> valid(oString.size(), 0);
    std::set<int> setcito;

    for (const auto& x : arre) {
        size_t pos = 0;
        while ((pos = lowString.find(x, pos)) != std::string::npos) {
            for (size_t i = pos; i < pos + x.size(); ++i) {
                setcito.insert(i);
            }
            pos += x.size();
        }
    }

    for (int i : setcito) {
        char letter = (lowString[i] == letter1) ? letter2 : letter1;
        if (islower(oString[i])) {
            oString[i] = letter;
        } else {
            oString[i] = std::toupper(letter);
        }
    }

    std::cout << oString << std::endl;

    return 0;
}
