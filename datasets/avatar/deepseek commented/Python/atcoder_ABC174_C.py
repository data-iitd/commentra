from sys import stdin , stdout , setrecursionlimit
from math import gcd , ceil , sqrt
from collections import Counter
from bisect import bisect_left , bisect_right
ii1 = lambda : int ( stdin.readline ( ).strip ( ) )  # Function to read an integer
is1 = lambda : stdin.readline ( ).strip ( )  # Function to read a string
iia = lambda : list ( map ( int , stdin.readline ( ).strip ( ).split ( ) ) )  # Function to read a list of integers
isa = lambda : stdin.readline ( ).strip ( ).split ( )  # Function to read a list of strings
setrecursionlimit ( 100000 )  # Set the recursion limit to 100,000
mod = 1000000007  # Define the modulo constant
k = ii1 ( )  # Read the integer k
t = 0  # Initialize t to 0
for i in range ( 1 , k + 1 ) :  # Loop from 1 to k
    t = ( t % k ) * 10 + 7  # Update t based on the current iteration
    if t % k == 0 :  # Check if t is divisible by k
        print ( i )  # Print the current index if t is divisible by k
        break  # Break the loop as we found the solution
else :  # If the loop completes without breaking
    print ( - 1 )  # Print -1 indicating no solution was found
