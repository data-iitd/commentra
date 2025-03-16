# Importing the necessary modules
import sys

def main():
    # Initializing a list to store the input strings
    sc_list = []

    # Continuously read input lines until EOF
    for line in sys.stdin:
        sc_list.append(line.strip())

    # Splitting the first line of input into a list of strings
    numlist = sc_list[0].split()
    
    # Parsing the first number as the count of sheep
    sheep = int(numlist[0])
    
    # Parsing the second number as the count of wolves
    wolve = int(numlist[1])

    # Checking if the number of wolves is greater than or equal to the number of sheep
    if wolve >= sheep:
        # If wolves are greater than or equal to sheep, it's unsafe
        print("unsafe")
    else:
        # If wolves are fewer than sheep, it's safe
        print("safe")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
