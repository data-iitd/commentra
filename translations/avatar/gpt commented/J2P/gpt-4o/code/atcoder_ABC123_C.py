import math

def main():
    # Read a long integer N from user input
    N = int(input())
    
    # Initialize a variable to hold the minimum value
    min_value = None
    
    # Loop to read five long integers and find the minimum
    for i in range(5):
        value = int(input())
        # For the first iteration, directly assign the value to min_value
        if min_value is None:
            min_value = value
        else:
            # For subsequent iterations, update min_value if a smaller value is found
            min_value = min(min_value, value)
    
    # Calculate the result by dividing N by min_value, rounding up, and adding 4
    result = math.ceil(N / min_value) + 4
    p(result)

# Overloaded print function to handle different types
def p(ans):
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
