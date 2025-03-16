#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class FastReader {
    public:
        FastReader() {}

        int nextInt() {
            int x;
            cin >> x;
            return x;
        }
};

int main() {
    FastReader sc;
    int x = sc.nextInt();
    int count = 0;
    int tmp = x;
    x = 0;

    while (x != 360) {
        x += tmp;
        if (x > 360) {
            x -= 360;
        }
        count++;
    }

    cout << count << endl;
    return 0;
}

// <END-OF-CODE>
