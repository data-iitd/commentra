#include <iostream>
using namespace std;

int main(void){
    // Declare variables to store loop index, transaction type, and number of items
    int i, t, n;

    // Loop through four transactions
    for(i = 0; i < 4; i++){
        // Read the transaction type and number of items from standard input
        cin >> t >> n;

        // Check the transaction type and calculate the total cost
        if(t == 1){
            cout << 6000 * n << endl; // If transaction type is 1, calculate cost for 6000 per item
        }
        else if(t == 2){
            cout << 4000 * n << endl; // If transaction type is 2, calculate cost for 4000 per item
        }
        else if(t == 3){
            cout << 3000 * n << endl; // If transaction type is 3, calculate cost for 3000 per item
        }
        else if(t == 4){
            cout << 2000 * n << endl; // If transaction type is 4, calculate cost for 2000 per item
        }
    }
}