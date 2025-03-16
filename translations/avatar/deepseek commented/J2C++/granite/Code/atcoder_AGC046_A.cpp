

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Create a FastReader object to read input
    FastReader sc;
    // Create a PrintWriter object to write output
    PrintWriter pw;

    // Read an integer input
    int x = sc.nextInt();
    // Initialize a counter to keep track of the number of iterations
    int count = 0;
    // Store the initial value of x in a temporary variable
    int tmp = x;
    // Initialize x to 0 to start the loop
    x = 0;

    // Loop until x becomes 360
    while (x!= 360) {
        // Increment x by tmp
        x = x + tmp;
        // If x exceeds 360, adjust it by subtracting 360
        if (x > 360) {
            x = x - 360;
        }
        // Increment the counter
        count++;
    }

    // Print the final count
    cout << count << endl;

    return 0;
}

class FastReader {
public:
    BufferedReader br;
    stringstream ss;

    FastReader() {
        br = BufferedReader(new InputStreamReader(cin));
    }

    string next() {
        while (ss.str().empty()) {
            string s = br.readLine();
            if (s.empty()) {
                break;
            }
            ss.str(s);
        }
        return ss.str();
    }

    int nextInt() {
        int ret;
        ss >> ret;
        ss.str("");
        ss.clear();
        return ret;
    }

    long long nextLong() {
        long long ret;
        ss >> ret;
        ss.str("");
        ss.clear();
        return ret;
    }

    double nextDouble() {
        double ret;
        ss >> ret;
        ss.str("");
        ss.clear();
        return ret;
    }

    string nextLine() {
        string ret = br.readLine();
        ss.str("");
        ss.clear();
        return ret;
    }
};

