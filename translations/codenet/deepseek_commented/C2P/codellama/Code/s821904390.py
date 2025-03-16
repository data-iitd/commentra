#include <stdio.h>  # Include the standard input/output library for using printf and scanf

int main():
    in = int(input())  # Read an integer input from the user, which represents the total time in seconds

    # Calculate the number of hours
    h = in // 3600  # Divide the input value by 3600 to get the number of hours
    in %= 3600  # Update in to store the remainder of the division, which represents the remaining seconds

    # Calculate the number of minutes
    m = in // 60  # Divide the updated in value by 60 to get the number of minutes
    in %= 60  # Update in to store the remainder of the division, which represents the remaining seconds

    # The remaining value in in is the number of seconds
    s = in

    # Print the calculated hours, minutes, and seconds in the format "HH:MM:SS"
    print(f"{h}:{m}:{s}")

