#include<stdio.h>
#include<stdlib.h>
 
top,S=[],[]
 
def push(x):
  S.append(x)
 
def pop():
  return S.pop()
 
def main():
  a,b,s=0,0,[]
  top=0
   
  while(input()!=EOF):
    if(s[0]=='+'):
      b=pop()
      a=pop()
      push(a+b)
    elif(s[0]=='-'):
      b=pop()
      a=pop()
      push(a-b)
    elif(s[0]=='*'):
      b=pop()
      a=pop()
      push(a*b)
    else:
      push(int(s))
 
  print(pop())
 
if __name__ == "__main__":
  main()
 
