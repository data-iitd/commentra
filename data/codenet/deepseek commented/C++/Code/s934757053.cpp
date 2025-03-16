#include <iostream>
using namespace std;

int main(){
    int A, B;
    int ans=0;
    int out = 1; // Initialize out to 1

    cin >> A >> B; // Read two integers A and B from the standard input

    while(out<B){ // Continue the loop as long as out is less than B
        out--; // Decrement out by 1
        out += A; // Increment out by A
        ans++; // Increment ans by 1
    }
    cout << ans << endl; // Print the value of ans to the standard output
    return 0;
}
