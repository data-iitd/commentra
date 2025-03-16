
#include<string>
#include<iostream>

// Declare variables
int main(){
  std::string **t,**h; // t and h are pointers to arrays of strings
  int n, // number of strings to be compared
      taro=0, // score for Taro
      hanako=0; // score for Hanako
  int i; // loop counter

  // Read the number of strings to be compared from the standard input
  std::cin>>n;

  // Allocate memory for t and h arrays
  t=new std::string*[n];
  h=new std::string*[n];

  // Initialize the loops for t and h arrays
  for(i=0;i<n;i++){
    // Allocate memory for each string in t and h arrays
    t[i]=new std::string[100];
    h[i]=new std::string[100];

    // Read strings from the standard input and store them in t and h arrays
    std::cin>>t[i];
    std::cin>>h[i];

    // Compare the strings and update the scores accordingly
    if(t[i]<h[i]){
      hanako+=3; // Hanako gets 3 points if the current string in t is smaller than the corresponding string in h
    }
    else if(t[i]>h[i]){
      taro+=3; // Taro gets 3 points if the current string in t is larger than the corresponding string in h
    }
    else{ // If the strings are equal
      taro+=1; // Taro gets 1 point if the strings are equal
      hanako+=1; // Hanako gets 1 point if the strings are equal
    }

    // Free the memory allocated for each string in t and h arrays
    delete[] t[i];
    delete[] h[i];
  }

  // Print the scores for Taro and Hanako
  std::cout<<taro<<" "<<hanako<<std::endl;

  // Free the memory allocated for t and h arrays
  delete[] t;
  delete[] h;

  // Return 0 to indicate successful execution of the program
  return 0;
}

