
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

# Declare variables
def main():
  t=[] # t is a list of character strings
  h=[] # h is a list of character strings
  n=0 # number of strings to be compared
  taro=0 # score for Taro
  hanako=0 # score for Hanako
  i=0 # loop counter

  # Read the number of strings to be compared from the standard input
  n=int(input())

  # Initialize the loops for t and h lists
  for i in range(n):
    # Read strings from the standard input and store them in t and h lists
    t.append(input())
    h.append(input())

    # Compare the strings and update the scores accordingly
    if(t[i]<h[i]):
      hanako+=3 # Hanako gets 3 points if the current string in t is smaller than the corresponding string in h
    elif(t[i]>h[i]):
      taro+=3 # Taro gets 3 points if the current string in t is larger than the corresponding string in h
    else: # If the strings are equal
      taro+=1 # Taro gets 1 point if the strings are equal
      hanako+=1 # Hanako gets 1 point if the strings are equal

  # Print the scores for Taro and Hanako
  print(taro,hanako)

  # Return 0 to indicate successful execution of the program
  return 0

