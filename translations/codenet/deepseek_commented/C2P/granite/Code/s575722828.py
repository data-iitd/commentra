
import sys # Step 1: Import necessary modules

def main(): # Step 2: Define the main function
    S = int(sys.stdin.read()) # Step 3: Read an integer value from the user and store it in S

    hours = S // 3600 # Step 4: Calculate hours from the total seconds S
    minutes = (S % 3600) // 60 # Step 5: Calculate minutes from the remaining seconds after dividing by 3600
    seconds = S % 60 # Step 6: Calculate seconds from the remaining seconds after dividing by 3600

    print(f"{hours}:{minutes}:{seconds}") # Step 7: Print the calculated hours, minutes, and seconds in the format "HH:MM:SS"

if __name__ == "__main__": # Step 8: Call the main function if the script is executed directly
    main()

