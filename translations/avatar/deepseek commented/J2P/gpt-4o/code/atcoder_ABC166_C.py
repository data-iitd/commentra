# Import the sys module for input
import sys

def main():
    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])  # Read the number of elements N
    M = int(data[1])  # Read the number of comparisons M
    
    H = list(map(int, data[2:2 + N]))  # Read the heights of the elements into the list H
    ans = [True] * N  # Initialize a boolean list to store the result for each element
    
    # Read the pairs of indices (temp1 and temp2) and compare the heights at these indices
    index = 2 + N
    for _ in range(M):
        temp1 = int(data[index]) - 1  # Convert to 0-based index
        temp2 = int(data[index + 1]) - 1  # Convert to 0-based index
        index += 2
        
        if H[temp1] < H[temp2]:
            ans[temp1] = False  # Update the boolean list ans based on the comparison results
        elif H[temp1] > H[temp2]:
            ans[temp2] = False  # Update the boolean list ans based on the comparison results
        else:
            ans[temp1] = False  # Update the boolean list ans based on the comparison results
            ans[temp2] = False  # Update the boolean list ans based on the comparison results
    
    ans2 = sum(ans)  # Count the number of elements in the boolean list ans that are still True
    
    print(ans2)  # Print the count

if __name__ == "__main__":
    main()

# <END-OF-CODE>
