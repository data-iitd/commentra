
#include<iostream>
#include<cstdlib>

// Function to run the logic of the program
void run(void){
  // Declare variables
  int n, k;

  // Read input values of n and k from the user
  std::cout<<"Enter the number of elements in the array and the target sum: ";
  std::cin>>n>>k;

  // Declare an array of size n to store the elements of the array
  int a[100];

  // Read the elements of the array from the user
  std::cout<<"Enter "<<n<<" integers: ";
  for(int i=0;i<n;i++){
    std::cin>>a[i];
  }

  // Declare a dynamic array of size k+1 to store the dp values
  int *dp=(int *)calloc(k+1,sizeof(int));

  // Initialize all dp values as false initially
  for(int i=0;i<=k;i++){
    dp[i]=0;
  }

  // Calculate the dp values for all sums from 1 to k
  for(int i=1;i<=k;i++){
    int win=0;

    // Check if there exists a subset of sum i in the given array a[]
    for(int j=0;j<n && a[j]<=i;j++){
      // If a[j] can be included in the subset, then check for the next element
      if(dp[i-a[j]]==1){
	win=1;
	break;
      }
    }

    // Update the dp value for the current sum i
    dp[i]=win;
  }

  // Print the result based on the dp value for the target sum k
  std::cout<<"The target sum "<<k<<" is ";
  if(dp[k]){
    std::cout<<"First\n"; // Target sum is a subset of given array
  }
  else{
    std::cout<<"Second\n"; // Target sum is not a subset of given array
  }

  // Free the memory allocated to dp array
  free(dp);
}

// Main function to call the run function
int main(void){
  // Call the run function to execute the logic
  run();

  // Return 0 to indicate successful execution of the program
  return 0;
}

