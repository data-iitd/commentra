-----

#include <bits/stdc++.h>
using namespace std;

// Function to take input from standard input
string input() {
    string s;
    getline(cin, s);
    return s;
}

// Function to read an integer
int I() {
    return atoi(input().c_str());
}

// Function to read a list of integers
vector<int> III() {
    string s = input();
    vector<int> v;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] =='') continue;
        int x = 0;
        while (i < s.size() && s[i]!='') {
            x = x * 10 + (s[i] - '0');
            i++;
        }
        v.push_back(x);
    }
    return v;
}

// Function to read a list of lists (2D array)
vector<vector<int>> Line(int N) {
    vector<vector<int>> v(N);
    for (int i = 0; i < N; i++) {
        v[i] = III();
    }
    return v;
}

// Function to print a list of integers
void P(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        if (i) cout << " ";
        cout << v[i];
    }
    cout << endl;
}

// Function to print a list of lists (2D array)
void P(vector<vector<int>> v) {
    for (int i = 0; i < v.size(); i++) {
        P(v[i]);
    }
}

// Function to print a 2D array
void P(int N, int M, int A[][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j) cout << " ";
            cout << A[i][j];
        }
        cout << endl;
    }
}

// Function to print a 2D array
void P(int N, int M, vector<vector<int>> A) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j) cout << " ";
            cout << A[i][j];
        }
        cout << endl;
    }
}

// Function to print a 2D array
void P(int N, int M, int A[][M], int L, int K) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j) cout << " ";
            cout << A[(i + L) % N][(j + K) % M];
        }
        cout << endl;
    }
}

// Function to print a 2D array
void P(int N, int M, vector<vector<int>> A, int L, int K) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j) cout << " ";
            cout << A[(i + L) % N][(j + K) % M];
        }
        cout << endl;
    }
}

// Function to print a 2D array
void P(int N, int M, int A[][M], int L, int K, int R, int B) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j) cout << " ";
            cout << A[(i + L) % N][(j + K) % M];
        }
        cout << endl;
    }
}

// Function to print a 2D array
void P(int N, int M, vector<vector<int>> A, int L, int K, int R, int B) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j) cout << " ";
            cout << A[(i + L) % N][(j + K) % M];
        }
        cout << endl;
    }
}

// Function to print a 2D array
void P(int N, int M, int A[][M], int L, int K, int R, int B, int X, int Y) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j) cout << " ";
            cout << A[(i + L) % N][(j + K) % M];
        }
        cout << endl;
    }
}

// Function to print a 2D array
void P(int N, int M, vector<vector<int>> A, int L, int K, int R, int B, int X, int Y) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j) cout << " ";
            cout << A[(i + L) % N][(j + K) % M];
        }
        cout << endl;
    }
}

// Function to print a 2D array
void P(int N, int M, int A[][M], int L, int K, int R, int B, int X, int Y, int Z) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j) cout << " ";
            cout << A[(i + L) % N][(j + K) % M];
        }
        cout << endl;
    }
}

// Function to print a 2D array
void P(int N, int M, vector<vector<int>> A, int L, int K, int R, int B, int X, int Y, int Z) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j) cout << " ";
            cout << A[(i + L) % N][(j + K) % M];
        }
        cout << endl;
    }
}

// Function to print a 2D array
void P(int N, int M, int A[][M], int L, int K, int R, int B, int X, int Y, int Z, int W) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j) cout << " ";
            cout << A[(i + L) % N][(j + K) % M];
        }
        cout << endl;
    }
}

// Function to print a 2D array
void P(int N, int M, vector<vector<int>> A, int L, int K, int R, int B, int X, int Y, int Z, int W) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j) cout << " ";
            cout << A[(i + L) % N][(j + K) % M];
        }
        cout << endl;
    }
}

// Function to print a 2D array
void P(int N, int M, int A[][M], int L, int K, int R, int B, int X, int Y, int Z, int W, int V) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j) cout << " ";
            cout << A[(i + L) % N][(j + K) % M];
        }
        cout << endl;
    }
}

