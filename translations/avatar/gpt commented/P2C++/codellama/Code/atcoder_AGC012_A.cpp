#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

// Function to read a list of integers from input
vector<int> readInts() {
    vector<int> A;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        A.push_back(x);
    }
    return A;
}

// Function to sort a list of integers in ascending order
void sort(vector<int> &A) {
    sort(A.begin(), A.end());
}

// Function to find the median of a list of integers
int median(vector<int> &A) {
    int n = A.size();
    if (n % 2 == 0) {
        return (A[n / 2 - 1] + A[n / 2]) / 2;
    } else {
        return A[n / 2];
    }
}

// Function to find the greatest common divisor of two integers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

// Function to find the least common multiple of two integers
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

// Function to find the greatest common divisor of a list of integers
int gcd(vector<int> &A) {
    int n = A.size();
    if (n == 1) {
        return A[0];
    } else {
        return gcd(A[0], gcd(A.begin() + 1, A.end()));
    }
}

// Function to find the least common multiple of a list of integers
int lcm(vector<int> &A) {
    int n = A.size();
    if (n == 1) {
        return A[0];
    } else {
        return lcm(A[0], lcm(A.begin() + 1, A.end()));
    }
}

// Function to find the greatest common divisor of two lists of integers
int gcd(vector<int> &A, vector<int> &B) {
    int n = A.size();
    int m = B.size();
    if (n == 1 && m == 1) {
        return gcd(A[0], B[0]);
    } else if (n == 1) {
        return gcd(A[0], gcd(B.begin() + 1, B.end()));
    } else if (m == 1) {
        return gcd(B[0], gcd(A.begin() + 1, A.end()));
    } else {
        return gcd(A[0], gcd(B[0], gcd(A.begin() + 1, A.end(), B.begin() + 1, B.end())));
    }
}

// Function to find the least common multiple of two lists of integers
int lcm(vector<int> &A, vector<int> &B) {
    int n = A.size();
    int m = B.size();
    if (n == 1 && m == 1) {
        return lcm(A[0], B[0]);
    } else if (n == 1) {
        return lcm(A[0], lcm(B.begin() + 1, B.end()));
    } else if (m == 1) {
        return lcm(B[0], lcm(A.begin() + 1, A.end()));
    } else {
        return lcm(A[0], lcm(B[0], lcm(A.begin() + 1, A.end(), B.begin() + 1, B.end())));
    }
}

// Function to find the greatest common divisor of a list of lists of integers
int gcd(vector<vector<int>> &A) {
    int n = A.size();
    if (n == 1) {
        return gcd(A[0]);
    } else {
        return gcd(A[0], gcd(A.begin() + 1, A.end()));
    }
}

// Function to find the least common multiple of a list of lists of integers
int lcm(vector<vector<int>> &A) {
    int n = A.size();
    if (n == 1) {
        return lcm(A[0]);
    } else {
        return lcm(A[0], lcm(A.begin() + 1, A.end()));
    }
}

// Function to find the greatest common divisor of two lists of lists of integers
int gcd(vector<vector<int>> &A, vector<vector<int>> &B) {
    int n = A.size();
    int m = B.size();
    if (n == 1 && m == 1) {
        return gcd(A[0], B[0]);
    } else if (n == 1) {
        return gcd(A[0], gcd(B.begin() + 1, B.end()));
    } else if (m == 1) {
        return gcd(B[0], gcd(A.begin() + 1, A.end()));
    } else {
        return gcd(A[0], gcd(B[0], gcd(A.begin() + 1, A.end(), B.begin() + 1, B.end())));
    }
}

// Function to find the least common multiple of two lists of lists of integers
int lcm(vector<vector<int>> &A, vector<vector<int>> &B) {
    int n = A.size();
    int m = B.size();
    if (n == 1 && m == 1) {
        return lcm(A[0], B[0]);
    } else if (n == 1) {
        return lcm(A[0], lcm(B.begin() + 1, B.end()));
    } else if (m == 1) {
        return lcm(B[0], lcm(A.begin() + 1, A.end()));
    } else {
        return lcm(A[0], lcm(B[0], lcm(A.begin() + 1, A.end(), B.begin() + 1, B.end())));
    }
}

// Function to find the greatest common divisor of a list of lists of lists of integers
int gcd(vector<vector<vector<int>>> &A) {
    int n = A.size();
    if (n == 1) {
        return gcd(A[0]);
    } else {
        return gcd(A[0], gcd(A.begin() + 1, A.end()));
    }
}

// Function to find the least common multiple of a list of lists of lists of integers
int lcm(vector<vector<vector<int>>> &A) {
    int n = A.size();
    if (n == 1) {
        return lcm(A[0]);
    } else {
        return lcm(A[0], lcm(A.begin() + 1, A.end()));
    }
}

// Function to find the greatest common divisor of two lists of lists of lists of integers
int gcd(vector<vector<vector<int>>> &A, vector<vector<vector<int>>> &B) {
    int n = A.size();
    int m = B.size();
    if (n == 1 && m == 1) {
        return gcd(A[0], B[0]);
    } else if (n == 1) {
        return gcd(A[0], gcd(B.begin() + 1, B.end()));
    } else if (m == 1) {
        return gcd(B[0], gcd(A.begin() + 1, A.end()));
    } else {
        return gcd(A[0], gcd(B[0], gcd(A.begin() + 1, A.end(), B.begin() + 1, B.end())));
    }
}

