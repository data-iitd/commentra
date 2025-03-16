import sys

def main():
    # Reading the integer value of n from the standard input
    n = int(sys.stdin.readline().strip())
    
    # Reading the string value of the input from the standard input
    str = sys.stdin.readline().strip()
    
    # Creating a char array l of size equal to the length of the input string
    l = list(str)
    
    # Checking if there is any character other than '4' or '7'
    t = 0
    for char in l:
        if char != '4' and char != '7':
            t = 1
            break
    
    if t == 1:
        print("NO")
    else:
        # Calculating the sum of digits in the first half of the string
        sumX = sum(int(char) for char in l[:n//2])
        
        # Calculating the sum of digits in the second half of the string
        sumY = sum(int(char) for char in l[n//2:])
        
        # Checking if the sum of digits in the first half is equal to the sum of digits in the second half
        if sumX == sumY:
            print("YES")
        else:
            print("NO")

if __name__ == "__main__":
    main()

