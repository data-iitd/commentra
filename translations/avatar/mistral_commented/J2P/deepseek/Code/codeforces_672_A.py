def generate_string():
    sb = ""  # Create an empty string

    # Use a for loop to append numbers from 1 to 1000 to the string
    for i in range(1, 1001):
        sb += str(i)  # Append the current number to the string

    # Convert the string to a character array and return it
    return list(sb)

# Define the main function that reads user input and prints the result
def main():
    sc = input()  # Read an integer value from the user input
    n = int(sc)

    # Print the character at the specified index of the generated string
    generated_string = generate_string()
    print(generated_string[n - 1])

main()
