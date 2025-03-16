#include <iostream>
#include <array>
#include <vector>
#include <iomanip>
#include <string>
#include <cmath>
#include <array>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

typedef  pair<int,int> P;

// Define an array to keep track of unavailable digits
bool d[10]={0};

// Define variables to store the number and the number of unavailable digits
int n,k;

// Define a boolean variable to check if the current number is valid
bool hantei=true;

int main(){
    // Read the initial number and the number of unavailable digits
    cin>>n>>k;

    // Mark the unavailable digits
    for(int i=0;i<k;++i){
        int a;
        cin>>a;
        d[a]=1;
    }

    // Loop until a valid number is found
    while(1){
        // Copy the current number to a temporary variable and initialize the check flag
        int x=n;
        hantei=1;

        // Check each digit of the number
        while(x){
            // If a digit is unavailable, set the check flag to false and break the loop
            if(d[x%10]){
                hantei=0;
                break;
            }
            // Move to the next digit
            x/=10;
        }

        // If the number is valid, print it and break the loop
        if(hantei){
            cout<<n<<endl;
            break;
        }

        // Increment the number and check again
        n++;
    }
}