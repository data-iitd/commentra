#include <iostream>
#include <string>

class Main {
public:
    long long A, B, K;
    long long x, y;

    Main() {
        std::cin >> A >> B >> K;
    }

    void calc() {
        x = A;
        y = B;
        x = A - K; // Subtract K from A to get the new value of x
        if (x < 0) {
            y = B + x; // Adjust B by the negative value of x
            x = 0; // Set x to 0 if it becomes negative
            if (y < 0) {
                y = 0; // Set y to 0 if it becomes negative
            }
        }
    }

    void showResult() {
        std::cout << x << " " << y << std::endl; // Print the final values of x and y
    }
};

int main() {
    Main ins;
    ins.calc();
    ins.showResult();
    return 0;
}

// <END-OF-CODE>
