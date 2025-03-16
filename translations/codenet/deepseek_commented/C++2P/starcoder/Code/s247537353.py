# Fast I/O setup
from sys import stdin,stdout
from math import *
from collections import *
from itertools import *

# Declare variables to store input values
A,B,C,K = map(int,stdin.readline().split())

# Check if the sum of A and B is greater than or equal to K
if A+B>=K:
  # Output the minimum of A and K
  stdout.write(str(min(A,K))+'\n')
else:
  # Calculate the result by subtracting the excess amount from A
  stdout.write(str(A-(K-(A+B)))+'\n')

# 