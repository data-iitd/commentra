#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(){
    stack<int> S; // Stack to hold integers
    string s; // String to hold the input

    // Read input until EOF
    while(cin >> s){
        // Check for addition operation
        if(s == "+"){
            int b = S.top(); S.pop(); // Pop the top two values from the stack
            int a = S.top(); S.pop();
            S.push(a + b); // Push the result of addition back onto the stack
        }
        // Check for subtraction operation
        else if(s == "-"){
            int b = S.top(); S.pop(); // Pop the top two values from the stack
            int a = S.top(); S.pop();
            S.push(a - b); // Push the result of subtraction back onto the stack
        }
        // Check for multiplication operation
        else if(s == "*"){
            int b = S.top(); S.pop(); // Pop the top two values from the stack
            int a = S.top(); S.pop();
            S.push(a * b); // Push the result of multiplication back onto the stack
        }
        // If the input is a number, convert it and push onto the stack
        else{
            S.push(stoi(s)); // Convert string to integer and push onto the stack
        }
    }
    
    // Print the final result which is the last remaining value in the stack
    cout << S.top() << endl;
    return 0; // Exit the program
}
