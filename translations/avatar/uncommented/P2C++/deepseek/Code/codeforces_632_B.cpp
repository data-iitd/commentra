#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <sstream>

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::vector<std::tuple<int, char>> pieces;
    std::stringstream ss(input);
    std::string token;
    while (std::getline(ss, token, ' ')) {
        int value = std::stoi(token);
        char type;
        std::cin >> type;
        pieces.emplace_back(value, type);
    }
    std::cout << Bob_sMaxStrength(pieces) << std::endl;
    return 0;
}

int Bob_sMaxStrength(const std::vector<std::tuple<int, char>>& pieces) {
    int pScore = 0, sScore = 0;
    int pMaxScore = 0, sMaxScore = 0;
    for (const auto& piece : pieces) {
        if (std::get<1>(piece) == 'B') {
            pScore += std::get<0>(piece);
            sScore += std::get<0>(piece);
        }
    }
    for (const auto& piece : pieces) {
        if (std::get<1>(piece) == 'A') {
            pScore += std::get<0>(piece);
            if (pScore > pMaxScore) {
                pMaxScore = pScore;
            }
        } else {
            pScore -= std::get<0>(piece);
        }
    }
    for (int i = pieces.size() - 1; i >= 0; --i) {
        if (std::get<1>(pieces[i]) == 'A') {
            sScore += std::get<0>(pieces[i]);
            if (sScore > sMaxScore) {
                sMaxScore = sScore;
            }
        } else {
            sScore -= std::get<0>(pieces[i]);
        }
    }
    return std::max(pMaxScore, sMaxScore);
}
