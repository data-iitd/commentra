#include <iostream>
#include <string>

using namespace std;

// searchRange finds the range of indices in the text where 'R' and 'L' are located.
// It returns the start index, the middle index (first non-'R' character), and the end index (first non-'L' character).
void searchRange(const string &text, int start, int limit, int &middle, int &end) {
    middle = -1;

    // Find the first index where the character is not 'R'
    for (int i = start; i < limit; i++) {
        if (text[i] != 'R') {
            middle = i;
            break;
        }
    }

    end = limit;

    // Find the first index after 'middle' where the character is not 'L'
    for (int i = middle; i < limit; i++) {
        if (text[i] != 'L') {
            end = i;
            break;
        }
    }
}

// answer processes the input text and prints the results based on the 'R' and 'L' characters.
void answer() {
    string text;
    // Read input text from standard input
    cin >> text;
    int limit = text.length();

    int start = 0;
    int middle = 0;
    int end = 0;
    bool firstPrinted = false;

    // Loop until the end of the text is reached
    while (end < limit) {
        // Get the range of indices for the current segment of 'R's and 'L's
        searchRange(text, start, limit, middle, end);
        int len1 = middle - start;
        int len2 = end - middle;

        // Print '0's for the 'R' segment
        for (int i = start; i < middle; i++) {
            if (firstPrinted) {
                cout << " ";
            }
            cout << "0";
            firstPrinted = true;
        }

        // Calculate counts based on the lengths of the segments
        int count1 = (len1 + 1) / 2 + len2 / 2;
        int count2 = len1 / 2 + (len2 + 1) / 2;

        // Print the counts for the current segment
        if (firstPrinted) {
            cout << " ";
        }
        cout << count1 << " " << count2;
        firstPrinted = true;

        // Print '0's for the 'L' segment
        for (int i = middle; i < end; i++) {
            if (firstPrinted) {
                cout << " ";
            }
            cout << "0";
            firstPrinted = true;
        }
        // Move to the next segment
        start = end;
    }
    // Print a newline at the end of the output
    cout << endl;
}

// main function serves as the entry point of the program
int main() {
    answer();
    return 0;
}

// <END-OF-CODE>
