# Package main provides
#
# File:  a.py
# Author: ymiyamoto
#
# Created on Sat Dec 29 04:47:30 2018
#
import sys

def main():
    A, B, C = map(int, sys.stdin.readline().split())

    # Read three integers from standard input
    # A, B, and C will store these values

    if A+B >= C:
        # Check if the sum of A and B is greater than or equal to C
        print("Yes")
    else:
        # If the sum is less than C, print "No"
        print("No")

if __name__ == '__main__':
    main()

