
import sys # Importing the sys module to read input from the user

def main():
    n, k = map(int, sys.stdin.readline().split()) # Reading the integers n and k from the user
    a = sys.stdin.readline().strip() # Reading the string a from the user

    # Check if k is greater than n/2
    if k > n / 2:
        # Move right until k equals n
        while k < n:
            print("RIGHT") # Print "RIGHT"
            k += 1 # Increment k
    else:
        # Move left until k equals 1
        while k > 1:
            print("LEFT") # Print "LEFT"
            k -= 1 # Decrement k

    # If k equals 1, print each character of the string a starting from the first character and moving rightwards
    if k == 1:
        for i in range(len(a)):
            print("PRINT", a[i]) # Print the character and then move right
            if i < len(a) - 1:
                print("RIGHT") # Print "RIGHT" if it's not the last character
    else:
        # If k does not equal 1, print each character of the string a starting from the last character and moving leftwards
        for i in range(len(a) - 1, -1, -1):
            print("PRINT", a[i]) # Print the character and then move left
            if i > 0:
                print("LEFT") # Print "LEFT" if it's not the first character

if __name__ == "__main__":
    main() # Call the main function

