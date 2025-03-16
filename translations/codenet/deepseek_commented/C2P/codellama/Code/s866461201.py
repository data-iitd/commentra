#include <stdio.h>

int main():
  # Declare variables
  n = 0
  fd = [0, 0, 0, 0, 0, 0]
  i = 0
  j = 0
  height = 0.0

  # Read the number of heights
  scanf("%d", &n)
  
  # Loop to read each height and categorize it
  while(n > 0):
    scanf("%lf", &height)
    if(height >= 185.0):
      fd[5] += 1
    elif(height >= 180.0):
      fd[4] += 1
    elif(height >= 175.0):
      fd[3] += 1
    elif(height >= 170.0):
      fd[2] += 1
    elif(height >= 165.0):
      fd[1] += 1
    else:
      fd[0] += 1
    n -= 1

  # Loop to print the histogram
  for(i = 0;i < 6;i++):
    printf("%d:", i + 1)
    for(j = 0;j < fd[i];j++):
      putchar('*')
    puts("")
  return 0

