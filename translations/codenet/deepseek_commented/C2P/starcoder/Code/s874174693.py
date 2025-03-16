#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define ll long long

// Function to swap two integers
def swap(x,y):
  temp=x
  x=y
  y=temp
  return

// Function to calculate the greatest common divisor (GCD)
def gcd(a,b):
  c=0
  while(b>0):
    c=a%b
    a=b
    b=c
  return a

// Function to compare long long integers for ascending order in sorting
def upll(a,b):
  return a<b and -1 or 1

// Function to compare long long integers for descending order in sorting
def downll(a,b):
  return a<b and 1 or -1

// Function to sort an array of long long integers in ascending order
def sortup(a,n):
  a.sort(upll)
  return

// Function to sort an array of long long integers in descending order
def sortdown(a,n):
  a.sort(downll)
  return

// Function to calculate (a^n) % mod using modular exponentiation
def modpow(a,n,mod):
  ans=1
  while(n>0):
    if(n & 1):
      ans=ans*a%mod
    a=a*a%mod
    n/=2
  return ans

// Function to calculate modular multiplicative inverse
def modinv(a,mod):
  return modpow(a,mod-2,mod)

// Function to find the maximum of two integers
def max(a,b):
  if(a<b):
    return b
  else:
    return a

// Function to find the minimum of two integers
def min(a,b):
  if(a<b):
    return a
  else:
    return b

// Function to update a variable if it is smaller
def chmax(a,b):
  if(a<b):
    a=b
  return

// Function to update a variable if it is larger
def chmin(a,b):
  if(a>b):
    a=b
  return

// Main function
def main():
  n=int(raw_input())
  sum=0
  m=n
  while(n>0):
    sum+=n%10
    n/=10
  if(m%sum==0):
    print "Yes"
  else:
    print "No"
  return 0

#