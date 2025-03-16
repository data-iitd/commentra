

#include<iostream>
#define N 2000
using namespace std;

int main(){
    int num1,math[N+1];

    // Initialize variables
    int a, num2, ans, sum = 0;
    int i, j;

    // Initialize math array with first element as 1
    math[0] = 1;

    // Read the number of integers to be input
    cout<<"Enter the number of integers to be input:\n";
    cin>>num1;

    // Read each integer and calculate its sum
    for(i=0;i<num1;i++){
        cout<<"Enter an integer:\n";
        cin>>a;

        // Add the current integer to the sum
        sum += a;

        // Mark all the previous numbers as visited
        for(j=sum-a;j>=0;j--){
            if(math[j]==1) math[j+a] = 1;
        }
    }

    // Read the number of integers to be checked
    cout<<"Enter the number of integers to be checked:\n";
    cin>>num2;

    // Check each integer and print the result
    for(i=0;i<num2;i++){
        cout<<"Enter an integer to check:\n";
        cin>>ans;

        // Check if the current integer is marked as visited
        if(math[ans]==1) cout<<"yes\n";
        else cout<<"no\n";
    }

    // Return 0 to indicate successful execution
    return 0;
}

