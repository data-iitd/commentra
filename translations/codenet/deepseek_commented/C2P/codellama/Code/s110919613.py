#include <stdio.h>

def main():
  i,j,k,L,tmp,d,def,end,aj,max,min = 0,0,0,0,0,0,0,0,0,0,0
  
  while True:
    an = [0] * 20
    a1 = [0] * 6
    a2 = [0] * 6
    scanf("%d %d", &an[0], &L)
    if L == 0: break # If L is 0, break out of the loop
    
    aj = an[0]
    end = 0
    for k in range(1, 21):
      for i in range(L-1, -1, -1):
	aj /= 10
	a1[i] = aj % 10
	a2[i] = aj % 10
      for i in range(1, L):
	for j in range(1, L):
	  if a1[j-1] < a1[j]: # Sort a1 in ascending order
	    tmp = a1[j-1]
	    a1[j-1] = a1[j]
	    a1[j] = tmp
	  if a2[j-1] > a2[j]: # Sort a2 in descending order
	    tmp = a2[j-1]
	    a2[j-1] = a2[j]
	    a2[j] = tmp
      d = 1
      max = 0
      min = 0
      for i in range(L-1, -1, -1):
	d *= 10
	max += (a1[i] % 10) * d
	min += (a2[i] % 10) * d
      def = max - min
      for i in range(0, k):
	if def == an[i]: # Check if def has been seen before
	  printf("%d %d %d\n", i, def, k-i) # Print the index, def, and steps taken
	  end = 1
	  break # Set end to 1 to break out of the loop
      if end == 1: break # If end is 1, break out of the loop
      an[k] = def
      aj = def
    return 0

