

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    // Read input as a vector of integers
    vector<int> input_vector;
    int input_element;
    while ( cin >> input_element ) {
        input_vector.push_back( input_element );
    }

    // Sort the input vector in ascending order
    sort( input_vector.begin(), input_vector.end() );

    // Initialize a variable to store the result
    string result = "";

    // Iterate through the sorted vector starting from the second element
    for ( int i = 1; i < input_vector.size(); i++ ) {

        // Compare the current element with the previous one
        int current_element = input_vector[i];
        int previous_element = input_vector[i-1];

        // Check if the current element is less than twice the previous element
        // and if it is not equal to the previous element
        if ( current_element < previous_element * 2 && current_element!= previous_element ) {

            // If the condition is true, set the result to 'YES'
            result = "YES";

            // Break out of the loop since we have found the answer
            break;
        }
    }

    // Print the result
    cout << result << endl;

    return 0;
}
