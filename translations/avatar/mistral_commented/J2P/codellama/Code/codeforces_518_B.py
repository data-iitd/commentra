
import sys

# Main method declaration
def main ( ) :
    # Create a new Scanner object to read input from the console
    scan = sys.stdin
    # Create a new StringBuilder object to store the first input string
    s = scan.readline ( )
    # Read the second input string from the console
    t = scan.readline ( )

    # Initialize counters for unique characters in the first string and opposite characters in the second string
    ura = 0
    opa = 0

    # Create a HashMap to store the frequency of each character in the second string
    tmap = { }

    # Read the characters of the second string and store their frequencies in the HashMap
    for ch in t :
        if ch not in tmap :
            tmap [ ch ] = 1
        else :
            tmap [ ch ] += 1

    # Process the first string
    length = len ( s )
    for i in range ( length ) :
        ch = s [ i ]
        num = tmap.get ( ch )
        if num == None :
            continue
        inum = num
        if inum == 1 :
            tmap.pop ( ch )
        else :
            tmap [ ch ] = inum - 1
        s [ i ] = 'Я'
        ura += 1

    # Process the reversed version of the first string
    for i in range ( length ) :
        ch = s [ i ]
        rch = reverse ( ch )
        num = tmap.get ( rch )
        if num == None :
            continue
        inum = num
        if inum == 1 :
            tmap.pop ( rch )
        else :
            tmap [ rch ] = inum - 1
        opa += 1

    # Print the results
    print ( ura , opa )

# Reverse the given character
def reverse ( ch ) :
    if ch.islower ( ) :
        return ch.upper ( )
    else :
        return ch.lower ( )

# Main method starts the execution of the program
main ( )

