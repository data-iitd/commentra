# Python 2
import sys

# Python 3
# import sys

# Function to solve the problem
def solve():
    # Initialize variables to track the longest string and its count
    maxsize=0
    maxcnt=0
    ans_num=0 # Index of the longest string
    ans_num2=0 # Index of the most frequent string
    str_v=[] # Vector to store input strings
    
    # Variable to read input strings
    in_str = sys.stdin.readline()
    while in_str:
        str_v.append(in_str) # Store the input string in the vector
        if(maxsize < len(in_str)): # Check if the current string is the longest so far
            maxsize = len(in_str) # Update the length of the longest string
            ans_num = len(str_v)-1 # Store the index of the longest string
        in_str = sys.stdin.readline()
    
    # Count occurrences of each string and find the most frequent string
    for i in range(len(str_v)):
        cnt=0
        for j in range(len(str_v)):
            if(str_v[i] == str_v[j]) cnt+=1 # Count occurrences of the current string
        if(maxcnt < cnt): # Check if the current string is the most frequent so far
            maxcnt = cnt # Update the count of the most frequent string
            ans_num2 = i # Store the index of the most frequent string
    
    # Output the most frequent and the longest string
    print str_v[ans_num2], str_v[ans_num]
    
    return True # Return true indicating success

# Main function to set precision and call the solve function
if __name__ == "__main__":
    # Set precision
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')
    sys.setrecursionlimit(100000)
    # Call the solve function
    solve()
    # Close the files
    sys.stdin.close()
    sys.stdout.close()

