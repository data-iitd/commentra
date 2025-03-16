#include <iostream>
#include <vector>

class Main {
public:
    // Constructor initializes the output stream
    Main() {}

    void run() {
        // Main method reads two integers, n and k, from the input
        int n, k;
        std::cin >> n >> k;
        std::vector<int> bb(n);
        for (int i = 0; i < n; i++) {
            std::cin >> bb[i];
        }

        // Initialize an array to store the result
        std::vector<int> aa(n);
        int m = 0;

        // Process the array bb in reverse order
        for (int a = n - 1; a >= 0; a--) {
            int j = 0;
            while (bb[a] > 0) {
                if (aa[j] >= a + k) {
                    bb[a]--;
                }
                j++;
            }
            for (int j_ = m++; j_ > j; j_--) {
                aa[j_] = aa[j_ - 1];
            }
            aa[j] = a;
        }

        // Print the contents of the array aa, incrementing each element by 1
        for (int i = 0; i < n; i++) {
            std::cout << aa[i] + 1 << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Main o;
    o.run();
    return 0;
}

// <END-OF-CODE>
