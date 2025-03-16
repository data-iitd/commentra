# Importing bufio package but not using it
import sys

# Importing fmt package for formatted I/O
import math

# Importing os package but not using it
import random

# Importing strconv package but not using it
import re

# Declare variables to hold input values
x, a, b = [int(x) for x in input().split()]

# Evaluate the difference between b and a to determine the output
if b-a <= 0:
	print("delicious") # Output "delicious" if b is less than or equal to a
elif b-a <= x:
	print("safe") # Output "safe" if the difference is within the limit x
else:
	print("dangerous") # Output "dangerous" if the difference exceeds x

# 