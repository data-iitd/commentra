#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    // Define the number of items in the input array
    int n;
    cin >> n;

    // Initialize an empty vector to store the input data
    vector<tuple<int, int, int, int>> input_array;

    // Read n items from the standard input and append them to the input_array
    for (int i = 0; i < n; i++) {
        int S, R, H, C;
        cin >> S >> R >> H >> C;
        input_array.push_back(make_tuple(S, R, H, C));
    }

    // Initialize an empty set to store the outdated items
    set<tuple<int, int, int, int>> outdated;

    // Check for outdated items in the input array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Check if the current item is older and smaller than the next one
            if (get<0>(input_array[i]) < get<0>(input_array[j]) &&
                get<1>(input_array[i]) < get<1>(input_array[j]) &&
                get<2>(input_array[i]) < get<2>(input_array[j])) {
                // Append the current item to the outdated set
                outdated.insert(input_array[i]);
            }
        }
    }

    // Initialize minimum_cost and input_number to large initial values
    int minimum_cost = 100000;
    int input_number = 0;

    // Find the item with the minimum cost that is not outdated
    for (int i = 0; i < n; i++) {
        auto current_item = input_array[i];
        int cost = get<3>(current_item);
        // Check if the current item is not outdated and has a smaller cost than minimum_cost
        if (current_item not in outdated && cost < minimum_cost) {
            // Update minimum_cost and input_number
            minimum_cost = cost;
            input_number = i + 1;
        }
    }

    // Print the index of the item with the minimum cost that is not outdated
    cout << input_number << endl;

    return 0;
}

