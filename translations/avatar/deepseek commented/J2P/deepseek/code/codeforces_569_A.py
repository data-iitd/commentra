def main():
    # Read the values of T, S, and q from the user input
    T, S, q = map(int, input().split())
    
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

# Call the main function
main()

