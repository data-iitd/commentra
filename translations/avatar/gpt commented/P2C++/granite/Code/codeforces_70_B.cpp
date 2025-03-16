
#include <iostream>  // Include the input/output stream module
#include <regex>  // Include the regular expression module

using namespace std;  // Use the standard namespace

int main() {
    int n;  // Declare an integer variable to store the maximum allowed length for sentences
    cin >> n;  // Read an integer input which represents the maximum allowed length for sentences

    int ans = 1, sumL = 0;  // Initialize the answer counter and the sum of lengths of sentences

    string text;  // Declare a string variable to store the input text
    getline(cin, text);  // Read the input text and store it in the text variable

    regex pattern("[.?!]");  // Define a regular expression pattern to match punctuation marks (.,?,!)
    smatch match;  // Declare a match object to store the results of the regular expression search

    int start = 0;  // Initialize the starting index of the current sentence
    while (regex_search(text, match, pattern, start)) {
        string s = match.str();  // Extract the current sentence from the text
        s = s.substr(0, s.length() - 1) + '.';  // Strip whitespace and add a period to the end of the sentence
        int L = s.length();  // Calculate the length of the current sentence

        // Check if the length of the sentence is greater than 1 (to avoid empty sentences)
        if (L > 1) {
            // If the length of the sentence exceeds the maximum allowed length, print "Impossible" and exit
            if (L > n) {
                cout << "Impossible" << endl;  // Print "Impossible"
                return 0;  // Exit the program
            }

            // Check if adding the current sentence length to the sum exceeds the maximum allowed length
            if (sumL + L + (sumL > 0) > n) {
                ans++;  // Increment the answer counter for a new line
                sumL = L;  // Reset the sum of lengths to the current sentence length
            } else {
                // Update the sum of lengths by adding the current sentence length
                sumL = sumL + L + (sumL > 0);  // Add 1 if there was a previous sentence (to account for space)
            }
        }

        start = match.position() + 1;  // Update the starting index for the next sentence
    }

    // Print the total number of lines needed
    cout << ans << endl;  // Print the total number of lines needed

    return 0;  // Return 0 to indicate successful execution
}
