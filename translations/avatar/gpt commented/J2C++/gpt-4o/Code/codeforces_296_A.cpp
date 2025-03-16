#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

class InputReader {
public:
    InputReader(istream &stream) : reader(stream) {}

    int nextInt() {
        int value;
        reader >> value;
        return value;
    }

private:
    istream &reader;
};

class Task {
public:
    void solve(InputReader &in, ostream &out) {
        // Read the number of elements
        int n = in.nextInt();

        // Initialize a map to count occurrences of each index (up to 1000)
        vector<int> array(1001, 0);

        // Read n integers and count their occurrences
        for (int i = 0; i < n; i++) {
            int index = in.nextInt();
            array[index]++;
        }

        // Determine the maximum count of any index
        int countMax = -1;
        for (int i = 1; i < array.size(); i++) {
            if (countMax < array[i])
                countMax = array[i];
        }

        // Check if the maximum count is within allowed limits based on n being even or odd
        if (n % 2 == 0) {
            // For even n, check if the maximum count is less than or equal to n/2
            if (countMax <= n / 2) {
                out << "YES" << endl;
            } else {
                out << "NO" << endl;
            }
        } else {
            // For odd n, check if the maximum count is less than or equal to n/2 + 1
            if (countMax <= n / 2 + 1) {
                out << "YES" << endl;
            } else {
                out << "NO" << endl;
            }
        }
    }
};

int main() {
    // Set up input and output streams
    InputReader in(cin);
    Task solver;

    // Call the solve method to process the input and produce output
    solver.solve(in, cout);

    return 0;
}

// <END-OF-CODE>
