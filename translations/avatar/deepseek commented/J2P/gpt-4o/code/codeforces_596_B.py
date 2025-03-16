# Step 1: Import the necessary modules.
import sys

# Step 2: Define the main function.
def main():
    # Step 3: Read the size of the array from the user.
    n = int(input())
    
    # Step 4: Create a list to store the elements of the array.
    arr = list(map(int, input().split()))
    
    # Step 5: Initialize a variable to store the answer.
    answer = abs(arr[0])
    
    # Step 6: Calculate the absolute difference between consecutive elements and add it to the answer.
    for i in range(1, n):
        answer += abs(arr[i] - arr[i - 1])
    
    # Step 7: Print the final answer.
    print(answer)

# Step 8: Call the main function.
if __name__ == "__main__":
    main()

# <END-OF-CODE>
