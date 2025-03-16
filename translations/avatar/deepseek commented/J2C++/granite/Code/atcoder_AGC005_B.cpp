
#include <iostream> // Including the necessary libraries
#include <vector>
#include <deque>

using namespace std;

int main() {
    int N; // Declaring the variable N
    cin >> N; // Reading the number of elements N
    
    vector<int> a(N); // Initializing the vector a with size N
    
    // Reading N elements and storing them in the vector a
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    
    // Initializing vectors to store the distances to the nearest smaller elements
    vector<int> leftl(N);
    vector<int> rightl(N);
    
    // Using a deque to find the nearest smaller element to the right
    deque<int> que;
    int index = 0;
    while (index < N) {
        while (!que.empty() && a[que.front()] > a[index]) {
            int ind = que.front();
            que.pop_front();
            rightl[ind] = index - ind - 1; // Calculating the distance
        }
        que.push_front(index++); // Adding the current index to the deque
    }
    while (!que.empty()) {
        int ind = que.front();
        que.pop_front();
        rightl[ind] = N - ind - 1; // Calculating the distance for remaining elements
    }
    
    // Using a deque to find the nearest smaller element to the left
    index = N - 1;
    while (index >= 0) {
        while (!que.empty() && a[que.front()] > a[index]) {
            int ind = que.front();
            que.pop_front();
            leftl[ind] = ind - index - 1; // Calculating the distance
        }
        que.push_front(index--); // Adding the current index to the deque
    }
    while (!que.empty()) {
        int ind = que.front();
        que.pop_front();
        leftl[ind] = ind - index - 1; // Calculating the distance for remaining elements
    }
    
    // Calculating the result by summing up the products
    long ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += (long) a[i] * (leftl[i] + 1) * (rightl[i] + 1);
    }
    
    // Printing the result
    cout << ans << endl; // Printing the result
    
    return 0; // Returning 0 to indicate successful execution
}

