

s1 = input ( ) # Read the first string from the input
s2 = input ( ) # Read the second string from the input

def isValid ( s1, s2 ) : # Check if the given strings are valid
    n1 = len ( s1 ) # Get the length of the first string
    n2 = len ( s2 ) # Get the length of the second string

    map = dict ( ) # Create a dictionary to store the presence of characters in the first string

    for c in s1 : # Iterate through each character in the first string
        map [ c ] = True # Mark the character as present in the dictionary

    for c in s2 : # Iterate through each character in the second string
        if c not in map : # If the character is not present in the first string, return false
            return False # Return false

    return True # If all characters in the second string are present in the first string, return true

if isValid ( s1, s2 ) == False : # Check if the given strings are valid
    print ( - 1 ) # If not valid, print -1 and exit
else : # If the strings are valid, proceed with the computation
    m1 = dict ( ) # Create a dictionary to store the frequency of characters in the first string
    m2 = dict ( ) # Create a dictionary to store the frequency of characters in the second string

    for c in s1 : # Iterate through each character in the first string
        if c in m1 : # If the character is already in the dictionary, increment its count
            m1 [ c ] += 1
        else : # If the character is not in the dictionary, add it with a count of 1
            m1 [ c ] = 1

    for c in s2 : # Iterate through each character in the second string
        if c in m2 : # If the character is already in the dictionary, increment its count
            m2 [ c ] += 1
        else : # If the character is not in the dictionary, add it with a count of 1
            m2 [ c ] = 1

    ans = 0 # Initialize the answer variable to 0
    hs = set ( ) # Create a set to store unique characters in the second string

    for c in s2 : # Iterate through each character in the second string
        if c not in hs : # If the character is not already in the set, add it and compute the answer
            hs. add ( c ) # Add the character to the set
            x1 = m1 [ c ] # Get the count of the character in the first string
            x2 = m2 [ c ] # Get the count of the character in the second string
            x1 = min ( x1, x2 ) # Take the minimum count
            ans += x1 # Add the minimum count to the answer

    print ( ans ) # Print the answer

