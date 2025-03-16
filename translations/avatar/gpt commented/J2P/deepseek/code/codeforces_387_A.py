from datetime import datetime, timedelta
import sys

def main():
    # Reading two time inputs in "HH:MM" format and splitting them into hours and minutes
    s = input().split(":")
    t = input().split(":")
    
    # Creating datetime objects from the input strings for the first and second time
    x = datetime.strptime(s[0] + ":" + s[1], "%H:%M")
    y = datetime.strptime(t[0] + ":" + t[1], "%H:%M")
    
    # Calculating the difference between the two times and printing the result
    difference = x - y
    print(difference)

if __name__ == "__main__":
    main()
