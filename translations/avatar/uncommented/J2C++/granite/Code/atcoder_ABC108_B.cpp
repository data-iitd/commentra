
#include <iostream>
using namespace std;

int revpos(int p[], int q[]) {
    int vec[2] = {0, 0};
    for (int i = 0; i < 2; i++) {
        vec[i] = p[i] - q[i];
    }
    int tmp = 0;
    tmp = vec[0];
    vec[0] = vec[1];
    vec[1] = -tmp;
    int newpos[2] = {0, 0};
    for (int i = 0; i < 2; i++) {
        newpos[i] = q[i] + vec[i];
    }
    return newpos[0];
}

int main() {
    int input[4] = {0, 0, 0, 0};
    for (int i = 0; i < 4; i++) {
        cin >> input[i];
    }
    int position[4][2] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};
    position[0][0] = input[0];
    position[0][1] = input[1];
    position[1][0] = input[2];
    position[1][1] = input[3];
    position[2][0] = revpos(position[0], position[1]);
    position[2][1] = revpos(position[1], position[2]);
    position[3][0] = revpos(position[2], position[3]);
    position[3][1] = revpos(position[3], position[2]);
    if (position[0][0] == revpos(position[2], position[3])) {
        cout << "OK" << endl;
    }
    int output[4] = {position[2][0], position[2][1], position[3][0], position[3][1]};
    for (int i = 0; i < 4; i++) {
        cout << output[i] << endl;
    }
    return 0;
}
