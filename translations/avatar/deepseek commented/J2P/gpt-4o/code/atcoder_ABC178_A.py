import sys

def main():
    x = int(input())  # Read an integer from the input
    bool_value = x == 1  # Convert the integer x to a boolean value
    result = 0 if bool_value else 1  # Calculate the result based on the boolean value
    print(result)  # Print the result

if __name__ == "__main__":
    main()

# <END-OF-CODE>
