# Importing necessary modules
import sys

def main():
    # Reading long value from the console and assigning it to 'a'
    a = int(input().strip())

    # Reading String value from the console and assigning it to 'b'
    b = input().strip()

    # Converting String 'b' to a character list and filtering out '.'
    bStr = ''.join([char for char in b if char != '.'])

    # Converting filtered String 'bStr' to integer and assigning it to 'bInt'
    bInt = int(bStr)

    # Multiplying 'a' with 'bInt', then dividing the result by 100 and assigning it to 'result'
    result = (a * bInt) // 100

    # Printing the value of 'result' to the console
    print(result)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
