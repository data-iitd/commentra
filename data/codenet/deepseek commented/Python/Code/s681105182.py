import sys
sys.setrecursionlimit(10**7)  # Setting the recursion limit to prevent deep recursion issues

def LI(): return [int(x) for x in sys.stdin.readline().split()]  # Function to read a list of integers
def LI_(): return [int(x) - 1 for x in sys.stdin.readline().split()]  # Function to read a list of integers and decrement each by 1
def LF(): return [float(x) for x in sys.stdin.readline().split()]  # Function to read a list of floats
def LS(): return sys.stdin.readline().split()  # Function to read a list of strings
def II(): return int(sys.stdin.readline())  # Function to read an integer
def SI(): return sys.stdin.readline().strip()  # Function to read a single string without newline

INF = 10 ** 18  # Constant for representing infinity
MOD = 10 ** 9 + 7  # Constant for a large prime number

def main(): 
    N = II()  # Read the number of elements
    a_li = LI()  # Read the list of elements

    a_li.sort()  # Sort the list of elements

    n = a_li[-1]  # The largest number in the list is assigned to n
    
    dif = INF  # Initialize the difference to a large value
    prev_dif = dif  # Initialize the previous difference to the same large value
    for a in a_li[:-1]:  # Iterate through the list except the last element
        dif = min(abs(n/2 - a), dif)  # Update the difference if a new minimum is found
        if dif != prev_dif:  # If the difference has changed
            r = a  # Assign the current number to r
            prev_dif = dif  # Update the previous difference

    print(n, r)  # Print the largest number and the closest number to half of the largest number

main()  # Call the main function
