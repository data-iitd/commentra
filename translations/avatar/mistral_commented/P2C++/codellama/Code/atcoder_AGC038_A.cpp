#include <iostream>
#include <string>
#include <vector>

// Define a function named 'solve' that takes four integer arguments: H, W, A, and B.
void solve(int H, int W, int A, int B) {

    // Initialize a 2D vector named 'answer' of size H x W with all elements set to the string "0".
    std::vector<std::vector<std::string>> answer(H, std::vector<std::string>(W, "0"));

    // Iterate through each row 'i' in the range of H.
    for (int i = 0; i < H; i++) {
        // Iterate through each column 'j' in the range of W.
        for (int j = 0; j < W; j++) {
            // Set the value of the cell 'answer[i][j]' based on the conditions.
            if (i < B) {
                if (j < A) {
                    answer[i][j] = "0";
                } else {
                    answer[i][j] = "1";
                }
            } else {
                if (j < A) {
                    answer[i][j] = "1";
                } else {
                    answer[i][j] = "0";
                }
            }
        }
    }

    // Iterate through each row 'i' in the range of H and print its elements joined by an empty string.
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            std::cout << answer[i][j];
        }
        std::cout << std::endl;
    }
}

// Define a function named 'main' that does not take any arguments.
int main() {

    // Define an inner function named 'iterate_tokens' that reads input from standard input and yields each token as a string.
    auto iterate_tokens = []() {
        std::string line;
        while (std::getline(std::cin, line)) {
            std::istringstream iss(line);
            std::string word;
            while (iss >> word) {
                yield word;
            }
        }
    };

    // Read the input tokens and assign them to the variables H, W, A, and B.
    auto tokens = iterate_tokens();
    int H = std::stoi(next(tokens));
    int W = std::stoi(next(tokens));
    int A = std::stoi(next(tokens));
    int B = std::stoi(next(tokens));

    // Call the 'solve' function with the given input.
    solve(H, W, A, B);

    return 0;
}

// 