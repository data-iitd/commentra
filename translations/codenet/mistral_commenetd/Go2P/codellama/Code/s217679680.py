
# Initialize a scanner for reading input from stdin
stdin = input()

# Function to read an array of integers from stdin and return it
def scanArrayInt():
    # Initialize an empty list to store the integers
    ret = []
    # Split the input line by space
    input = stdin.split(" ")
    # Iterate through each element in the input list and convert it to integer
    for s in input:
        # Convert the string to integer and append it to the list
        i = int(s)
        ret.append(i)
    # Return the list of integers
    return ret

# Function to initialize variables and start the main logic
def main():
    # Read the array of integers from stdin
    arr = scanArrayInt()
    # Initialize variables a and b with the first two elements of the array
    a, b = arr[0], arr[1]
    # Initialize variables tap and consent with default values
    tap, consent = 0, 1
    # Loop until consent is greater than or equal to b
    while consent < b:
        # Increment consent by the sum of a and consent minus one
        consent = consent + a - 1
        # Increment tap by one for each iteration
        tap += 1
    # Print the result, i.e., the number of taps required
    print(tap)

# Call the main function
main()

