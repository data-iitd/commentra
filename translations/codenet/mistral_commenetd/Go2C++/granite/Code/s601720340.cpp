
#include <bits/stdc++.h>
using namespace std;

#define magic 1000000007

string cpuprofile, memprofile;

int N;
vector<int> p;

// find function checks if a given number n is present in the p vector
int find(int n) {
    for (int i = 0; i < N; i++) {
        if (n == p[i]) {
            return 0;
        }
    }
    return 1;
}

// solve function contains the main logic of the problem
void solve() {
    // Create an Io instance for reading input
    Io io;
    defer io.Flush();

    // Parse input using the NextInt function of the Io instance
    int X = io.NextInt();
    Logf("%v\n", X);
    N = io.NextInt();
    Logf("%v\n", N);
    for (int i = 0; i < N; i++) {
        p.push_back(io.NextInt());
    }
    Logf("p %v\n", p[0:10]);

    // Check if X or its neighbors are present in the p vector
    for (int i = 0; i <= 100; i++) {
        if (find(X-i) == 1) {
            cout << X-i << endl;
            exit(0);
        }
        if (find(X+i) == 1) {
            cout << X+i << endl;
            exit(0);
        }
    }

    // Output generation part is not present in the code
    // // OUTPUT GENERATION PART
    // int ans = 0;
    // cout << ans << endl;

    // If ans > 0, print "Yes" and exit; otherwise, print "No"
    // if (ans > 0) {
    //   cout << "Yes" << endl;
    // } else {
    //   cout << "No" << endl;
    // }
}

int main(int argc, char **argv) {
    // Parse command-line arguments
    for (int i = 1; i < argc; i++) {
        if (argv[i][0]!= '-') {
            break;
        }
        if (strcmp(argv[i], "-cpuprofile") == 0) {
            cpuprofile = argv[i+1];
        } else if (strcmp(argv[i], "-memprofile") == 0) {
            memprofile = argv[i+1];
        }
    }

    if (!cpuprofile.empty()) {
        // Write the CPU profile to the file
        ofstream f(cpuprofile);
        if (f.good()) {
            pprof::StartCPUProfile(&f);
            defer pprof::StopCPUProfile();
        } else {
            Logf("%v\n", "could not create CPU profile: " + cpuprofile);
            exit(1);
        }
    }

    solve(); // Call the solve function

    if (!memprofile.empty()) {
        // Write the memory profile to the file
        ofstream f(memprofile);
        if (f.good()) {
            pprof::WriteHeapProfile(&f);
        } else {
            Logf("%v\n", "could not create memory profile: " + memprofile);
            exit(1);
        }
    }
}

