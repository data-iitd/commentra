
import sys

# Function to read an integer from standard input
def I():
    return int(sys.stdin.readline())

# Function to read a list of integers from standard input
def LI():
    return [int(x) for x in sys.stdin.readline().split()]

def main():
    # Read the number of elements N
    N = I()
    
    # Read the list of integers S, sort them in descending order
    S = sorted(LI(), reverse=True)
    
    # Initialize a flag array to keep track of used elements
    flag = [True] * len(S)
    
    # Initialize the current list with the first element of S
    cur = []
    cur.append(S[0])
    
    # Set the flag for the first element to False
    flag[0] = False
    
    # Loop through N times
    for i in range(N):
        j = 0
        jM = len(cur)
        
        # Iterate over the elements of S
        for k in range(len(S)):
            if flag[k] and S[k] < cur[j]:
                # Add the element to cur, set its flag to False, and increment j
                cur.append(S[k])
                j += 1
                flag[k] = False
                if j == jM:
                    break
        
        # If no such element is found, return "No"
        else:
            return "No"
        
        # Sort cur in descending order
        cur.sort(reverse=True)
    
    # Return "Yes" if the condition is satisfied
    return "Yes"

if __name__ == "__main__":
    # Print the result of the main function
    print(main())