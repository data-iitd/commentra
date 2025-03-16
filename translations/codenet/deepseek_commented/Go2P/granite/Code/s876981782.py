
import sys

def main():
    N = int(input()) # Read the number of values
    values = [float(x) for x in input().split()] # Read the values into a list
    values.sort() # Sort the values in ascending order
    generated = 0
    for i in range(N-1):
        generated = (values[i] + values[i+1]) / 2 # Calculate the average of the current and next value
        values[i+1] = generated # Update the next value with the calculated average
    print(generated) # Print the final generated value

if __name__ == "__main__":
    main()

