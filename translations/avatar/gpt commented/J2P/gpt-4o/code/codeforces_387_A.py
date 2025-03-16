from datetime import datetime, timedelta  # Importing datetime and timedelta for time manipulation

def main():
    # Reading two time inputs in "HH:MM" format
    s = input().strip()  # First time input
    t = input().strip()  # Second time input
    
    # Creating datetime objects from the input strings for the first and second time
    x = datetime.strptime(s, "%H:%M")  # Parsing the first time
    y = datetime.strptime(t, "%H:%M")  # Parsing the second time
    
    # Calculating the difference between the two times
    difference = x - timedelta(hours=y.hour, minutes=y.minute)
    
    # Printing the result
    print(difference.time())  # Outputting the time part of the difference

if __name__ == "__main__":
    main()

# <END-OF-CODE>
