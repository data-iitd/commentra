def main():
    # Read two integers a and b from input
    a, b = map(int, input().split())

    # Convert b to string to determine its length
    bstr = str(b)
    
    # Calculate the number formed by concatenating a and b
    num = a * (10 ** len(bstr)) + b

    # Initialize a variable to find the square root of num
    i = 1
    # Loop to check if there exists an integer i such that i*i equals num
    while i * i <= num:
        if i * i == num:
            break  # If found, exit the loop
        i += 1

    # Check if a valid integer i was found within the range
    if i * i > num: 
        print("No")  # If no such i exists, print "No"
    else: 
        print("Yes")  # If such i exists, print "Yes"

main()
