
#include <iostream>
#include <vector>

using namespace std;

struct Box {
    int num;
    bool red;
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<Box> B(N);
    B[0] = {1, true};
    for (int i = 1; i < N; i++) {
        B[i] = {1, false};
    }

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        B[x - 1].moveTo(B[y - 1]);
    }

    int counter = 0;
    for (Box b : B) {
        if (b.red) {
            counter++;
        }
    }

    cout << counter << endl;

    return 0;
}

// Box class representing a box with a number and a color state
void Box::moveTo(Box& other) {
    // If this box is empty, do nothing
    if (num == 0) {
        return;
    }
    // If this box has one item, transfer it to the other box
    else if (num == 1) {
        num = 0;
        other.num++;
        // If this box is red, the other box becomes red
        if (red) {
            other.red = true;
        }
        red = false; // This box is no longer red
    }
    // If this box has more than one item, transfer one item to the other box
    else {
        num--;
        other.num++;
        // If this box is red, the other box becomes red
        if (red) {
            other.red = true;
        }
    }
}

// End of code