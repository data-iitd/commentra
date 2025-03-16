#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    // Read the number of items from user input
    int n;
    cin >> n;

    // Initialize an empty vector to store the input items
    vector<tuple<int, int, int, int>> input_array;

    // Loop to read each item's attributes (S, R, H, C)
    for (int i = 0; i < n; i++) {
        // Read the attributes S, R, H, C and convert them to integers
        int S, R, H, C;
        cin >> S >> R >> H >> C;
        // Append the attributes as a tuple to the input_array
        input_array.push_back(make_tuple(S, R, H, C));
    }

    // Initialize a set to keep track of outdated items
    set<tuple<int, int, int, int>> outdated;

    // Compare each item with every other item to find outdated ones
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Check if item i is outdated compared to item j
            if (get<0>(input_array[i]) < get<0>(input_array[j]) &&
                get<1>(input_array[i]) < get<1>(input_array[j]) &&
                get<2>(input_array[i]) < get<2>(input_array[j])) {
                // If outdated, add item i to the outdated set
                outdated.insert(input_array[i]);
            }
        }
    }

    // Initialize variables to track the minimum cost and corresponding item index
    int minimum_cost = 100000;
    int input_number = 0;

    // Loop through the input items to find the one with the minimum cost that is not outdated
    for (int i = 0; i < n; i++) {
        auto current_item = input_array[i];
        int cost = get<3>(current_item);  // Get the cost of the current item
        // Check if the current item is not outdated and has a lower cost than the current minimum
        if (outdated.find(current_item) == outdated.end() && cost < minimum_cost) {
            minimum_cost = cost;  // Update the minimum cost
            input_number = i + 1;  // Store the index of the current item (1-based index)
        }
    }

    // Print the index of the item with the minimum cost that is not outdated
    cout << input_number << endl;

    return 0;
}

