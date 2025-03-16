import sys

def main():
    # Reading the number of rows and columns of the 2D char array from the standard input stream
    n = int(input().strip())

    # Allocating memory for the 2D char array and the String array
    arr = [list(input().strip()) for _ in range(n)]

    # Initializing two variables 'a' and 'b' with the characters at the first position of the first row of the 2D char array
    a = arr[0][0]
    b = arr[0][1]

    # Checking if the first characters of the first row are equal or not
    if a == b:
        print("NO")
    else:
        res = True

        # Checking if there exists any pair of distinct characters in the 2D char array such that they form a diagonal line
        for i in range(n):
            for j in range(n):
                # Checking if the current pair (i, j) and (j, i) form a diagonal line
                if (i == j or i + j == n - 1):
                    # Checking if the characters at the current position of the 2D char array are equal to 'a' or 'b'
                    if arr[i][j] != a:
                        res = False
                        break
                else:
                    # Checking if the characters at the current position of the 2D char array are equal to 'b'
                    if arr[i][j] != b:
                        res = False
                        break

        # Printing "YES" if all the characters in the 2D char array form either a single diagonal line of 'a's and 'b's or two separate diagonal lines of 'a's and 'b's
        if res:
            print("YES")
        else:
            print("NO")

if __name__ == "__main__":
    main()
