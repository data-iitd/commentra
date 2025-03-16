# Define the main function
def main():
    # Input reading: Read three integers N, D, and X from standard input
    N, D, X = map(int, input().split())
    
    # Array initialization: Create a list A to store the values
    A = [0] * 101
    
    # Reading values into array A
    for i in range(N):
        A[i] = int(input())
    
    # Calculating the number of chocolates
    num_of_chocolate = 0
    for i in range(N):
        days = 0
        counter = 0
        j = 0
        while True:
            days = j * A[i] + 1
            if days <= D:
                counter += 1
            else:
                break
            j += 1
        num_of_chocolate += counter
    
    # Adding extra chocolates
    num_of_chocolate += X
    
    # Output the result
    print(num_of_chocolate)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
