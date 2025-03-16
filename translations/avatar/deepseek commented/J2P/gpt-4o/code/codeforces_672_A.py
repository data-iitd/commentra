def generate_string():
    # This function generates a string of numbers from 1 to 1000
    return ''.join(str(i) for i in range(1, 1001))

# The main function reads an integer n from the user, and prints the nth character of the generated string
if __name__ == "__main__":
    n = int(input())
    generated_string = generate_string()
    print(generated_string[n - 1])

# <END-OF-CODE>
