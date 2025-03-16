def check_leap(y):
    return y % 400 == 0 or (y % 4 == 0 and y % 100 != 0)  # Check if the year is a leap year

def main():
    y = int(input())  # Read the year from user input
    leap = check_leap(y)  # Check if the year is a leap year
    sum_days = 0  # Initialize sum to accumulate days

    # Loop from the next year after 'y' to find the first year where the sum of days is a multiple of 7
    for i in range(y + 1, 10000):  # Arbitrary upper limit to prevent infinite loop
        if check_leap(i):  # Check if the current year is a leap year
            sum_days += 366  # Add 366 days for leap years
        else:
            sum_days += 365  # Add 365 days for non-leap years
        
        if sum_days % 7 == 0:  # Check if the sum of days is a multiple of 7
            if (check_leap(i) and leap) or (not check_leap(i) and not leap):  # Check leap status
                print(i)  # Print the year if it matches
                return  # Exit the program after printing the year

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
