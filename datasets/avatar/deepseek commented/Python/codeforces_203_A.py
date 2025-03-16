
xxs = input().split(" ")
x, t, a, b, da, db = int(xxs[0]), int(xxs[1]), int(xxs[2]), int(xxs[3]), int(xxs[4]), int(xxs[5])

# Define the main function to perform the logic
def main():
    # Check if the value of x is 0
    if x == 0:
        print("YES")
        return "Result Found"
    
    # Calculate the maximum number of times a and b can be decremented within the time limit t
    a_time = min([a // da, t - 1])
    b_time = min([b // db, t - 1])
    
    # Iterate over all possible combinations of decrements for a and b within their respective limits
    for i in range(a_time + 1):
        for j in range(b_time + 1):
            # Check if either a or b (or their sum) equals x
            if a - da * i == x or b - db * j == x:
                print("YES")
                return "Result Found"
            if (a - da * i) + (b - db * j) == x:
                print("YES")
                return "Result Found"
    
    # Return "Result Not Found" if no combination results in x
    return "Result Not Found"

# Call the main function and store the result
ff = main()

# Check the result and print "NO" if the result is "Result Not Found"
if ff == "Result Not Found":
    print("NO")

