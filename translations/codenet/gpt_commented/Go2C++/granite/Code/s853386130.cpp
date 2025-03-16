

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// Define the mod constant
const int mod = 1000000007;

// Define the INF constant
const int INF = 1000000007;

// Define the min function
int min(int a, int b) {
    return a < b? a : b;
}

// Define the max function
int max(int a, int b) {
    return a > b? a : b;
}

// Define the abs function
int abs(int a) {
    return a < 0? -a : a;
}

// Define the primeFactor function
map<int, int> primeFactor(int x) {
    map<int, int> res;
    for (int i = 2; i * i <= x; i++) {
        while (x % i == 0) {
            res[i]++;
            x /= i;
        }
    }
    if (x!= 1) {
        res[x] = 1;
    }
    return res;
}

// Define the divisor function
vector<int> divisor(int x) {
    vector<int> res;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            res.push_back(i);
            if (i!= x / i) {
                res.push_back(x / i);
            }
        }
    }
    return res;
}

// Define the gcd function
int gcd(int x, int y) {
    if (y == 0) {
        return x;
    }
    return gcd(y, x % y);
}

// Define the lcm function
int lcm(int x, int y) {
    return x / gcd(x, y) * y;
}

// Define the reverseString function
string reverseString(string s) {
    string res = "";
    for (int i = s.length() - 1; i >= 0; i--) {
        res += s[i];
    }
    return res;
}

// Define the pow function
int pow(int a, int n) {
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res *= a;
    }
    return res;
}

// Define the Queue structure
struct Queue {
    vector<int> data;
    int front, rear;
    Queue() {
        front = rear = 0;
    }
    bool empty() {
        return front == rear;
    }
    void push(int x) {
        data.push_back(x);
        rear++;
    }
    int pop() {
        int res = data[front];
        front++;
        return res;
    }
};

// Define the Stack structure
struct Stack {
    vector<int> data;
    int top;
    Stack() {
        top = -1;
    }
    bool empty() {
        return top == -1;
    }
    void push(int x) {
        data.push_back(x);
        top++;
    }
    int pop() {
        int res = data[top];
        top--;
        return res;
    }
};

// Define the intHeap structure
struct intHeap {
    vector<int> data;
    intHeap() {}
    bool empty() {
        return data.empty();
    }
    void push(int x) {
        data.push_back(x);
        int i = data.size() - 1;
        while (i > 0 && data[i] > data[(i - 1) / 2]) {
            swap(data[i], data[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
    int pop() {
        int res = data[0];
        data[0] = data[data.size() - 1];
        data.pop_back();
        int i = 0;
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smallest = i;
            if (left < data.size() && data[left] < data[smallest]) {
                smallest = left;
            }
            if (right < data.size() && data[right] < data[smallest]) {
                smallest = right;
            }
            if (smallest == i) {
                break;
            }
            swap(data[i], data[smallest]);
            i = smallest;
        }
        return res;
    }
};

// Define the point structure
struct point {
    int x, y;
};

// Define the points structure
struct points {
    vector<point> data;
    bool operator()(const point& a, const point& b) {
        return a.x < b.x;
    }
};

int main() {
    // Your code here
    return 0;
}

