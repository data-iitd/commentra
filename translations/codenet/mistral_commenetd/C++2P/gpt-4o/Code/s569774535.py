# Main function starts here
def main():
    n = int(input())  # Read the number of elements from the standard input

    # Read 'n' integers from the standard input and store them in the list 'a'
    a = list(map(int, input().split()))

    ans = 0  # Initialize a variable 'ans' to store the answer

    # Main logic of the program starts here
    while True:
        for i in range(n):  # Iterate through all the elements in the list 'a'
            if a[i] % 2 == 1:  # Check if the 'i'-th element of the list 'a' is odd
                print(ans)  # If yes, print the answer and exit the program
                return
            else:  # If the 'i'-th element of the list 'a' is even, divide it by 2
                a[i] //= 2
        ans += 1  # Increment the answer by 1 for each iteration of the outer loop

    # Print the final answer if all elements in the list 'a' become even
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
