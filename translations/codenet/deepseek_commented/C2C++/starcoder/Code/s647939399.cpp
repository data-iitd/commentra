#include<iostream>  // Step 1: Include the standard input/output library.

using namespace std;  // Step 2: Use the standard namespace.

int main(){  // Step 3: Define the main function.
  char m;  // Step 4: Declare a character variable'm'.
  int a,b,c[256],i,j;  // Declare two integers 'a' and 'b', an array 'c' of size 256, and two integer variables 'i' and 'j'.

  for(i=0;i>-1;i++){  // Step 5: Start an infinite loop using a 'for' loop with no condition.
    cin>>a>>m>>b;  // Step 6: Read three inputs: an integer 'a', a character'm', and an integer 'b'.
    if(m=='?'){  // Step 7: Check if the character'm' is '?'. If true, break the loop.
      break;
    }
    if(m=='+'){  // Step 8: Depending on the character'm', perform the corresponding arithmetic operation and store the result in the array 'c' at index 'i'.
      c[i]=a+b;
    }
    if(m=='-'){
      c[i]=a-b;
    }
    if(m=='*'){
      c[i]=a*b;
    }
    if(m=='/'){
      c[i]=a/b;
    }
  }

  for(j=0;j<i;j++){  // Step 11: After the loop ends, start another loop to print the results stored in the array 'c' from index 0 to 'i-1'.
    cout<<c[j]<<endl;
  }
  return(0);  // Step 12: Return 0 to indicate successful execution.
}
