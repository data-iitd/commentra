import sys

# Function to read a single integer from standard input
def I():
    return (int(sys.stdin.readline()))

# Function to read a list of integers from standard input
def LI():
    return ([int(x) for x in sys.stdin.readline().split()])

def main():
    # Read the number of elements
    N = I()
    
    # Read the list of integers, sort it in descending order
    S = sorted(LI(), reverse=True)
    
    # Initialize a flag list to track which elements have been used
    flag = [True] * len(S)
    
    # Initialize the current list with the largest element
    cur = []
    cur.append(S[0])
    
    # Mark the first element as used
    flag[0] = False
    
    # Iterate N times to build the current list
    for i in range(N):
        j = 0  # Index for the current list
        jM = len(cur)  # Length of the current list
        
        # Try to find the next largest unused element
        for k in range(len(S)):
            # Check if the current element is unused and smaller than the last added element
            if flag[k] and S[k] < cur[j]:
                cur.append(S[k])  # Add the element to the current list
                j += 1  # Move to the next index in the current list
                flag[k] = False  # Mark this element as used
                
                # If we have added enough elements, break out of the loop
                if j == jM:
                    break
        else:
            # If we couldn't find a suitable element, return "No"
            return "No"
        
        # Sort the current list in descending order for the next iteration
        cur.sort(reverse=True)
    
    # If we successfully built the list, return "Yes"
    return "Yes"

# Entry point of the program
if __name__ == "__main__":
    # Print the result of the main function
    print(main())
