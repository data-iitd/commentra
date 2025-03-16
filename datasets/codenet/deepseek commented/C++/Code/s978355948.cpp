#include <iostream>
#include <vector>

using namespace std;

int main(){
    // Read the number of elements N and the maximum distance X
    int N, X;
    cin >> N >> X;
    
    // Read the lengths of the segments into a vector L
    vector<int> L(N);
    for(int i = 0; i < N; i++)
        cin >> L[i];
    
    // Initialize the index i and the distance d
    int i;
    int d = 0;
    
    // Loop through the segments to calculate the total distance
    for(i = 0; i < N; i++){
        // Add the current segment length to the total distance
        d = d + L[i];
        
        // If the total distance exceeds X, break the loop
        if(d > X)
            break;
    }

    // Output the number of segments used
    cout << i+1 << endl;
}
