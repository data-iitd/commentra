#include <iostream>
#include <cstdlib>
#include <cstring>

void push(int);
int pop();

int top;
int kinbo[1000];

int main() {
    int chonda, yamagami;
    top = 0;
    char null[100];

    while (std::cin >> null) {
        if (null[0] == '+') {
            chonda = pop();
            yamagami = pop();
            push(chonda + yamagami);
        } else if (null[0] == '-') {
            yamagami = pop();
            chonda = pop();
            push(chonda - yamagami);
        } else if (null[0] == '*') {
            chonda = pop();
            yamagami = pop();
            push(chonda * yamagami);
        } else {
            push(atoi(null));
        }
    }

    std::cout << pop() << std::endl;

    return 0;
}

void push(int chonda) {
    kinbo[++top] = chonda;
}

int pop() {
    top--;
    return kinbo[top + 1];
}

// <END-OF-CODE>
