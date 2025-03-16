# Import the sys module for reading user input
import sys

def main():
    # Read the values of T, S, and q from the user input
    T = int(sys.stdin.readline().strip())
    S = int(sys.stdin.readline().strip())
    q = int(sys.stdin.readline().strip())
    
    # Initialize the variable `previous` with the value of S
    previous = S
    
    # Initialize the variable `answer` with the value 0
    answer = 0
    
    # Enter a while loop that continues until `previous` is less than T
    while previous < T:
        # Inside the loop, multiply `previous` by q and increment the `answer` by 1
        previous *= q
        answer += 1
    
    # After the loop, print the value of `answer`
    print(answer)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
