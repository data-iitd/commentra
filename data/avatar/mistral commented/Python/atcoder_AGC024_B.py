#######
# This is the main function that is called when we run the script.
# It takes an input of an integer N and a list P of N integers as arguments.
# It then calls the editorial function with these arguments.
def main():
    # Read the number of test cases N from the standard input.
    N = int(input())
    # Read N integers from the standard input and store them in a list P.
    P = [int(input()) for _ in range(N)]
    # Call the editorial function with N and P as arguments.
    editorial(N, P)

# This function calculates the answer based on the given input.
def editorial(N, P):
    # Base case: if there is only one element in the list, the answer is 0.
    if N == 1:
        print(0)
        return
    # Initialize an array a of size N+1 with all elements initialized to 0.
    a = [0] * (N + 1)
    # Iterate through the list P and assign each element its index in the array a.
    for i, p in enumerate(P):
        a[p] = i
    # Initialize two variables: tmp to keep track of the current streak,
    # and max_len to keep track of the maximum streak.
    tmp = 1
    max_len = 1
    # Iterate through the array a from the second element to the last.
    for i in range(1, N):
        # If the current element has a smaller index than the previous one,
        # increment the streak and update max_len if necessary.
        if a[i] < a[i + 1]:
            tmp += 1
            max_len = max(max_len, tmp)
        # Otherwise, reset the streak to 1.
        else:
            tmp = 1
    # Calculate the answer as the difference between the total number of elements
    # and the maximum streak.
    ans = N - max_len
    # Print the answer.
    print(ans)

# This function is used for testing purposes and is not called in the main function.
def WA(N, P):
    # Initialize two variables: tmp to keep track of the current streak,
    # and ans to keep track of the maximum answer.
    tmp = 0
    ans = 0
    # Iterate through the list P and calculate the answer based on the current streak.
    for i, p in enumerate(P):
        # If the current element is the first one or its previous element plus one,
        # increment the streak and update ans if necessary.
        if i == 0 or P[i - 1] + 1 == p:
            tmp += 1
            ans = max(ans, tmp)
        # Otherwise, reset the streak to 1.
        else:
            tmp = 1
    # Print the answer.
    print(N - ans)

# This line is executed only if the script is run as the main module, not imported as a module.
if __name__ == '__main__':
    # Call the main function.
    main()
