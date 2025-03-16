
#include<iostream> // Including the standard input output library

using namespace std; // Using the standard namespace

int main(){ // Starting the main function
  int a,b,c; // Declaring three integer variables a, b, and c
  cin>>a>>b>>c; // Reading three integers from the standard input and storing them in variables a, b, and c

  if(a<b && b<c){ // Starting the if condition block
    cout<<"Yes"<<endl; // If the condition is true, print "Yes" to the standard output
  }else{ // Starting the else condition block
    cout<<"No"<<endl; // If the condition is false, print "No" to the standard output
  }

  return 0; // Ending the main function with a return value of 0
}

