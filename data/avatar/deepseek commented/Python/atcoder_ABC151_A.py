
import sys
import math
debug = False
def log ( text ) :
    if debug :
        print ( text )
# Function to parse input from either user input or a string
def parse_input ( lines_as_string = None ) :
    global debug
    lines = [ ]
    if lines_as_string is None :
        debug = False
        lines.append ( input ( ) )
    else :
        debug = True
        lines = [ e for e in lines_as_string.split ( "\n" ) ] [ 1 : - 1 ]
    c = [ e for e in lines [ 0 ].split ( " " ) ] [ 0 ]
    return ( c , )
# Function to solve the problem by finding the next character in the alphabet
def solve ( c ) :
    a = "abcdefghijklmnopqrstuvwxyz"
    i = a.index ( c )
    return a [ i + 1 ]
# Main function to orchestrate the execution of the program
def main ( ) :
    result = solve ( * parse_input ( ) )
    if isinstance ( result , list ) :
        for r in result :
            print ( "%s" % r , sep = '' )
    else :
        print ( "%s" % result , sep = '' )
if __name__ == '__main__' :
    main ( )

