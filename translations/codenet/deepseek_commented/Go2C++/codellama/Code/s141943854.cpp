
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    string sage;
    cin >> sage;

    switch (sage[0]) {
        case '1':
            cout << "Hello World" << endl;
            break;
        case '2':
            int sum = 0;
            for (int i = 0; i < 2; i++) {
                string num;
                cin >> num;
                sum += atoi(num.c_str());
            }
            cout << sum << endl;
            break;
    }

    return 0;
}

