# Importing the sys module for input operations.
import sys

def main():
    # Reading the first integer input which seems to be a time interval.
    sec = int(sys.stdin.readline().strip())
    # Reading the second integer input which is a number to be added per iteration.
    per_num = int(sys.stdin.readline().strip())
    # Reading the third integer input and adding 0.5 to it.
    max_sec = int(sys.stdin.readline().strip()) + 0.5
    
    # Initializing the variable to store the result of additions.
    ans_num = 0
    
    # Loop to iterate from 'sec' to 'max_sec' in steps of 'sec' and add 'per_num' to 'ans_num' each time.
    for i in range(sec, int(max_sec), sec):
        ans_num += per_num
    
    # Printing the final result after the loop completes.
    print(ans_num)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
