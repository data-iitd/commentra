
# Import the BufferedReader class from the java.io package
from java.io import BufferedReader

# Import the InputStreamReader class from the java.io package
from java.io import InputStreamReader

# Import the Integer class from the java package
from java.lang import Integer

# Define a function to read input from the console
def read_input():
    # Create a BufferedReader to read input from the console
    buf = BufferedReader(InputStreamReader(System.in))

    # Read the first line of input and split it into an array of strings
    inp = buf.readLine().split("")

    # Parse the first two elements of the input array as integers n and m
    n = Integer.parseInt(inp[0])
    m = Integer.parseInt(inp[1])

    # Initialize an array to hold the resulting strings
    ans = [""] * n

    # Loop through each of the n lines of input
    for i in range(n):
        # Read the current line of input
        str = buf.readLine()

        # Create a StringBuilder to construct the output for the current line
        temp = StringBuilder("")

        # Loop through each character in the current line
        for j in range(m):
            # Check if the character is a '-'
            if str.charAt(j) == "-":
                # Append '-' to the StringBuilder if it is
                temp.append("-")
            else:
                # If the character is not '-', determine whether to append 'W' or 'B'
                if (i + j) % 2 == 1:
                    temp.append("W")  # Append 'W' for odd indices
                else:
                    temp.append("B")  # Append 'B' for even indices

        # Store the constructed string in the ans array
        ans[i] = temp.toString()

    # Output the resulting strings line by line
    for i in range(n):
        print(ans[i])


# Call the read_input function
read_input()

# End of code
