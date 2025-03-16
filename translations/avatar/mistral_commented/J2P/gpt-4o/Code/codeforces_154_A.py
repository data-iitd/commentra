import sys

def main():
    # Reading the first line of input as a character array
    arr = list(sys.stdin.readline().strip())
    
    N = len(arr)  # Length of the character array
    K = int(sys.stdin.readline().strip())  # Reading the second line of input as an integer
    
    res = 0  # Variable to store the result

    for _ in range(K):
        input_str = sys.stdin.readline().strip()  # Reading a string as input
        
        a = 0  # Counter for the first character
        b = 0  # Counter for the second character
        
        for char in arr:
            if char == input_str[0]:
                a += 1  # Incrementing 'a' if the character matches the first character of the input string
            elif char == input_str[1]:
                b += 1  # Incrementing 'b' if the character matches the second character of the input string
            else:
                res += min(a, b)  # Adding the minimum of 'a' and 'b' to 'res'
                a = b = 0  # Resetting 'a' and 'b' to zero
        
        res += min(a, b)  # Adding the minimum of 'a' and 'b' to 'res' after the loop

    print(res)  # Printing the final result

if __name__ == "__main__":
    main()

# <END-OF-CODE>
