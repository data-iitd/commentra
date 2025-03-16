# Import the copy module for deep copying a list
import copy

# Define a function named 'solve' to find the solution
def solve():

    # Read the string 'S_d' and 'T' from the standard input
    S_d = list(input())
    T = list(input())

    # Initialize variables 'end' and 'first'
    end = len(S_d) - 1
    first = end - len(T) + 1

    # Use a 'while' loop to find the matching pattern in 'S_d' with 'T'
    while first >= 0:
        # Initialize variable 't_i'
        t_i = 0

        # Use a 'for' loop to compare each character in 'S_d' with the corresponding character in 'T'
        for s_i in range(first, end+1):
            # Check if the characters match or if 'S_d[s_i]' is a '?' symbol
            if T[t_i] != S_d[s_i] and S_d[s_i] != '?':
                # If they don't match, break the inner loop
                break
            # Increment 't_i' index
            t_i += 1

        # If the pattern is found, break the outer loop
        else:
            break

        # Decrement 'first' and 'end' indices
        first -= 1
        end -= 1

    # If the pattern is not found, print 'UNRESTORABLE' and exit the program
    else:
        print('UNRESTORABLE')
        exit(0)

    # Create a deep copy of 'S_d' list and assign it to 'ans'
    ans = copy.deepcopy(S_d)

    # Use a 'for' loop to replace the characters in 'ans' with the corresponding characters from 'T'
    t_i = 0
    for i in range(first, end+1):
        ans[i] = T[t_i]
        t_i += 1

    # Join all the elements in 'ans' list into a single string and replace '?' symbols with 'a'
    ans = ''.join(ans).replace('?','a')

    # Print the solution
    print(ans)

# Call the 'solve' function if the script is run as the main program
if __name__ == '__main__':
    solve()
