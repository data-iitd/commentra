#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <sstream>

// This function is the entry point of the program
void main() {
    // Read input from standard input
    std::string input;
    std::getline(std::cin, input);

    // Parse input into a vector of pairs, where each pair contains the score and the player of a piece
    std::vector<std::pair<int, std::string>> pieces;
    std::getline(std::cin, input);
    std::stringstream ss(input);
    std::string token;
    while (std::getline(ss, token, ' ')) {
        int score = std::stoi(token);
        std::getline(ss, token, ' ');
        std::string player = token;
        pieces.push_back(std::make_pair(score, player));
    }

    // Call the function to find Bob's maximum strength
    int result = Bob_sMaxStrength(pieces);

    // Print the result
    std::cout << result << std::endl;
}

// This function calculates Bob's maximum strength based on the given pieces
int Bob_sMaxStrength(const std::vector<std::pair<int, std::string>>& pieces) {
    // Initialize variables to store the scores for players A and B
    int p_score = 0, s_score = 0;
    int p_max_score = 0, s_max_score = 0;

    // Iterate through each piece and update the scores accordingly
    for (const auto& piece : pieces) {
        // If the piece belongs to player A, add its score to p_score
        if (piece.second == "A") {
            p_score += piece.first;
            // Update p_max_score if the current p_score is greater
            if (p_score > p_max_score) {
                p_max_score = p_score;
            }
        }
        // If the piece belongs to player B, subtract its score from p_score
        else {
            p_score -= piece.first;
        }
    }

    // Iterate through the pieces in reverse order and update the scores for player S
    for (int i = pieces.size() - 1; i >= 0; --i) {
        // If the current piece belongs to player A, add its score to s_score
        if (pieces[i].second == "A") {
            s_score += pieces[i].first;
            // Update s_max_score if the current s_score is greater
            if (s_score > s_max_score) {
                s_max_score = s_score;
            }
        }
        // If the current piece belongs to player B, subtract its score from s_score
        else {
            s_score -= pieces[i].first;
        }
    }

    // Return the maximum score between Bob's and Sally's scores
    if (p_max_score > s_max_score) {
        return p_max_score;
    }
    return s_max_score;
}