// Function to find the least common multiple of two lists of lists of lists of integers
int lcm(vector<vector<vector<int>>> &A, vector<vector<vector<int>>> &B) {
    int n = A.size();
    int m = B.size();
    if (n == 1 && m == 1) {
        return lcm(A[0], B[0]);
    } else if (n == 1) {
        return lcm(A[0], lcm(B.begin() + 1, B.end()));
    } else if (m == 1) {
        return lcm(B[0], lcm(A.begin() + 1, A.end()));
    } else {
        return lcm(A[0], lcm(B[0], lcm(A.begin() + 1, A.end(), B.begin() + 1, B.end())));
    }
}

// Function to find the greatest common divisor of a list of lists of lists of lists of integers
int gcd(vector<vector<vector<vector<int>>>> &A) {
    int n = A.size();
    if (n == 1) {
        return gcd(A[0]);
    } else {
        return gcd(A[0], gcd(A.begin() + 1, A.end()));
    }
}

// Function to find the least common multiple of a list of lists of lists of lists of integers
int lcm(vector<vector<vector<vector<int>>>> &A) {
    int n = A.size();
    if (n == 1) {
        return lcm(A[0]);
    } else {
        return lcm(A[0], lcm(A.begin() + 1, A.end()));
    }
}

// Function to find the greatest common divisor of two lists of lists of lists of lists of integers
int gcd(vector<vector<vector<vector<int>>>> &A, vector<vector<vector<vector<int>>>> &B) {
    int n = A.size();
    int m = B.size();
    if (n == 1 && m == 1) {
        return gcd(A[0], B[0]);
    } else if (n == 1) {
        return gcd(A[0], gcd(B.begin() + 1, B.end()));
    } else if (m == 1) {
        return gcd(B[0], gcd(A.begin() + 1, A.end()));
    } else {
        return gcd(A[0], gcd(B[0], gcd(A.begin() + 1, A.end(), B.begin() + 1, B.end())));
    }
}

// Function to find the least common multiple of two lists of lists of lists of lists of integers
int lcm(vector<vector<vector<vector<int>>>> &A, vector<vector<vector<vector<int>>>> &B) {
    int n = A.size();
    int m = B.size();
    if (n == 1 && m == 1) {
        return lcm(A[0], B[0]);
    } else if (n == 1) {
        return lcm(A[0], lcm(B.begin() + 1, B.end()));
    } else if (m == 1) {
        return lcm(B[0], lcm(A.begin() + 1, A.end()));
    } else {
        return lcm(A[0], lcm(B[0], lcm(A.begin() + 1, A.end(), B.begin() + 1, B.end())));
    }
}

// Function to find the greatest common divisor of a list of lists of lists of lists of lists of integers
int gcd(vector<vector<vector<vector<vector<int>>>>> &A) {
    int n = A.size();
    if (n == 1) {
        return gcd(A[0]);
    } else {
        return gcd(A[0], gcd(A.begin() + 1, A.end()));
    }
}

// Function to find the least common multiple of a list of lists of lists of lists of lists of integers
int lcm(vector<vector<vector<vector<vector<int>>>>> &A) {
    int n = A.size();
    if (n == 1) {
        return lcm(A[0]);
    } else {
        return lcm(A[0], lcm(A.begin() + 1, A.end()));
    }
}

// Function to find the greatest common divisor of two lists of lists of lists of lists of lists of integers
int gcd(vector<vector<vector<vector<vector<int>>>>> &A, vector<vector<vector<vector<vector<int>>>>> &B) {
    int n = A.size();
    int m = B.size();
    if (n == 1 && m == 1) {
        return gcd(A[0], B[0]);
    } else if (n == 1) {
        return gcd(A[0], gcd(B.begin() + 1, B.end()));
    } else if (m == 1) {
        return gcd(B[0], gcd(A.begin() + 1, A.end()));
    } else {
        return gcd(A[0], gcd(B[0], gcd(A.begin() + 1, A.end(), B.begin() + 1, B.end())));
    }
}

// Function to find the least common multiple of two lists of lists of lists of lists of lists of integers
int lcm(vector<vector<vector<vector<vector<int>>>>> &A, vector<vector<vector<vector<vector<int>>>>> &B) {
    int n = A.size();
    int m = B.size();
    if (n == 1 && m == 1) {
        return lcm(A[0], B[0]);
    } else if (n == 1) {
        return lcm(A[0], lcm(B.begin() + 1, B.end()));
    } else if (m == 1) {
        return lcm(B[0], lcm(A.begin() + 1, A.end()));
    } else {
        return lcm(A[0], lcm(B[0], lcm(A.begin() + 1, A.end(), B.begin() + 1, B.end())));
    }
}

// Function to find the greatest common divisor of a list of lists of lists of lists of lists of lists of integers
int gcd(vector<vector<vector<vector<vector<vector<int>>>>>> &A) {
    int n = A.size();
    if (n == 1) {
        return gcd(A[0]);
    } else {
        return gcd(A[0], gcd(A.begin() + 1, A.end()));
    }
}

// Function to find the least common multiple of a list of lists of lists of lists of lists of lists of integers
int lcm(vector<vector<vector<vector<vector<vector<int>>>>>> &A) {
    int n = A.size();
    if (n == 1) {
        return lcm(A[0]);
    } else {
        return lcm(A[0], lcm(A.begin() + 1, A.end()));
    }
}

// Function to find the greatest common divisor of two lists of lists of lists of lists of lists of lists of integers
int gcd(vector<vector<vector<vector<vector<vector<int>>>>>> &A, vector<vector<vector<vector<vector<vector<int>>>>>> &B) {
    int n = A.size();
    int m = B.siz