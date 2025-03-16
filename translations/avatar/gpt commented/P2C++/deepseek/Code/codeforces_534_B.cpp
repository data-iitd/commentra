#include <iostream>
#include <vector>
using namespace std;

int main() {
    int v1, v2, t, d;
    cin >> v1 >> v2;
    cin >> t >> d;

    vector<int> velocities(t);
    velocities[0] = v1;
    for (int i = 1; i < t; ++i) {
        if (velocities[i - 1] - v2 > (t - i - 1) * d) {
            velocities[i] = (t - i - 1) * d + v2;
        } else {
            velocities[i] = velocities[i - 1] + d;
        }
    }

    int distance = 0;
    for (int i = 0; i < t; ++i) {
        distance += velocities[i];
    }

    cout << distance << endl;
    return 0;
}
