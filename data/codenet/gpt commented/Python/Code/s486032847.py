import math

def keta(s):
    # If the length of the string is less than 2, convert it to an integer and return
    if len(s) < 2:
        return int(s)
    # Calculate the sum of the digits in the string representation of the number
    n = sum(map(int, s))
    # Recursively call keta with the string representation of the sum
    return keta(str(n))

def main():
    # Read input from the user
    N = input()
    # Uncomment the following line if you want to read multiple integers from input
    # N, X, T = list(map(int, input().split()))
    
    # Check if the result of keta(N) is divisible by 9
    if keta(N) % 9 == 0:
        print("Yes")  # Print "Yes" if divisible by 9
    else:
        print("No")   # Print "No" if not divisible by 9

# Entry point of the program
if __name__ == "__main__":
    main()
