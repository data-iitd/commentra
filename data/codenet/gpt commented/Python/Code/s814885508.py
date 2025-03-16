def main():
    # Read input values for X, K, and D from the user
    X, K, D = map(int, input().split())

    # Calculate how many full steps of size D can be taken from X
    r = X // D
    
    # Check if the number of steps exceeds K
    if abs(r) > K:
        # If it does, print the remaining distance after K steps and exit
        print(abs(X) - K * D)
        exit()
    
    # Calculate the position after taking r steps of size D
    a = X - r * D
    
    # Check if the remaining steps after r are even or odd
    if (K - r) % 2 == 0:
        # If even, print the current position a
        print(a)
    else:
        # If odd, print the distance to the next position after one more step
        print(abs(D - a))

if __name__ == '__main__':
    # Call the main function to execute the program
    main()
