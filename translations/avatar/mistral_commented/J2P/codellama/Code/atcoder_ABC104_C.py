# Importing the required Python utility library
import sys

# Reading the number of test cases D from the standard input
D = int ( sys.stdin.readline ( ) )

# Reading the goal score G from the standard input
G = int ( sys.stdin.readline ( ) )

# Declaring and initializing two integer arrays p and c of size D
p = [ ]
c = [ ]
for i in range ( D ) :
    p.append ( int ( sys.stdin.readline ( ) ) )
    c.append ( int ( sys.stdin.readline ( ) ) )

# Initializing a variable min to a large value
min = 100000

# Looping through all possible combinations of bits using a binary number
for bit in range ( 1 << D ) :

    # Initializing variables score and solve_num to zero
    score = 0
    solve_num = 0

    # Looping through each test case i
    for i in range ( D ) :

        # Checking if the current bit is set in the binary number
        if ( bit & ( 1 << i ) ) != 0 :

            # Adding the score for the current test case i to the total score
            score += 100 * ( i + 1 ) * p [ i ] + c [ i ]

            # Incrementing the number of test cases solved so far
            solve_num += p [ i ]

    # Checking if the current combination of bits can form a valid solution
    if score < G :

        # Backtracking to find the minimum number of test cases to be solved
        for i in range ( D - 1 , -1 , -1 ) :

            # If the current bit is not set in the binary number
            if ( bit & ( 1 << i ) ) == 0 :

                # Looping through each test case j that can be added to the current solution
                for j in range ( 0 , p [ i ] - 1 ) :

                    # Adding the score for the current test case i and the current test case j to the total score
                    score += 100 * ( i + 1 )

                    # Incrementing the number of test cases solved so far
                    solve_num += 1

                    # Checking if the current combination of bits can form a valid solution
                    if score >= G :

                        # Breaking out of the inner loop as we have found a valid solution
                        break

                # If we have found a valid solution, we can break out of the outer loop as well
                if score >= G :
                    break

    # Updating the minimum number of test cases if the current combination of bits can form a valid solution with a smaller number of test cases
    if score >= G :
        min = min ( min , solve_num )

# Printing the minimum number of test cases required to form a valid solution
print ( min )

# End of code
