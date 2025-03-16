#include <stdio.h>

def main():
  n=int(input())
  cnt4=0
  cnt2=0
  for i in range(n):
    wk=int(input())
    if wk%4==0:
      cnt4+=1
    elif wk%2==0:
      cnt2+=1
  if cnt4+cnt2/2>=n/2:
    print("Yes")
  else:
    print("No")

main()

