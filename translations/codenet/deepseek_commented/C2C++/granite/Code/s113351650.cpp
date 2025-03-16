
#include<iostream>
using namespace std;
int main(void){
  
  // Declare an integer variable to store the input value.
  int x;
  
  // Read an integer input from the user and store it in the variable x.
  cin >> x;
  
  // Check the value of x and print 1 or 0 based on the value of x.
  if (x == 0) {
    cout << "1" << endl;
  }
  if (x == 1) {
    cout << "0" << endl;
  }
  
  // Return 0 to indicate successful execution of the program.
  return 0;
}
