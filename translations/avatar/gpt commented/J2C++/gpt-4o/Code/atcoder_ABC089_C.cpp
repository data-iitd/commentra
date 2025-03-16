#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TaskC {
public:
    void solve(int testNumber) {
        // Read the number of strings
        int n;
        cin >> n;
        
        // Initialize a vector to count occurrences of specific starting letters
        vector<long long> cnt(5, 0); // Fill the count vector with zeros
        
        // Process each string input
        for (int i = 0; i < n; ++i) {
            string str;
            cin >> str;
            // Increment the count based on the first character of the string
            if (str[0] == 'M') {
                cnt[0]++;
            } else if (str[0] == 'A') {
                cnt[1]++;
            } else if (str[0] == 'R') {
                cnt[2]++;
            } else if (str[0] == 'C') {
                cnt[3]++;
            } else if (str[0] == 'H') {
                cnt[4]++;
            }
        }
        
        // Calculate the result based on combinations of counts
        long long res = cnt[0] * cnt[1] * cnt[2] +
                        cnt[0] * cnt[1] * cnt[3] +
                        cnt[0] * cnt[1] * cnt[4] +
                        cnt[0] * cnt[2] * cnt[3] +
                        cnt[0] * cnt[2] * cnt[4] +
                        cnt[0] * cnt[3] * cnt[4] +
                        cnt[1] * cnt[2] * cnt[3] +
                        cnt[1] * cnt[2] * cnt[4] +
                        cnt[1] * cnt[3] * cnt[4] +
                        cnt[2] * cnt[3] * cnt[4];
        
        // Output the result
        cout << res << endl;
    }
};

int main() {
    // Create an instance of TaskC to solve the problem
    TaskC solver;
    // Call the solve method with test number 1
    solver.solve(1);
    
    return 0;
}

// <END-OF-CODE>
