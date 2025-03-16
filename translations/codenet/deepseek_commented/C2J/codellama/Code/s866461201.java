#include <stdio.h>

public class Main {
  public static void main(String[] args) {
    // Declare variables
    int n, fd[] = new int[6], i, j; // n: number of heights, fd: array to store counts, i, j: loop counters
    double height; // height: variable to store each height input

    // Read the number of heights
    scanf("%d", &n);
    
    // Loop to read each height and categorize it
    while(n--){
      scanf("%lf", &height);
      if(height >= 185.0) fd[5]++;
      else if(height >= 180.0) fd[4]++;
      else if(height >= 175.0) fd[3]++;
      else if(height >= 170.0) fd[2]++;
      else if(height >= 165.0) fd[1]++;
      else fd[0]++;
    }

    // Loop to print the histogram
    for(i = 0;i < 6;i++){
      printf("%d:", i + 1);
      for(j = 0;j < fd[i];j++)
        putchar('*');
      puts("");
    }
  }
}

