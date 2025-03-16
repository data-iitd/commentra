import sys  # Importing sys for input operations

def main():
    # Reading input and splitting it by spaces
    str_input = sys.stdin.read().strip().split()
    h = int(str_input[0])  # Parsing the first element to an integer representing the height
    a = int(str_input[1])  # Parsing the second element to an integer representing the amount to subtract
    num = 0  # Initializing a counter to keep track of the number of subtractions

    # Implementing a loop to subtract 'a' from 'h' until 'h' is less than or equal to 0
    while h > 0:
        h -= a  # Subtracting 'a' from 'h'
        num += 1  # Incrementing the counter

    print(num)  # Printing the result, which is the number of subtractions

if __name__ == "__main__":
    main()

# <END-OF-CODE>
