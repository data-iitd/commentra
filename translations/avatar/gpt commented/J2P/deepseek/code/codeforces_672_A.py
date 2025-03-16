# Python version of the given Java code

def generate_string():
    # Creating an empty string to efficiently build the string
    s = ""
    
    # Looping through numbers 1 to 1000 and appending them to the string
    for i in range(1, 1001):
        s += str(i)  # Appending the current number to the string
    
    # Converting the built string to a character array and returning it
    return list(s)

# Main function to read an integer input and print the character at the (n-1)th index
def main():
    # Reading an integer input from the user
    n = int(input())
    
    # Printing the character at the (n-1)th index of the generated character array
    char_array = generate_string()
    print(char_array[n - 1])

# Calling the main function
if __name__ == "__main__":
    main()
