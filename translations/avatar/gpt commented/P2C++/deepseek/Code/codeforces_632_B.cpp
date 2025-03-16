#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <sstream>

int Bob_sMaxStrength(const std::vector<std::tuple<int, char>>& pieces) {
    // Initialize scores for player A and player B, and their maximum scores
    int pScore = 0, sScore = 0;
    int pMaxScore = 0, sMaxScore = 0;

    // Calculate maximum score for player A by iterating through pieces from the start
    for (const auto& piece : pieces) {
        if (std::get<1>(piece) == 'A') {  // If the piece belongs to player A
            pScore += std::get<0>(piece);  // Add the score of the piece to player A's score
            if (pScore > pMaxScore) {  // Update maximum score if current score exceeds it
                pMaxScore = pScore;
            }
        } else {  // If the piece belongs to player B
            pScore -= std::get<0>(piece);  // Subtract the score of the piece from player A's score
        }
    }

    // Calculate maximum score for player B by iterating through pieces from the end
    for (int i = pieces.size() - 1; i >= 0; --i) {
        if (std::get<1>(pieces[i]) == 'A') {  // If the piece belongs to player A
            sScore += std::get<0>(pieces[i]);  // Add the score of the piece to player B's score
            if (sScore > sMaxScore) {  // Update maximum score if current score exceeds it
                sMaxScore = sScore;
            }
        } else {  // If the piece belongs to player B
            sScore -= std::get<0>(pieces[i]);  // Subtract the score of the piece from player B's score
        }
    }

    // Return the maximum score between player A and player B
    return std::max(pMaxScore, sMaxScore);
}

int main() {
    // Read input (the first input is ignored)
    std::string line;
    std::getline(std::cin, line);

    // Read the second line of input, split it into integers and corresponding characters,
    // and create a vector of tuples where each tuple is a pair of (score, character)
    std::vector<std::tuple<int, char>> pieces;
    std::getline(std::cin, line);
    std::stringstream ss(line);
    int score;
    char character;
    while (ss >> score >> character) {
        pieces.emplace_back(score, character);
    }

    // Call the function to calculate Bob's maximum strength and return the result
    std::cout << Bob_sMaxStrength(pieces) << std::endl;

    return 0;
}

