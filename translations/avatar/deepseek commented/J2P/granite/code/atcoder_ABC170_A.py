
import sys  # Importing sys module for input and output operations

def main():
    input_array = sys.stdin.readline().split()  # Reading input and splitting it into a list of strings
    result = 0  # Initializing a variable to store the count of non-zero elements

    # Iterating through the list and updating the result
    for str in input_array:
        result += 1  # Incrementing the result for each element
        if str == "0": break  # Breaking the loop if a zero is encountered

    print(result)  # Printing the result to the console

if __name__ == "__main__":
    main()

