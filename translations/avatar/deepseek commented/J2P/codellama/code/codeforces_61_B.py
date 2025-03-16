
import re

# Initialize Scanner for input operations
in = input ( )

# Read and process the three input words
word1 = re.sub ( "[^a-zA-Z]" , "" , in )
word2 = re.sub ( "[^a-zA-Z]" , "" , in )
word3 = re.sub ( "[^a-zA-Z]" , "" , in )

# Generate all possible permutations of the three words
perm1 = word1 + word2 + word3
perm2 = word1 + word3 + word2
perm3 = word2 + word1 + word3
perm4 = word2 + word3 + word1
perm5 = word3 + word2 + word1
perm6 = word3 + word1 + word2

# Read the number of test cases
students = int ( input ( ) )

# Process each test case
for i in range ( students ) :
    # Check if the test case matches any of the generated permutations
    if ( re.sub ( "[^a-zA-Z]" , "" , input ( ) ) == perm1 or re.sub ( "[^a-zA-Z]" , "" , input ( ) ) == perm2 or re.sub ( "[^a-zA-Z]" , "" , input ( ) ) == perm3 or re.sub ( "[^a-zA-Z]" , "" , input ( ) ) == perm4 or re.sub ( "[^a-zA-Z]" , "" , input ( ) ) == perm5 or re.sub ( "[^a-zA-Z]" , "" , input ( ) ) == perm6 ) :
        print ( "ACC" )
    else :
        print ( "WA" )

# END-OF-CODE
