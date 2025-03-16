
# Python code to find the length of the shortest substring of S that matches T with all characters

# Function to read input from stdin
def read_int():
    return int(input())

def read_ints():
    return list(map(int, input().split()))

def read_str():
    return input()

# Main function
def main():
    # Read input strings S and T
    S = read_str()
    T = read_str()

    # Initialize max as 0
    max_count = 0

    # Loop through all possible substrings of S with length equal to T
    for i in range(len(S) - len(T) + 1):
        # Initialize a counter c for the number of matching characters between S[i:i+len(T)] and T
        count = 0

        # Check character by character for matching characters
        for j in range(len(T)):
            # If current characters match, increment counter c
            if S[i+j] == T[j]:
                count += 1

        # If current substring has more matching characters than the current max, update max
        if max_count < count:
            max_count = count

    # Print the length of the shortest substring of S that matches T with all characters
    print(len(T) - max_count)

# Call the main function
if __name__ == "__main__":
    main()

