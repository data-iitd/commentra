#include <bits/stdc++.h>
using namespace std;

// FastReader class to handle fast input
class FastReader {
    public:
    vector<string> split_string(string);
    int slen;
    string str;
    public:
    FastReader() {
        slen = 0;
        str = "";
    }
    string next() {
        while (slen == 0 || str[slen - 1] =='') {
            str = "";
            slen = 0;
            getline(cin, str);
        }
        int start = 0;
        int end = 0;
        while (end < slen && str[end]!='') {
            end++;
        }
        string res = str.substr(start, end - start);
        str = str.substr(end, slen - end);
        slen = slen - end;
        return res;
    }
    int nextInt() {
        return stoi(next());
    }
    long long nextLong() {
        return stoll(next());
    }
    double nextDouble() {
        return stod(next());
    }
    string nextLine() {
        string res = str;
        str = "";
        slen = 0;
        getline(cin, str);
        return res;
    }
};

// Utility function to split a string to vector of strings
vector<string> FastReader::split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x =='';
    });
    input_string.erase(new_end, input_string.end());
    while (input_string[input_string.length() - 1] =='') {
        input_string.pop_back();
    }
    vector<string> splits;
    char delimiter ='';
    size_t i = 0;
    size_t pos = input_string.find(delimiter);
    while (pos!= string::npos) {
        splits.push_back(input_string.substr(i, pos - i));
        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }
    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));
    return splits;
}

// Driver Code
int main() {
    FastReader scan;
    int t = 1; // Number of test cases (currently set to 1)
    while (t-- > 0) {
        solve(); // Call the solve method for processing
    }
    return 0;
}

// Function to determine the winner for each element
void solve() {
    // Read the number of elements in the array
    int t = scan.nextInt();
    int arr[t];
    
    // Populate the array with input values
    for (int i = 0; i < t; i++) {
        arr[i] = scan.nextInt();
    }
    
    int prevWinner = 0; // Variable to track the previous winner
    
    // Iterate through the array to determine the winner for each element
    for (int i = 0; i < t; i++) {
        // Check if the current element is 1
        if (arr[i] == 1) {
            // If the previous winner is 0, set the previous winner to 2
            if (prevWinner == 0) {
                prevWinner = 2;
            }
        }
        
        // Determine the winner based on the previous winner and the current element
        if (prevWinner == 2 || prevWinner == 0) {
            // If the previous winner is 2 or 0, check the parity of (arr[i] - 1)
            if ((arr[i] - 1) % 2 == 0) {
                cout << 2 << endl; // Print winner 2
                prevWinner = 2; // Update previous winner
            } else {
                cout << 1 << endl; // Print winner 1
                prevWinner = 1; // Update previous winner
            }
        } else {
            // If the previous winner is 1, check the parity of (arr[i] - 1)
            if ((arr[i] - 1) % 2 == 0) {
                cout << 1 << endl; // Print winner 1
                prevWinner = 1; // Update previous winner
            } else {
                cout << 2 << endl; // Print winner 2
                prevWinner = 2; // Update previous winner
            }
        }
    }
}

