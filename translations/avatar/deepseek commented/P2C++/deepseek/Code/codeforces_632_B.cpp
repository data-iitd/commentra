#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <sstream>

int Bob_sMaxStrength(const std::vector<std::tuple<int, char>>& pieces) {
    // Initialize scores for both ends and their maximum scores
    int pScore = 0, sScore = 0;
    int pMaxScore = 0, sMaxScore = 0;

    // Calculate the score from the front (left to right)
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

    // Calculate the score from the back (right to left)
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

    // Return the maximum score between the two ends
    if (pMaxScore > sMaxScore) {
        return pMaxScore;
    }
    return sMaxScore;
}

int main() {
    // Take input from the user
    std::string line;
    std::getline(std::cin, line); // Read the first line (ignored)
    std::getline(std::cin, line); // Read the second line

    // Process the input to get a vector of (value, type) pairs for each piece
    std::vector<std::tuple<int, char>> pieces;
    std::istringstream iss(line);
    std::string token;
    while (iss >> token) {
        int value = std::stoi(token);
        char type = iss.get(); // Read the next character
        pieces.emplace_back(value, type);
    }

    // Call the Bob_sMaxStrength function with the processed pieces and return its result
    int result = Bob_sMaxStrength(pieces);
    std::cout << result << std::endl;

    return 0;
}

