
import sys

def cout(str):
    print(str)

def main():
    # Creating a Scanner object to read input from the console
    cin = sys.stdin
    
    # Initializing variables to hold parts of the input string
    a = ""
    b = ""
    str = ""
    n = 0

    # Reading an integer input which represents the length of the string
    n = int(cin.readline())
    
    # Reading the actual string input
    str = cin.readline().strip()

    # Loop to construct the first half of the string
    for i in range(n // 2):
        a += str[i] # Appending characters from the first half of the string to 'a'

    # Checking if the string is made up of two identical halves
    if str == a + a:
        cout("Yes") # If true, print "Yes"
    else:
        cout("No") # If false, print "No"

if __name__ == "__main__":
    main()

