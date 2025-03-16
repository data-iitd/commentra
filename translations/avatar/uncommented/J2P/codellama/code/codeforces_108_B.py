
import sys
import math
import string
import re
import array
import bisect
import collections
import heapq
import time
import random
import itertools


def solve ( ) :
    n = int ( input ( ) )
    a = [ int ( x ) for x in input ( ).split ( ) ]
    a.sort ( )
    for i in range ( len ( a ) - 1 ) :
        if a [ i + 1 ] < a [ i ] * 2 and a [ i ] != a [ i + 1 ] :
            print ( "YES" )
            return
    print ( "NO" )


if __name__ == "__main__" :
    solve ( )


