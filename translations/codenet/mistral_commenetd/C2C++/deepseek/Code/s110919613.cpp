#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  // Declare variables
  int i, j, k, L, tmp, d, def, end, aj, max, min;

  // Infinite loop to read input
  for(;;){
    std::vector<int> an(20);
    std::vector<int> a1(6);
    std::vector<int> a2(6);
    std::cin >> an[0] >> L;
    if(!L) break; // Exit the loop if the input length is zero

    aj=an[0]; end=0;

    // Iterate through each number in the input array
    for(k=1;k<20;k++){
      // Iterate through each digit in the number from right to left
      for(i=L-1;i>=0;i--,aj/=10){
	a1[i]=aj%10; a2[i]=aj%10;
      }
      // Sort the digits in both arrays in ascending order
      std::sort(a1.begin(), a1.begin() + L);
      std::sort(a2.begin(), a2.begin() + L, std::greater<int>());

      // Calculate the difference between the two numbers
      d=1; max=0; min=0;
      for(i=L-1;i>=0;i--,d*=10){
	max+=(a1[i])*d;
	min+=(a2[i])*d;
      }
      def=max-min; // Store the difference in a variable

      // Check if the difference has already been encountered in the array 'an'
      for(i=0;i<k;i++){
	if(def==an[i]){ // If a match is found, print the result and exit the loop
	  std::cout << i << " " << def << " " << k-i << std::endl;
	  end=1; break;
	}
      }
      if(end==1) break; // Exit the loop if a match is found
      an[k]=def; aj=def; // Update the array and the variable for the next iteration
    }
  }

  return 0;
}
