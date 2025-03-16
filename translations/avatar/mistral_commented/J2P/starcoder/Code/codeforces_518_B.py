
# Main method declaration
def main ( ):
    scan = input ( ) # Create a new Scanner object to read input from the console
    s = scan.next ( ) # Create a new StringBuilder object to store the first input string
    t = scan.next ( ) # Read the second input string from the console

    # Initialize counters for unique characters in the first string and opposite characters in the second string
    ura = 0
    opa = 0

    # Create a HashMap to store the frequency of each character in the second string
    tmap = { }

    # Read the characters of the second string and store their frequencies in the HashMap
    for i in range ( len ( t ) ):
        ch = t [ i ]
        if ( ch not in tmap ): # If the character is not already in the HashMap
            tmap [ ch ] = 1 # Add it with a frequency of 1
        else:
            tmap [ ch ] = tmap [ ch ] + 1 # If the character is already in the HashMap, increment its frequency

    # Process the first string
    length = len ( s )
    for i in range ( length ):
        ch = s [ i ]
        num = tmap [ ch ]
        if ( num == None ): # If the character is not in the second string
            continue
        inum = num
        if ( inum == 1 ): # If the character appears only once in the second string
            tmap.remove ( ch ) # Remove it from the HashMap
        else:
            tmap [ ch ] = inum - 1 # If the character appears more than once in the second string, decrement its frequency
        s = s [ : i ] + 'Я' + s [ i + 1 : ] # Replace the character in the StringBuilder with 'Я'
        ura = ura + 1 # Increment the counter for unique characters

    # Process the reversed version of the first string
    for i in range ( length ):
        ch = s [ i ]
        rch = reverse ( ch ) # Get the reverse character of the current character
        num = tmap [ rch ]
        if ( num == None ): # If the reverse character is not in the second string
            continue
        inum = num
        if ( inum == 1 ): # If the reverse character appears only once in the second string
            tmap.remove ( rch ) # Remove it from the HashMap
        else:
            tmap [ rch ] = inum - 1 # If the reverse character appears more than once in the second string, decrement its frequency
        opa = opa + 1 # Increment the counter for opposite characters

    # Print the results
    print ( ura, opa )

# Reverse the given character
def reverse ( ch ):
    if ( ch.islower ( ) ): # If the character is lowercase
        return ch.upper ( ) # Return its uppercase version
    else:
        return ch.lower ( ) # If the character is uppercase, return its lowercase version

# Main method starts the execution of the program
if __name__ == '__main__':
    main ( )

