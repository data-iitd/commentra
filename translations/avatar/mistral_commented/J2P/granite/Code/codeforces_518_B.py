

import sys

# Main method declaration
def main ( ) :
    scan = Scanner ( ) ; # Create a new Scanner object to read input from the console
    s = StringBuilder ( scan.next ( ) ) ; # Create a new StringBuilder object to store the first input string
    t = scan.next ( ) ; # Read the second input string from the console

    # Initialize counters for unique characters in the first string and opposite characters in the second string
    ura = 0 ;
    opa = 0 ;

    # Create a dictionary to store the frequency of each character in the second string
    tmap = dict ( ) ;

    # Read the characters of the second string and store their frequencies in the dictionary
    for ch in t :
        if ch not in tmap : # If the character is not already in the dictionary
            tmap [ ch ] = 1 ; # Add it with a frequency of 1
        else :
            tmap [ ch ] += 1 ; # If the character is already in the dictionary, increment its frequency

    # Process the first string
    length = len ( s ) ;
    for i in range ( length ) :
        ch = s [ i ] ;
        num = tmap.get ( ch ) ;
        if num == None : # If the character is not in the second string
            continue ;
        inum = num ;
        if inum == 1 : # If the character appears only once in the second string
            del tmap [ ch ] ; # Remove it from the dictionary
        else :
            tmap [ ch ] = inum - 1 ; # If the character appears more than once in the second string, decrement its frequency
        s [ i ] = 'Я' ; # Replace the character in the StringBuilder with 'Я'
        ura += 1 ; # Increment the counter for unique characters

    # Process the reversed version of the first string
    for i in range ( length - 1, - 1, - 1 ) :
        ch = s [ i ] ;
        rch = reverse ( ch ) ; # Get the reverse character of the current character
        num = tmap.get ( rch ) ;
        if num == None : # If the reverse character is not in the second string
            continue ;
        inum = num ;
        if inum == 1 : # If the reverse character appears only once in the second string
            del tmap [ rch ] ; # Remove it from the dictionary
        else :
            tmap [ rch ] = inum - 1 ; # If the reverse character appears more than once in the second string, decrement its frequency
        opa += 1 ; # Increment the counter for opposite characters

    # Print the results
    print ( ura, opa ) ; # Print the counters for unique characters and opposite characters

# Reverse the given character
def reverse ( ch ) :
    if ch.islower ( ) : # If the character is lowercase
        return ch.upper ( ) ; # Return its uppercase version
    else :
        return ch.lower ( ) ; # If the character is uppercase, return its lowercase version

# Main method starts the execution of the program
if __name__ == "__main__" :
    main ( ) ; # Call the main method to start the program

