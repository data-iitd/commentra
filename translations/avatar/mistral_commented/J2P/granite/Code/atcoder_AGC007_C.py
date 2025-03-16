

import decimal # Importing the decimal module for precise floating-point arithmetic

def main():
    decimal.getcontext().prec = 20 # Setting the precision of the output to 20 decimal places

    N = float(input()) # Reading the first input value from the user
    d = float(input()) # Reading the second input value from the user
    x = float(input()) # Reading the third input value from the user

    ans = 0.0 # Initializing an answer variable with zero value

    # Calculating the answer using the given formula
    while N > 0.5:
        adnum = (d + x * (N - 0.5)) # Calculating the next term of the sum
        ans += adnum # Adding the next term to the answer

        # Updating the values of d and x for the next iteration
        d = (N + 1.0) * d / N + (5.0 * x) / (2.0 * N)
        x = (1.0 + (2.0 / N)) * x

        N -= 1.0 # Decreasing the value of N by 1 for the next iteration

    # Printing the final answer with 20 decimal places
    print(format(ans, '.20f'))

if __name__ == "__main__":
    main()

These comments should provide a clear understanding of the code's functionality and logic.