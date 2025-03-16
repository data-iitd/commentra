
#include<iostream>
#include<algorithm>
using namespace std;

// Initialize variables a, b, and c with user input
int main(){
 int a, b, c;
 cin >> a >> b >> c;

 // Check if a is greater than b and swap if necessary
 if (a > b) {
 swap(a, b);
 }

 // Check if b is greater than c and swap if necessary
 if (b > c) {
 swap(b, c);
 }

 // Check if a is greater than b again and swap if necessary
 if (a > b) {
 swap(a, b);
 }

 // Print the sorted values of a, b, and c
 cout << a << " " << b << " " << c << endl;
}

