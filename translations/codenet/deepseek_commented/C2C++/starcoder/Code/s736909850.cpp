#include<iostream>  // Step 1: Include the standard input/output library to use cout and cin functions.

using namespace std;  // Step 2: Use the standard namespace.

int main(void){  // Step 3: Define the main function which is the entry point of the program.
   int sheep;  // Step 4: Declare two integer variables, sheep and wolf, to store the number of sheep and wolves.
   int wolf;

   cin>>sheep>>wolf;  // Step 5: Use the cin function to read the number of sheep and wolves from the user.

   if(wolf>=sheep){  // Step 6: Check if the number of wolves is greater than or equal to the number of sheep.
      cout<<"unsafe"<<endl;  // Step 7: If the condition is true, print "unsafe".
   } else {
      cout<<"safe"<<endl;  // Step 8: Otherwise, print "safe".
   }

   return 0;  // Step 9: Return 0 to indicate successful execution of the program.
}

