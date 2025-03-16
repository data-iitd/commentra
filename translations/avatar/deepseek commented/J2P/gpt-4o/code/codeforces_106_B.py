import sys

def main():
    # Read the number of elements
    n = int(sys.stdin.readline().strip())
    
    # Initialize a 2D list to store the elements
    vec = [list(map(int, sys.stdin.readline().strip().split())) for _ in range(n)]
    
    # Initialize variables to store the best index and its price
    ans = 500
    ansprice = 20000
    
    # Loop through each element to find the best one
    for i in range(n):
        fl = 1  # Flag to check if the element is dominated
        
        # Compare the current element with every other element
        for j in range(n):
            if vec[i][0] < vec[j][0] and vec[i][1] < vec[j][1] and vec[i][2] < vec[j][2]:
                fl = 0  # The element is dominated
        
        # If the element is not dominated, check its price
        if fl == 1:
            if vec[i][3] < ansprice:
                ansprice = vec[i][3]  # Update the minimum price
                ans = i + 1  # Update the best index
    
    # Output the index of the best element
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
