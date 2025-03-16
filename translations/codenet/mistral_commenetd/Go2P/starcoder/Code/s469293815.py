
# Package main provides the entry point for the program.
#
# File:  a.py
# Author: ymiyamoto
#
# Created on Sat Dec 29 04:47:30 2018
#

import sys

def main():
    # Declare and initialize three integer variables, A, B, and C, with values read from the standard input.
    A, B, C = map(int, sys.stdin.readline().split())

    # Check if the sum of A and B is greater than or equal to C.
    if A+B >= C:
        # If the condition is true, print "Yes" to the standard output.
        print("Yes")
    else:
        # If the condition is false, print "No" to the standard output.
        print("No")

if __name__ == '__main__':
    main()

