# Linear Search Function
# Purpose: This function performs a linear search to find the key in the array S.
# Parameters:
#   - S: The list to be searched.
#   - key: The value to be searched for.
# Return Value: Returns True if the key is not found, otherwise returns False.
def linear_search(S, key):
    for item in S:
        if item == key:
            return False
    return True

# Main Function
# Purpose: This function reads two lists S and T, and counts the number of elements in T that are present in S using the linear_search function.
def main():
    n = int(input())
    S = list(map(int, input().split()))
    
    q = int(input())
    T = list(map(int, input().split()))
    
    count = 0
    
    for key in T:
        if linear_search(S, key):
            count += 1
            
    print(count)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
