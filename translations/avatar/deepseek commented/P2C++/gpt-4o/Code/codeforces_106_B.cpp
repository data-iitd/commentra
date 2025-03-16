#include <iostream>
#include <vector>
#include <set>
#include <tuple>
#include <limits>

using namespace std;

int main() {
    int n;
    cin >> n;  // Take the number of elements as input
    vector<tuple<int, int, int, int>> input_array;  // Initialize a vector to store tuples

    // Loop to take inputs and append them as tuples to input_array
    for (int i = 0; i < n; i++) {
        int S, R, H, C;
        cin >> S >> R >> H >> C;  // Take four integers as input
        input_array.push_back(make_tuple(S, R, H, C));  // Append the tuple to input_array
    }

    set<tuple<int, int, int, int>> outdated;  // Initialize a set to store outdated elements

    // Nested loop to compare each element in input_array with every other element
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (get<0>(input_array[i]) < get<0>(input_array[j]) &&
                get<1>(input_array[i]) < get<1>(input_array[j]) &&
                get<2>(input_array[i]) < get<2>(input_array[j])) {
                outdated.insert(input_array[i]);  // Insert outdated elements to outdated set
            }
        }
    }

    int minimum_cost = numeric_limits<int>::max();  // Initialize minimum_cost to a large value
    int input_number = 0;  // Initialize input_number to 0

    // Iterate through input_array to find the item with the minimum cost that is not outdated
    for (int i = 0; i < n; i++) {
        auto current_item = input_array[i];
        int cost = get<3>(current_item);
        if (outdated.find(current_item) == outdated.end() && cost < minimum_cost) {
            minimum_cost = cost;  // Update minimum_cost
            input_number = i + 1;  // Update input_number
        }
    }

    cout << input_number << endl;  // Print the input number of the item with the minimum cost that is not outdated

    return 0;
}  // <END-OF-CODE>
