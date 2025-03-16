# Step 1: Import necessary modules

def main():  # Step 2: Define the main function
    S = int(input())  # Step 3: Read an integer value from the user and store it in S

    # Step 5: Calculate hours, minutes, and seconds from the total seconds S
    hours = S // 3600
    minutes = (S % 3600) // 60
    seconds = S % 60

    # Step 6: Print the calculated hours, minutes, and seconds in the format "HH:MM:SS"
    print(f"{hours}:{minutes}:{seconds}")

if __name__ == "__main__":  # Ensure the main function runs when the script is executed
    main()

# Step 7: Return 0 to indicate successful execution (not needed in Python)
# <END-OF-CODE>
