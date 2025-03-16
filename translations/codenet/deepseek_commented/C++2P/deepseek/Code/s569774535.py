import sys

def main():
    n = int(input())  # Read the integer n
    a = list(map(int, input().split()))  # Read n integers into the list a

    ans = 0  # Initialize ans to 0
    while True:  # Start the main loop
        for i in range(n):  # Iterate over each element in the list a
            if a[i] % 2 == 1:  # Check if the element is odd
                print(ans)  # Print the current value of ans and exit
                return
            else:  # If the element is even
                a[i] //= 2  # Divide the element by 2
        ans += 1  # Increment ans after processing all elements

if __name__ == "__main__":
    main()
