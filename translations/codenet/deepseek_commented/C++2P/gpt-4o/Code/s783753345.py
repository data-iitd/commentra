# Main function where the program execution begins
def main():
    # Infinite loop to continuously take input and perform operations
    while True:
        # Take input in the format a S b
        user_input = input().split()
        a = int(user_input[0])
        S = user_input[1]
        b = int(user_input[2])
        
        # Perform operations based on the value of S
        if S == '+':
            print(a + b)
        elif S == '-':
            print(a - b)
        elif S == '*':
            print(a * b)
        elif S == '/':
            print(a // b)  # Use integer division for consistency with C++
        
        # Break the loop if S is '?'
        if S == '?':
            break

# Call the main function to execute the program
main()

# <END-OF-CODE>
