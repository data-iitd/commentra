from datetime import time  # Import the time class for handling time
import sys  # Import sys for handling input/output exceptions

def main():
    # Read the first time string from the console and split it into hour and minute parts
    s = input().split(":")

    # Read the second time string from the console and split it into hour and minute parts
    t = input().split(":")

    # Create time objects `x` and `y` from the hour and minute parts of the first and second time strings, respectively
    x = time(int(s[0]), int(s[1]))
    y = time(int(t[0]), int(t[1]))

    # Calculate the difference in minutes
    x_minutes = x.hour * 60 + x.minute
    y_minutes = y.hour * 60 + y.minute
    difference = x_minutes - y_minutes

    # Convert the difference back to hours and minutes
    hours = difference // 60
    minutes = difference % 60

    # Print the result
    print(f"{hours}:{minutes:02d}")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
