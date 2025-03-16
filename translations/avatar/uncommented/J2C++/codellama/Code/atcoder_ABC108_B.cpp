
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int *revpos(int *p, int *q) {
    int *vec = new int[2];
    for (int i = 0; i < 2; i++) {
        vec[i] = p[i] - q[i];
    }
    int tmp = 0;
    tmp = vec[0];
    vec[0] = vec[1];
    vec[1] = -tmp;
    int *newpos = new int[2];
    for (int i = 0; i < 2; i++) {
        newpos[i] = q[i] + vec[i];
    }
    return newpos;
}

int main() {
    int *input = new int[4];
    for (int i = 0; i < 4; i++) {
        cin >> input[i];
    }
    int **position = new int*[4];
    for (int i = 0; i < 4; i++) {
        position[i] = new int[2];
    }
    position[0][0] = input[0];
    position[0][1] = input[1];
    position[1][0] = input[2];
    position[1][1] = input[3];
    position[2] = revpos(position[0], position[1]);
    position[3] = revpos(position[1], position[2]);
    if (position[0] == revpos(position[2], position[3])) {
        cout << "OK" << endl;
    }
    int *output = new int[4];
    for (int i = 0; i < 4; i++) {
        output[i] = position[i][0];
    }
    for (int i = 0; i < 4; i++) {
        cout << output[i] << endl;
    }
    return 0;
}

