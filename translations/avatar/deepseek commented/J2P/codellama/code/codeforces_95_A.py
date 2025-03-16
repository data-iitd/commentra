import sys ; 
import io ; 
import os ; 
import platform ; 
import time ; 
import math ; 
import random ; 
import re ; 
import itertools ; 

class Main ( io.TextIOWrapper ) : 
    def __init__ ( self ) : 
        super ( ).__init__ ( sys.stdout , encoding = 'utf-8' ) ; 

    def main ( self ) : 
        # Reading the number of strings and the array of strings
        n = int ( input ( ) ) ; 
        ss = [ input ( ).split ( ) for _ in range ( n ) ] ; 

        # Reading the pattern array and the target character
        cc = input ( ).split ( ) ; 
        m = len ( cc ) ; 
        c = input ( ) ; 
        c_ = c.upper ( ) ; 
        a = 'b' if c == 'a' else 'a' ; 
        a_ = a.upper ( ) ; 

        # Array to mark positions in cc that match any string in ss
        lucky = [ False ] * m ; 

        # Finding lucky positions and updating characters based on the target character c
        for j in range ( m ) : 
            for i in range ( n ) : 
                l = len ( ss [ i ] ) ; 
                if m - j >= l and cc [ j : j + l ] == ss [ i ] : 
                    for h in range ( l ) : 
                        lucky [ j + h ] = True ; 

        # Updating characters in cc based on the lucky positions and target character c
        for j in range ( m ) : 
            if lucky [ j ] : 
                if cc [ j ] == c : 
                    cc [ j ] = a_ if cc [ j ].isupper ( ) else a ; 
                else : 
                    cc [ j ] = c_ if cc [ j ].isupper ( ) else c ; 

        # Printing the modified cc array
        print ( ' '.join ( cc ) ) ; 

if __name__ == '__main__' : 
    Main ( ) . main ( ) ; 

