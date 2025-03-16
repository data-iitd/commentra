#include<stdio.h>
def linersearch(a,n,key):
  i=0

  # Modify the array to facilitate the search
  a.append(key)
  
  # Perform the linear search
  while a[i]!=key:
    i+=1

  # Return true if the key is found, false otherwise
  return i!=n


def main():
  i,n,s,q,t,count=0

  # Read the number of elements
  n=int(input())

  # Read the elements into the array s
  s=list(map(int,input().split()))

  # Read the number of queries
  q=int(input())

  # Perform a linear search for each query
  for i in range(q):
    t=int(input())
    if linersearch(s,n,t):
      count+=1

  # Print the total count of successful searches
  print(count)
  
main()

