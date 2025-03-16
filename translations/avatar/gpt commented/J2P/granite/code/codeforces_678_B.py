
import datetime

def check_leap(y):
    return y % 400 == 0 or (y % 4 == 0 and y % 100!= 0)

def main():
    # Create a Scanner object to read input from the user
    y = int(input())

    # Check if the input year is a leap year
    leap = check_leap(y)

    # Initialize variables to keep track of the total days and the modulus
    sum = 0
    mod = 0

    # Start an infinite loop to find the next matching year
    for i in range(y + 1, 10000):
        # Check if the current year is a leap year and add the corresponding days to sum
        if check_leap(i):
            sum += 366
        else:
            sum += 365

        # Check if the total number of days is a multiple of 7
        if sum % 7 == 0:
            # If the leap year status matches with the input year, print the year and exit
            if (check_leap(i) and leap) or (not check_leap(i) and not leap):
                print(i)
                return
            else:
                # Continue to the next iteration if the leap year status does not match
                continue

if __name__ == "__main__":
    main()

