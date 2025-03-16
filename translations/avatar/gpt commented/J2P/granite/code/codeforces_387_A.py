
import datetime # Importing datetime module to work with date and time

def main():
    # Reading two time inputs in "HH:MM" format and splitting them into hours and minutes
    s = input().split(":") 
    t = input().split(":") 

    # Creating datetime.time objects from the input strings for the first and second time
    x = datetime.time(int(s[0]), int(s[1])) 
    y = datetime.time(int(t[0]), int(t[1])) 

    # Calculating the difference between the two times and printing the result
    print(x - y) 

if __name__ == "__main__":
    main()

