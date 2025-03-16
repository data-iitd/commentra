# Importing the necessary modules
import sys

def main():
    # Reading an integer value from the user input
    y = int(input())

    # Checking if the given year is a leap year or not
    leap = check_leap(y)

    # Initializing the sum variable to 0
    sum_days = 0

    # Starting the loop from the year + 1
    for i in range(y + 1, sys.maxsize):
        # Checking if the current year is a leap year or not
        if check_leap(i):
            # If the current year is a leap year and the previous year was also a leap year,
            # then print the current year and exit the loop
            if (leap and check_leap(i)) or (not leap and not check_leap(i)):
                print(i)
                return
            sum_days += 366
        else:
            # If the current year is not a leap year, then add 365 to the sum
            sum_days += 365

        # Checking if the sum is divisible by 7
        if sum_days % 7 == 0:
            # If the current year is a leap year and the previous year was also a leap year,
            # or if the current year is not a leap year and the previous year was not a leap year,
            # then continue to the next iteration of the loop
            if (leap and check_leap(i)) or (not leap and not check_leap(i)):
                continue

            # If the conditions are not met, then print the current year and exit the loop
            print(i)
            return

# A static method to check if a given year is a leap year or not
def check_leap(y):
    # Returning true if the given year is divisible by 400, or if it is divisible by 4 and not divisible by 100
    return y % 400 == 0 or (y % 4 == 0 and y % 100 != 0)

# Entry point of the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
