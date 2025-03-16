# Include the standard input/output library

def main():
    S = int(input())  # Initialize an integer variable named S with a value read from the standard input

    # Print the hours, minutes, and seconds of the given number of seconds
    print(f"{S // 3600}:{(S % 3600) // 60}:{S % 60}")

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
