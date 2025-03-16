# Import the sys module for reading input
import sys

def main():
    in_seconds = int(sys.stdin.readline().strip())  # Read an integer input from the user, which represents the total time in seconds

    # Calculate the number of hours
    h = in_seconds // 3600  # Divide the input value by 3600 to get the number of hours
    in_seconds %= 3600      # Update in_seconds to store the remainder of the division, which represents the remaining seconds

    # Calculate the number of minutes
    m = in_seconds // 60     # Divide the updated in_seconds value by 60 to get the number of minutes
    in_seconds %= 60         # Update in_seconds to store the remainder of the division, which represents the remaining seconds

    # The remaining value in in_seconds is the number of seconds
    s = in_seconds

    # Print the calculated hours, minutes, and seconds in the format "HH:MM:SS"
    print(f"{h}:{m}:{s}")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
