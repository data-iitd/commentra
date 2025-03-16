import sys ; 
import math ; 
import string ; 
import ascii ; 
import re ; 
import itertools ; 
import collections ; 

def solve ( ) : 
    t = int ( sys . stdin . readline ( ) ) ; 
    arr = [ int ( sys . stdin . readline ( ) ) for i in range ( t ) ] ; 
    prevWinner = 0 ; 
    for i in range ( t ) : 
        if arr [ i ] == 1 : 
            if prevWinner == 0 : 
                prevWinner = 2 ; 
        if prevWinner == 2 or prevWinner == 0 : 
            if ( arr [ i ] - 1 ) % 2 == 0 : 
                print ( 2 ) ; 
                prevWinner = 2 ; 
            else : 
                print ( 1 ) ; 
                prevWinner = 1 ; 
        else : 
            if ( arr [ i ] - 1 ) % 2 == 0 : 
                print ( 1 ) ; 
                prevWinner = 1 ; 
            else : 
                print ( 2 ) ; 
                prevWinner = 2 ; 
    return ; 

solve ( ) ; 

