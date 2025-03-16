#include <bits/stdc++.h>
using namespace std;

int main() {
    // Step 1: Read the input value N, which represents the number of elements.
    int N;
    cin >> N;

    // Step 2: Create a map idorder to store the elements and their corresponding positions.
    map < int, int > idorder;

    // Step 3: Read each element and store its value and position in the map.
    for (int i = 1; i <= N; i++) {
        int A;
        cin >> A;
        idorder[A] = i;
    }

    // Step 4: Print the positions of the elements in the order they were read.
    for (int i = 1; i <= N; i++) {
        cout << idorder[i] << " ";
    }
}

