# Define the main function
def main():
    # Read the input string from the user
    str_input = input()
    
    # Initialize a variable to hold the sum of digits
    total_sum = 0
    
    # Iterate through each character in the string
    for char in str_input:
        # Convert character to integer and add to total_sum
        total_sum += int(char)  # Convert character to integer directly
    
    # Check if the sum of digits is divisible by 9
    if total_sum % 9 == 0:
        # If divisible, print "Yes"
        print("Yes")
    else:
        # If not divisible, print "No"
        print("No")

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
