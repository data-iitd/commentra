import sys

def main():
    # Reading the first line of input as a character array
    arr = list(sys.stdin.readline().strip())
    
    # Reading the length of the character array 'arr'
    N = len(arr)
    
    # Reading the second line of input as an integer
    K = int(sys.stdin.readline().strip())
    
    # Initializing the result variable
    res = 0
    
    # Iterating 'K' times
    for _ in range(K):
        # Reading a string as input
        input_str = sys.stdin.readline().strip()
        
        # Initializing the counts for two different characters
        a = 0
        b = 0
        
        # Iterating through each index of the character array 'arr'
        for char in arr:
            # Incrementing the count 'a' if the character matches the first character of the input string
            if char == input_str[0]:
                a += 1
            # Incrementing the count 'b' if the character matches the second character of the input string
            elif char == input_str[1]:
                b += 1
            # Resetting the counts and adding to the result if the character is different
            else:
                res += min(a, b)
                a = b = 0
        
        # Adding the minimum of 'a' and 'b' to the result after the loop
        res += min(a, b)
    
    # Printing the final result
    print(res)

if __name__ == "__main__":
    main()
