
# Package main is the entry point of the program
import sys

# ReadLongLines function reads long lines from standard input
def ReadLongLines(times):
    # Initialize result list with the given size
    result = [None] * times
    # Initialize a new buffered reader
    reader = sys.stdin
    # Initialize a new bytes.Buffer
    buffer = b""
    # Initialize readBytes variable to keep track of the total number of bytes read
    readBytes = 2

    # For each iteration, read a line from the standard input
    for i in range(times):
        # Read a line from the standard input
        for line in reader:
            # Write the read line to the buffer
            buffer += line
            # Check if the line read is the last line of the input
            if not line.endswith(b"\n"):
                # Store the content of the line in the result list
                result[i] = buffer.decode("utf-8")
                # Reset the buffer for the next iteration
                buffer = b""
                # Break the inner loop if the line read is the last line of the input
                break

    # Return the result and nil error
    return result, None

# Console type is used to manage the standard output
class Console:
    # NewConsole function initializes a new Console instance
    def __init__(self):
        # Initialize a new Console instance with the standard output as the writer
        self.writer = sys.stdout

    # Printf function prints formatted strings to the Console writer
    def Printf(self, format, *args):
        # Format and print the given arguments to the Console writer
        print(format % args, file=self.writer)

    # Println function prints a newline character followed by the given string to the Console writer
    def Println(self, s):
        # Format and print the given string followed by a newline character to the Console writer
        print(s, file=self.writer)

    # Close function flushes the Console writer and closes it
    def Close(self):
        # Flush and close the Console writer
        self.Flush()

    # Flush function flushes the Console writer
    def Flush(self):
        # Flush the Console writer
        self.writer.flush()

# PrintList function prints an integer slice to the standard output
def PrintList(list):
    # Initialize a new Console instance
    con = Console()
    # Defer the Flush function to be called when the function returns
    defer con.Flush()
    # Iterate through the given integer slice and print each element to the standard output
    for i in range(len(list)):
        # If it's the first element, print it without a separator
        if i == 0:
            con.Printf("%d", list[i])
        else:
            # Otherwise, print it with a separator
            con.Printf(" %d", list[i])
    # Print a newline character to the standard output
    con.Println("")

# main function is the entry point of the program
def main():
    # Initialize a new Console instance
    con = Console()
    # Defer the Flush function to be called when the function returns
    defer con.Flush()

    # Initialize an empty map to store unique integers
    m = {}
    # Read long lines from the standard input
    lines, _ = ReadLongLines(4)
    # Split the second line into an integer slice
    a = lines[1].split()
    # Iterate through the integer slice and add each integer to the map
    for i in range(len(a)):
        # Parse the integer from the string and add it to the map
        n = int(a[i])
        m[n] = None

    # Read integers from the fourth line and add them to the map if they are not already present
    b = lines[3].split()
    for i in range(len(b)):
        # Parse the integer from the string and add it to the map if it's not already present
        n = int(b[i])
        if n not in m:
            m[n] = None

    # Extract the unique integers from the map and store them in a slice
    result = []
    for k, _ in m.items():
        # Append the integer to the result slice
        result.append(k)

    # Sort the result slice in ascending order
    result.sort()

    # Iterate through the sorted result slice and print each integer to the standard output
    for j in range(len(result)):
        # Print each integer to the standard output
        con.Printf("%d\n", result[j])

# 