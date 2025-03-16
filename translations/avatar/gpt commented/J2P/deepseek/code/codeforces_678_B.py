import sys

def check_leap(y):
    return y % 400 == 0 or (y % 4 == 0 and y % 100 != 0)

def main():
    # Read the year input from the user
    y = int(input())
    
    # Initialize variables to keep track of the total days and the modulus
    sum_days = 0
    mod = 0
    
    # Start an infinite loop to find the next matching year
    i = y + 1
    while True:
        # Check if the current year is a leap year and add the corresponding days to sum
        if check_leap(i):
            sum_days += 366
        else:
            sum_days += 365
        
        # Check if the total number of days is a multiple of 7
        if sum_days % 7 == 0:
            # If the leap year status matches with the input year, print the year and exit
            if (check_leap(i) and check_leap(y)) or (not check_leap(i) and not check_leap(y)):
                print(i)
                return
            else:
                # Continue to the next iteration if the leap year status does not match
                i += 1
                continue
        i += 1

if __name__ == "__main__":
    main()
