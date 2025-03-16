import sys

# Initialize week array
week = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"]

# Function to read a single line of input as string
def get_string():
    return sys.stdin.readline().strip()

# Main function
def main():
    # Read input string
    s = get_string()

    # Find index of the given day in week array
    if s in week:
        index = week.index(s)
    else:
        raise ValueError("Invalid day of the week")

    # Calculate the number of days until Sunday and print the result
    days_until_sunday = 7 - index
    print(days_until_sunday)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
