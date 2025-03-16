# Importing necessary Python classes for reading input from the console and writing output to the console
import sys
import io

# Main method is the entry point of the Python application
def main():

    # Creating BufferedReader object to read input from the console
    br = io.BufferedReader(sys.stdin)

    # Creating PrintWriter object to write output to the console
    pw = io.PrintWriter(sys.stdout)

    # Reading input array from the console
    input_array = br.readline().split(" ")

    # Initializing result variable to 0
    result = 0

    # Iterating through each string in the input array
    for str in input_array:

        # Incrementing result variable for each non-zero string encountered
        result += 1

        # Breaking the loop if a zero string is encountered
        if "0".equals(str):
            break

    # Writing the result to the console
    pw.println(result)

    # Closing the BufferedReader and PrintWriter objects
    br.close()
    pw.close()

# Calling the main method
if __name__ == '__main__':
    main()

