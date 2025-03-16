

import sys

# Read and process the three input words
word1 = input ( ).strip ( ).lower ( ) 
word2 = input ( ).strip ( ).lower ( ) 
word3 = input ( ).strip ( ).lower ( ) 

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
    testCase = input ( ).strip ( ).lower ( ) 
    # Check if the test case matches any of the generated permutations
    if testCase == perm1 or testCase == perm2 or testCase == perm3 or testCase == perm4 or testCase == perm5 or testCase == perm6 : 
        print ( "ACC" ) # Print "ACC" if a match is found
    else : 
        print ( "WA" ) # Print "WA" if no match is found

