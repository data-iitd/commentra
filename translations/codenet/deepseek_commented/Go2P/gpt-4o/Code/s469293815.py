# Package main provides
#
# File:  a.py
# Author: ymiyamoto
#
# Created on Sat Dec 29 04:47:30 2018

# Read three integers from standard input
A, B, C = map(int, input().split())

# Check if the sum of A and B is greater than or equal to C
if A + B >= C:
    print("Yes")
else:
    print("No")

# <END-OF-CODE>
