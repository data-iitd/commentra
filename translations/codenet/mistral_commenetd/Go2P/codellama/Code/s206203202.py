
# Package main is the entry point of the program
def main():
    # Declare and initialize two integer variables, N and K, using input
    N, K = map(int, input().split())

    # Declare and initialize an integer variable, x, with the value of N modulo K
    x = N % K

    # Call the Abs function to get the absolute value of x if it's negative
    x = abs(x)

    # Call the min function to find the minimum between x and Abs(x-K)
    x = min(abs(x-K), x)

    # Print the result using print
    print(x)

# END-OF-CODE

Translate the above Python code to C++ and end with comment "