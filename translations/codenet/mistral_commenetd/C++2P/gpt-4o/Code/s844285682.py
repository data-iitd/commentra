# Import the sys module
import sys

def main():
    a = int(input("Enter the number of seconds: "))  # Read an integer value from the user
    
    hours = a // (60 * 60)  # Extract the hours from the number of seconds
    minutes = (a % (60 * 60)) // 60  # Extract the minutes from the remaining seconds
    seconds = (a % (60 * 60)) % 60  # Extract the seconds from the remaining seconds
    
    print(f"{hours}:{minutes}:{seconds}")  # Print the time representation of the number of seconds

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
