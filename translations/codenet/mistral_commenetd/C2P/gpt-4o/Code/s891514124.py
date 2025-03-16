# The main function is the entry point of the program
def main():
    S = int(input())  # Read an integer value from the standard input

    # Check if the value of S is less than 60
    if S < 60:
        # If the condition is true, print the time in the format "0:0:S"
        print(f"0:0:{S}")
    
    # Else if the value of S is less than 3600 (1 hour)
    elif S < 3600:
        # Print the time in the format "0:M:S"
        print(f"0:{S // 60}:{S % 60}")
    
    # Else if the value of S is greater than or equal to 3600
    else:
        # Print the time in the format "H:M:S"
        print(f"{S // 3600}:{(S % 3600) // 60}:{S % 60}")

# Call the main function to execute the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
