
#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

// This function is the entry point of the program
void main() {
    // Read input from standard input
    int n;
    std::cin >> n;

    // Parse input into a vector of pairs, where each pair contains the score and the player of a piece
    std::vector<std::tuple<int, char>> pieces(n);
    for (int i = 0; i < n; i++) {
        int score;
        char player;
        std::cin >> score >> player;
        pieces[i] = std::make_tuple(score, player);
    }

    // Call the function to find Bob's maximum strength
    int result = Bob_sMaxStrength(pieces);

    // Print the result
    std::cout << result << std::endl;
}

// This function calculates Bob's maximum strength based on the given pieces
int Bob_sMaxStrength(const std::vector<std::tuple<int, char>>& pieces) {
    // Initialize variables to store the scores for players A and B
    int p_score = 0, s_score = 0, p_max_score = 0, s_max_score = 0;

    // Iterate through each piece and update the scores accordingly
    for (const auto& piece : pieces) {
        // If the piece belongs to player A, add its score to p_score
        if (std::get<1>(piece) == 'A') {
            p_score += std::get<0>(piece);
            // Update p_max_score if the current p_score is greater
            if (p_score > p_max_score) {
                p_max_score = p_score;
            }
        }
        // If the piece belongs to player B, subtract its score from p_score
        else {
            p_score -= std::get<0>(piece);
        }
    }

    // Iterate through the pieces in reverse order and update the scores for player S
    for (int i = pieces.size() - 1; i >= 0; i--) {
        // If the current piece belongs to player A, add its score to s_score
        if (std::get<1>(pieces[i]) == 'A') {
            s_score += std::get<0>(pieces[i]);
            // Update s_max_score if the current s_score is greater
            if (s_score > s_max_score) {
                s_max_score = s_score;
            }
        }
        // If the current piece belongs to player B, subtract its score from s_score
        else {
            s_score -= std::get<0>(pieces[i]);
        }
    }

    // Return the maximum score between Bob's and Sally's scores
    return std::max(p_max_score, s_max_score);
}

// Run the main function if the script is executed directly
int main() {
    main();
    return 0;
}

