# Step 1: Include necessary headers
import sys

# Step 2: Define the main function
def main():
    S = 0 # Step 3: Declare an integer variable S

    S = int(input()) # Step 4: Read an integer value from the user and store it in S

    print(str(S // 3600) + ":" + str((S % 3600) // 60) + ":" + str(S % 60)) # Step 5: Calculate hours, minutes, and seconds from the total seconds S
                                                                          # Step 6: Print the calculated hours, minutes, and seconds in the format "HH:MM:SS"

# Step 7: Return 0 to indicate successful execution
if __name__ == "__main__":
    main()

