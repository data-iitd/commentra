#include<iostream>
#include<stack>

using namespace std;

// Function to push an element onto the stack
void push(int x){
 // Increment the top index and push the element
 top++;
 S.push(x);
}

// Function to pop an element from the stack
int pop(){
 // Return the top element and decrement the top index
 return S.top();
}

// Main function
int main(){
 // Initialize variables
 int a, b;
 char s[200];

 // Initialize stack top to 0
 top = 0;

 // Read input until end of file
 while(cin>>s){
 // Check if the input is an operator or a number
 if(s[0]=='+' || s[0]=='-' || s[0]=='*'){
 // Pop the top two elements from the stack
 b = pop();
 a = pop();

 // Perform the operation and push the result back onto the stack
 if(s[0]=='+'){
 push(a+b);
 }else if(s[0]=='-'){
 push(a-b);
 }else{ // s[0]=='*'
 push(a*b);
 }
 }else{ // Input is a number
 // Push the number directly onto the stack
 push(atoi(s));
 }
 }

 // Print the final result
 cout<<pop()<<endl;

 // Return 0 to indicate successful execution
 return 0;
}

