#include<iostream>
using namespace std;

int main(){
    int a, b; // Declare two integer variables a and b
    
    cin >> a; // Take an integer input from the user and store it in variable a
    
    cout << a/(60*60) << ":"<< a%(60*60)/60 << ":" << a%(60*60)%60 << endl; // Calculate and output the hours, minutes, and seconds
    
    return 0; // Return 0 to indicate successful execution
}

