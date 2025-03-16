import math

def main():
    # Read the value of N
    N = int(input())

    # Initialize min to 0 and find the minimum of the first five inputs
    min_value = None
    for i in range(5):
        current_input = int(input())
        if min_value is None:
            min_value = current_input
        else:
            min_value = min(min_value, current_input)

    # Calculate the result and print it
    result = math.ceil(N / min_value) + 4
    p(result)

# Overloaded print methods to handle different data types
def p(ans):
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
