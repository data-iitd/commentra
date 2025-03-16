import collections
import heapq
import sys
import math
import itertools
import bisect
from io import BytesIO , IOBase
import os

# Function to check if a given pair of indices (i, j) is within the bounds of a grid with dimensions n by m
def valid ( i , j , n , m ) :
    if i < n and i >= 0 and j >= 0 and j < m : return True
    return False

# Function to calculate the sum of an arithmetic series from i to n
def sumn ( i , n ) :
    return ( n - i ) * ( i + n ) / 2

# Function to solve a quadratic equation of the form ax^2 + bx + c = 0
def sqfun ( a , b , c ) :
    return ( - b + math.sqrt ( b * b - 4 * a * c ) ) / 2 * a

# Function to read a single or multiple integer values from input
def value ( ) : return tuple ( map ( int , input ( ).split ( ) ) )

# Function to read a single or multiple integer values from standard input
def values ( ) : return tuple ( map ( int , sys.stdin.readline ( ).split ( ) ) )

# Function to read a list of integers from input
def inlst ( ) : return [ int ( i ) for i in input ( ).split ( ) ]

# Function to read a list of integers from standard input
def inlsts ( ) : return [ int ( i ) for i in sys.stdin.readline ( ).split ( ) ]

# Function to read a single integer from input
def inp ( ) : return int ( input ( ) )

# Function to read a single integer from standard input
def inps ( ) : return int ( sys.stdin.readline ( ) )

# Function to read a string from input
def instr ( ) : return input ( )

# Function to split a string into a list of words
def stlst ( ) : return [ i for i in input ( ).split ( ) ]

# Function to sanitize a string by converting it to lowercase and removing certain characters
def f ( s ) :
    r = ''
    for i in s :
        if i not in [ '-' , ';' , '_' ] : r += i.lower ( )
    return r

# Main logic of the program
def solve ( ) :
    l = [ ]
    for i in range ( 3 ) :
        l.append ( f ( input ( ) ) )
    t = itertools.permutations ( l , len ( l ) )
    l = [ ]
    for i in t : l.append ( "".join ( i ) )
    for i in range ( inp ( ) ) :
        if f ( instr ( ) ) in l : print ( 'ACC' )
        else : print ( 'WA' )

if __name__ == "__main__" :
    solve ( )