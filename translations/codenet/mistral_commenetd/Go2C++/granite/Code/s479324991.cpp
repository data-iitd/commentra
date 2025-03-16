
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Scanner sc;

    // Read the number of elements in the array from the standard input
    int n = sc.NextInt();

    // Allocate memory for the array of size n
    vector<double> arr(n);

    // Read n integers from the standard input and store them in the array
    for (int i = 0; i < n; i++) {
        arr[i] = sc.NextInt();
    }

    // Sort the array in ascending order
    sort(arr.begin(), arr.end());

    // Initialize a variable prev to store the previous element in the sorted array
    double prev = arr[0];

    // Iterate through the sorted array from the second element to the last
    for (int i = 1; i < n; i++) {
        // Calculate the average of the previous and current elements
        prev = (prev + arr[i]) / 2;
    }

    // Print the result to the standard output
    cout << prev << endl;

    return 0;
}

// Initialize a new scanner object
class Scanner {
public:
    Scanner() {
        rdr = new BufferedReader(new InputStreamReader(System.in));
        buf = new StringBuilder();
        p = 0;
    }

    // Read a single token from the standard input
    string Next() {
        pre();
        int start = p;
        for (; p < buf.length(); p++) {
            if (buf.charAt(p) =='') {
                break;
            }
        }
        string result = buf.substring(start, p);
        p++;
        return result;
    }

    // Read a line from the standard input
    string NextLine() {
        pre();
        int start = p;
        p = buf.length();
        return buf.substring(start);
    }

    // Read an integer from the standard input
    int NextInt() {
        return Integer.parseInt(Next());
    }

    // Read an array of integers from the standard input
    vector<int> NextIntArray() {
        pre();
        int start = p;
        vector<int> result;
        for (; p < buf.length(); p++) {
            if (buf.charAt(p) =='') {
                result.push_back(Integer.parseInt(buf.substring(start, p)));
                start = p + 1;
            }
        }
        result.push_back(Integer.parseInt(buf.substring(start, p)));

        return result;
    }

    // Read a map from the standard input
    unordered_map<int, bool> NextMap() {
        pre();
        int start = p;
        unordered_map<int, bool> mp;
        for (; p < buf.length(); p++) {
            if (buf.charAt(p) =='') {
                mp[Integer.parseInt(buf.substring(start, p))] = true;
                start = p + 1;
            }
        }
        mp[Integer.parseInt(buf.substring(start, p))] = true;

        return mp;
    }

    // Prepare the scanner for the next read operation
    void pre() {
        if (p >= buf.length()) {
            readLine();
            p = 0;
        }
    }

    // Read a line from the standard input
    void readLine() {
        buf.setLength(0);
        try {
            int c;
            while ((c = rdr.read())!= -1) {
                if (c == '\n') {
                    break;
                }
                buf.append((char) c);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

private:
    BufferedReader *rdr;
    StringBuilder buf;
    int p;
};

// Translate the above C++ code to Java and end with comment "