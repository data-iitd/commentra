# Importing the Scanner class for user input (in Python, we use the built-in input function)

def main():
    # Reading three integer values from user input
    pandu = int(input())  # The first input value
    vundu = int(input())  # The second input value
    urdu = int(input())   # The third input value
    
    # Calculating the cumulative sum of 'pandu' multiplied by each integer from 1 to 'urdu'
    c = 0
    for i in range(1, urdu + 1):
        c += i * pandu  # Incrementing 'c' by the product of 'i' and 'pandu'
    
    # Checking if the calculated sum 'c' is less than 'vundu'
    if c < vundu:
        print("0")  # If true, print "0"
    else:
        # If 'c' is greater than or equal to 'vundu', print the difference
        print(c - vundu)

# Calling the main function to execute the program
if __name__ == "__main__":
    main()