// Function to print a 2D array
void P(int N, int M, vector<vector<int>> A, int L, int K, int R, int B, int X, int Y, int Z, int W, int V) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j) cout << " ";
            cout << A[(i + L) % N][(j + K) % M];
        }
        cout << endl;
    }
}

// Function to print a 2D array
void P(int N, int M, int A[][M], int L, int K, int R, int B, int X, int Y, int Z, int W, int V, int U) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j) cout << " ";
            cout << A[(i + L) % N][(j + K) % M];
        }
        cout << endl;
    }
}

// Function to print a 2D array
void P(int N, int M, vector<vector<int>> A, int L, int K, int R, int B, int X, int Y, int Z, int W, int V, int U) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j) cout << " ";
            cout << A[(i + L) % N][(j + K) % M];
        }
        cout << endl;
    }
}

// Function to print a 2D array
void P(int N, int M, int A[][M], int L, int K, int R, int B, int X, int Y, int Z, int W, int V, int U, int T) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j) cout << " ";
            cout << A[(i + L) % N][(j + K) % M];
        }
        cout << endl;
    }
}

// Function to print a 2D array
void P(int N, int M, vector<vector<int>> A, int L, int K, int R, int B, int X, int Y, int Z, int W, int V, int U, int T) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j) cout << " ";
            cout << A[(i + L) % N][(j + K) % M];
        }
        cout << endl;
    }
}

// Function to print a 2D array
void P(int N, int M, int A[][M], int L, int K, int R, int B, int X, int Y, int Z, int W, int V, int U, int T, int S) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j) cout << " ";
            cout << A[(i + L) % N][(j + K) % M];
        }
        cout << endl;
    }
}

// Function to print a 2D array
void P(int N, int M, vector<vector<int>> A, int L, int K, int R, int B, int X, int Y, int Z, int W, int V, int U, int T, int S) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j) cout << " ";
            cout << A[(i + L) % N][(j + K) % M];
        }
        cout << endl;
    }
}

// Function to print a 2D array
void P(int N, int M, int A[][M], int L, int K, int R, int B, int X, int Y, int Z, int W, int V, int U, int T, int S, int P) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j) cout << " ";
            cout << A[(i + L) % N][(j + K) % M];
        }
        cout << endl;
    }
}

// Function to print a 2D array
void P(int N, int M, vector<vector<int>> A, int L, int K, int R, int B, int X, int Y, int Z, int W, int V, int U, int T, int S, int P) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j) cout << " ";
            cout << A[(i + L) % N][(j + K) % M];
        }
        cout << endl;
    }
}

// Function to print a 2D array
void P(int N, int M, int A[][M], int L, int K, int R, int B, int X, int Y, int Z, int W, int V, int U, int T, int S, int P, int O) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j) cout << " ";
            cout << A[(i + L) % N][(j + K) % M];
        }
        cout << endl;
    }
}

// Function to print a 2D array
void P(int N, int M, vector<vector<int>> A, int L, int K, int R, int B, int X, int Y, int Z, int W, int V, int U, int T, int S, int P, int O) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j) cout << " ";
            cout << A[(i + L) % N][(j + K) % M];
        }
        cout << endl;
    }
}

// Function to print a 2D array
void P(int N, int M, int A[][M], int L, int K, int R, int B, int X, int Y, int Z, int W, int V, int U, int T, int S, int P, int O, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j) cout << " ";
            cout << A[(i + L) % N][(j + K) % M];
        }
        cout << endl;
    }
}

// Function to print a 2D array
void P(int N, int M, vector<vector<int>> A, int L, int K, int R, int B, int X, int Y, int Z, int W, int V, int U, int T, int S, int P, int O, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j) cout << " ";
            cout << A[(i + L) % N][(j + K) % M];
        }
        cout << endl;
    }
}

// Function to print a 2D array
void P(int N, int M, int A[][M], int L, int K, int R, int B, int X, int Y, int Z, int W, int V, int U, int T, int S, int P, int O, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j) cout << " ";
            cout << A[(i + L) % N][(j + K) % M];
        }
        cout << endl;
    }
}

// Function to print a 2D array
void P(int N, int M, vector<vector<