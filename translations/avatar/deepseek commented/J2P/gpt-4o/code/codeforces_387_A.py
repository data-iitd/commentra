from datetime import time

def main():
    # Step 1: Read two times from the user, split by colon and convert to time objects
    s = input().split(":")
    t = input().split(":")
    x = time(int(s[0]), int(s[1]))
    y = time(int(t[0]), int(t[1]))

    # Step 2: Calculate the difference between the two times
    # Since time objects do not support direct subtraction, we will convert them to minutes
    x_minutes = x.hour * 60 + x.minute
    y_minutes = y.hour * 60 + y.minute
    difference = x_minutes - y_minutes

    # Output the difference in hours and minutes
    hours = difference // 60
    minutes = difference % 60
    print(f"{hours} hours and {minutes} minutes")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
