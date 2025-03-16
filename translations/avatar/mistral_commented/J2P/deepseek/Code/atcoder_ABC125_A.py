def main():
    # Read three integers from the standard input: the number of seconds, the number of periods, and the total number of seconds
    sec = int(input())  # Read the number of seconds
    per_num = int(input())  # Read the number of periods
    max_sec = float(input())  # Read the total number of seconds and convert it to float

    # Initialize a counter variable ans_num to zero
    ans_num = 0

    # Start a for loop that runs from the initial value sec to the final value max_sec with a step size of sec. In each iteration of the loop, add per_num to ans_num
    for i in range(sec, int(max_sec) + 1, sec):
        ans_num += per_num

    # Print the result ans_num to the standard output stream
    print(ans_num)


# Call the main function
main()
