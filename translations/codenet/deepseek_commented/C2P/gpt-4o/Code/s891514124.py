# Include the standard input-output library

def main():  # Define the main function
    S = int(input())  # Read an integer input from the user and store it in S

    # Check if S is less than 60
    if S < 60:
        print(f"0:0:{S}")  # Print "0:0:S" if S is less than 60

    # Check if S is less than 3600
    elif S < 3600:
        print(f"0:{S // 60}:{S % 60}")  # Print "0:S//60:S%60" if S is less than 3600

    # If S is not less than 3600
    else:
        print(f"{S // 3600}:{(S % 3600) // 60}:{S % 60}")  # Print "S//3600:S%3600//60:S%60" if S is not less than 3600

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
