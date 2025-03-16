def main():
    # Read the number of elements
    n = int(input())
    
    # Read heights and determine the maximum height
    heights = list(map(int, input().split()))
    max_height = -1
    flag = False
    
    for height in heights:
        # Update maximum height if current height is greater
        if max_height < height:
            max_height = height
        
        # Check if the difference between max height and current height is 2 or more
        if max_height - height >= 2:
            flag = True  # Set flag if condition is met
    
    # Output result based on the flag value
    if flag:
        print("No")  # If flag is set, print "No"
    else:
        print("Yes")  # If flag is not set, print "Yes"

# Call the main function
main()

