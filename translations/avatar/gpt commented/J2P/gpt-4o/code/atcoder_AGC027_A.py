# Import the necessary module
import sys

def main():
    # Read the number of sweet items (N) and the initial amount of money (x)
    N = int(sys.stdin.readline().strip())
    x = int(sys.stdin.readline().strip())
    
    # Initialize a list to store the sweetness values of the items
    sweet = []
    
    # Read the sweetness values and add them to the list
    for _ in range(N):
        a = int(sys.stdin.readline().strip())
        sweet.append(a)
    
    # Sort the list of sweetness values in ascending order
    sweet.sort()
    
    # Initialize a counter for the number of sweet items that can be bought
    num = 0
    
    # Iterate through the sorted sweetness values
    for i in range(N):
        # Check if the current sweetness value can be bought with the remaining money
        if x - sweet[num] >= 0:
            # Deduct the sweetness value from the total money
            x -= sweet[num]
            # Increment the count of items bought
            num += 1
        else:
            # If the current item cannot be bought, exit the loop
            break
    
    # Adjust the count if all items were bought but there is still money left
    if num == N and x > 0:
        num -= 1
    
    # Print the total number of sweet items that can be bought
    print(num)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
