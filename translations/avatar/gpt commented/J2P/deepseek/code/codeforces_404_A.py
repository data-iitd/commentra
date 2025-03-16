import sys

def main():
    # Reading the size of the matrix (n x n)
    n = int(input().strip())
    
    # Initializing a 2D list to store the matrix
    arr = []
    
    # Reading n strings from the input
    for _ in range(n):
        str_input = input().strip()
        arr.append(list(str_input))
    
    # Storing the first two characters of the matrix for comparison
    a = arr[0][0]
    b = arr[0][1]
    
    # Checking if the first two characters are the same
    if a == b:
        print("NO")  # If they are the same, print "NO"
    else:
        # Initializing a boolean variable to track the result
        res = True
        
        # Checking the conditions for the characters in the matrix
        for i in range(n):
            for j in range(n):
                # Checking if the current position is on the main diagonal or the anti-diagonal
                if i == j or i + j == n - 1:
                    # If it is, check if the character matches 'a'
                    if arr[i][j] != a:
                        res = False  # If not, set result to False and break
                        break
                else:
                    # If it is not on the diagonals, check if the character matches 'b'
                    if arr[i][j] != b:
                        res = False  # If not, set result to False and break
                        break
        
        # Print "YES" if the conditions are satisfied, otherwise print "NO"
        if res:
            print("YES")
        else:
            print("NO")

if __name__ == "__main__":
    main()
