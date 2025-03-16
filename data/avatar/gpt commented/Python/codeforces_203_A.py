# Read input values and split them into a list
xxs = input().split(" ")

# Convert the input strings to integers
x, t, a, b, da, db = int(xxs[0]), int(xxs[1]), int(xxs[2]), int(xxs[3]), int(xxs[4]), int(xxs[5])

def main():
    # Check if the target value x is zero
    if x == 0:
        print("YES")  # If x is zero, print "YES" and return
        return "Result Found"
    
    # Calculate the maximum time available for a and b, constrained by t
    a_time = min([a // da, t - 1])
    b_time = min([b // db, t - 1])
    
    # Iterate through all possible values of i and j within the calculated time limits
    for i in range(a_time + 1):
        for j in range(b_time + 1):
            # Check if either a or b can be reduced to x by subtracting multiples of da or db
            if a - da * i == x or b - db * j == x:
                print("YES")  # If found, print "YES" and return
                return "Result Found"
            # Check if the sum of the remaining values of a and b equals x
            if (a - da * i) + (b - db * j) == x:
                print("YES")  # If found, print "YES" and return
                return "Result Found"
    
    # If no valid combination is found, return "Result Not Found"
    return "Result Not Found"

# Call the main function and store the result
ff = main()

# If the result indicates that no valid combination was found, print "NO"
if ff == "Result Not Found":
    print("NO")
