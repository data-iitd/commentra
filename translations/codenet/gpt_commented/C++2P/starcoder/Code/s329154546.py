# Define a long long type for convenience
# Define a long long type for convenience

# Macros for loop iterations
# Macros for loop iterations

# Macros for input and output
# Macros for input and output

# Function to update the maximum value
# Function to update the maximum value

# Function to update the minimum value
# Function to update the minimum value

# Global variables for number of strings and their length
# Global variables for number of strings and their length

# Function to sort the array of strings in lexicographical order
def sort_strings(S):
    # Sort the array of strings in lexicographical order
    S.sort()
    return S

# Function to input the strings from the user
def input_strings(S):
    # Input the strings from the user
    for i in range(N):
        S.append(input())
    return S

# Function to output the sorted strings
def output_strings(S):
    # Output the sorted strings
    for i in range(N):
        print(S[i])
    return

# Main function
def main():
    # Read the number of strings (N) and the length of each string (L)
    global N, L
    in(N)
    in(L)

    # Declare an array to hold the strings
    S = []

    # Input the strings from the user
    input_strings(S)

    # Sort the array of strings in lexicographical order
    S = sort_strings(S)

    # Output the sorted strings
    output_strings(S)

    # Print a newline at the end of the output
    print()

# Main function
if __name__ == "__main__":
    main()

