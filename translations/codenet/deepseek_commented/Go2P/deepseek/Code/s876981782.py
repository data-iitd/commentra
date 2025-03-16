def main():
    N = int(input())  # Read the number of values
    values = list(map(float, input().split()))  # Read the values into a list

    values.sort()  # Sort the values in ascending order
    for i in range(N - 1):
        generated = (values[i] + values[i + 1]) / 2  # Calculate the average of the current and next value
        values[i + 1] = generated  # Update the next value with the calculated average

    print(generated)  # Print the final generated value

main()
