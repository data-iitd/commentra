

#include <bits/stdc++.h>

using namespace std;

// Define constants
const int magic = 1000000007;

// Define flags for profiling
bool cpuprofile = false;
bool memprofile = false;

// Define variables
int N;
int p[200000];

// Function to check if a number exists in the array p
int find(int n) {
  for (int i = 0; i < N; i++) {
    if (n == p[i]) {
      return 0;
    }
  }
  return 1;
}

// Function to solve the problem
void solve() {
  int X, N;
  cin >> X >> N;
  for (int i = 0; i < N; i++) {
    cin >> p[i];
  }

  // Search for the closest number to X in the array p
  for (int i = 0; i <= 100; i++) {
    if (find(X-i) == 1) {
      cout << X-i << endl;
      return;
    }
    if (find(X+i) == 1) {
      cout << X+i << endl;
      return;
    }
  }
}

// Main function
int main() {
  // Parse command line arguments for profiling
  for (int i = 0; i < argc; i++) {
    if (strcmp(argv[i], "--cpuprofile") == 0) {
      cpuprofile = true;
    }
    if (strcmp(argv[i], "--memprofile") == 0) {
      memprofile = true;
    }
  }

  // Start CPU profiling if flag is set
  if (cpuprofile) {
    ofstream f("cpuprofile.out");
    pprof::StartCPUProfile(&f);
  }

  // Solve the problem
  solve();

  // Stop CPU profiling if flag is set
  if (cpuprofile) {
    pprof::StopCPUProfile();
  }

  // Start memory profiling if flag is set
  if (memprofile) {
    ofstream f("memprofile.out");
    pprof::WriteHeapProfile(&f);
  }

  return 0;
}

