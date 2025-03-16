#include <iostream>
#include <stack>
#include <cstdlib>

int main() {
    std::stack<int> S;
    std::string s;

    while (std::cin >> s) {
        if (s[0] == '+') {
            int b = S.top(); S.pop();
            int a = S.top(); S.pop();
            S.push(a + b);
        } else if (s[0] == '-') {
            int b = S.top(); S.pop();
            int a = S.top(); S.pop();
            S.push(a - b);
        } else if (s[0] == '*') {
            int b = S.top(); S.pop();
            int a = S.top(); S.pop();
            S.push(a * b);
        } else {
            S.push(std::atoi(s.c_str()));
        }
    }
    std::cout << S.top() << std::endl;
    return 0;
}

// <END-OF-CODE>
