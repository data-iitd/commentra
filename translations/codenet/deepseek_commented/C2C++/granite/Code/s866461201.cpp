
#include <iostream>

int main(){
  // Declare variables
  int n, fd[6] = {}, i, j; // n: number of heights, fd: array to store counts, i, j: loop counters
  double height; // height: variable to store each height input

  // Read the number of heights
  std::cin >> n;
  
  // Loop to read each height and categorize it
  while(n--){
    std::cin >> height;
    if(height >= 185.0) fd[5]++;
    else if(height >= 180.0) fd[4]++;
    else if(height >= 175.0) fd[3]++;
    else if(height >= 170.0) fd[2]++;
    else if(height >= 165.0) fd[1]++;
    else fd[0]++;
  }

  // Loop to print the histogram
  for(i = 0;i < 6;i++){
    std::cout << i + 1 << ":";
    for(j = 0;j < fd[i];j++)
      std::cout << "*";
    std::cout << std::endl;
  }
  return 0;
}
