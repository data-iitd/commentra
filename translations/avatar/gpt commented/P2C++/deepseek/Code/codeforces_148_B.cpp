#include <iostream>
using namespace std;

int main() {
    int princess, dragon, t, f, c;
    cin >> princess >> dragon >> t >> f >> c;

    if (dragon <= princess) {
        cout << 0 << endl;
        return 0;
    }

    int result = 0;
    double position = t * princess;

    position += princess * position / (dragon - princess);

    while (position < c) {
        result++;
        position += princess * position / dragon;
        position += princess * f;
        position += princess * position / (dragon - princess);
    }

    cout << result << endl;
    return 0;
}

