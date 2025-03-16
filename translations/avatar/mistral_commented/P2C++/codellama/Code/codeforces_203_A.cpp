#######
# Code
#######

# Include the iostream library
#include <iostream>

// Input the string of numbers separated by spaces and split it into a list
std::string xxs;
std::cin >> xxs;
std::stringstream ss(xxs);
std::vector<int> xxs_list;
int x;
while (ss >> x) {
    xxs_list.push_back(x);
}

// Extract the first six numbers as integers and assign them to variables x, t, a, b, da, db respectively
int x = xxs_list[0];
int t = xxs_list[1];
int a = xxs_list[2];
int b = xxs_list[3];
int da = xxs_list[4];
int db = xxs_list[5];

// Define the main function to perform the logic of the program
void main() {
    // Check if x is equal to zero
    if (x == 0) {
        // If yes, print "YES" and return
        std::cout << "YES" << std::endl;
        return;
    }

    // Calculate the minimum time it takes for a and b to reach x
    int a_time = std::min(a / da, t - 1);
    int b_time = std::min(b / db, t - 1);

    // Loop through all possible combinations of a_time and b_time
    for (int i = 0; i <= a_time; i++) {
        for (int j = 0; j <= b_time; j++) {
            // Check if x is equal to a after 'i' time steps or b after 'j' time steps
            if (a - da * i == x || b - db * j == x) {
                // If yes, print "YES" and return
                std::cout << "YES" << std::endl;
                return;
            }

            // Check if x is equal to the sum of a after 'i' time steps and b after 'j' time steps
            if ((a - da * i) + (b - db * j) == x) {
                // If yes, print "YES" and return
                std::cout << "YES" << std::endl;
                return;
            }
        }
    }

    // If the result is "Result Not Found", print "NO"
    std::cout << "NO" << std::endl;
}

// Call the main function
main();

// End with comment "