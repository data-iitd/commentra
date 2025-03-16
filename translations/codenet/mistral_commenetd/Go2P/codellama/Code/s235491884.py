# Package main is the entry point of the program
def main():
    # Declare a variable 's' of type string
    s = input()

    # Use 'str.count' to count the number of occurrences of the substring "o" in the string 's'
    n = s.count("o")

    # Calculate the result by adding 700 to the product of 100 and the number of occurrences of "o" in the string
    result = 700 + n*100
    # Use 'print' to print the result to the standard output
    print(result)

# The code ends here
