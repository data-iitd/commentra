

#include<iostream> // Including the standard input output library

int main(){ // Starting the main function
  int a,b,c; // Declaring three integer variables a, b, and c
  std::cin>>a>>b>>c; // Reading three integers from the standard input and storing them in variables a, b, and c

  if(a<b && b<c){ // Starting the if condition block
    std::cout<<"Yes\n"; // If the condition is true, print "Yes" to the standard output
  }else{ // Starting the else condition block
    std::cout<<"No\n"; // If the condition is false, print "No" to the standard output
  }

  return 0; // Ending the main function with a return value of 0
}

