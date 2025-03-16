def main():
    X, K, D = map(int, input().split())

    r = X // D  # Calculate the number of complete steps of size D that can be taken from X
    if abs(r) > K:  # Check if we cannot reach the target by moving K steps
        print(abs(X) - K * D)  # Print the absolute difference if we cannot reach the target
        exit()  # Exit the program
    a = X - r * D  # Calculate the remainder
    if (K - r) % 2 == 0:  # Check if the difference between K and r is even
        print(a)  # Print the remainder if the difference is even
    else:
        print(abs(D - a))  # Print the absolute difference between D and a if the difference is odd
    


if __name__ == '__main__':
    main()
