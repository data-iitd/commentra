#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> as(N+1, 0); // Create a vector to keep track of the occurrences of each element
    for (int i = 0; i < K; i++) {
        int d;
        cin >> d;
        for (int j = 0; j < d; j++) {
            int a;
            cin >> a;
            as[a]++;
        }
    }
    int ans = 0; // Initialize the answer variable to count unchosen elements
    for (int i = 1; i <= N; i++) {
        if (as[i] == 0) {
            ans++; // Increment the answer if an element was not chosen
        }
    }
    cout << ans << endl; // Print the number of unchosen elements
    return 0;
}

