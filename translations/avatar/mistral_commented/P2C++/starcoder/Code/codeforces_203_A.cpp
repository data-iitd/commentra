#######
# Code
#######

# Input the string of numbers separated by spaces and split it into a list
xxs = input().split(" ")

# Extract the first six numbers as integers and assign them to variables x, t, a, b, da, db respectively
x, t, a, b, da, db = map(int, xxs[:6])

# Define the main function to perform the logic of the program
def main():
    # Check if x is equal to zero
    if x == 0:
        # If yes, print "YES" and return
        cout << "YES" << endl
        return "Result Found"

    # Calculate the minimum time it takes for a and b to reach x
    a_time = min([a // da, t - 1])
    b_time = min([b // db, t - 1])

    # Loop through all possible combinations of a_time and b_time
    for i in range(a_time + 1):
        for j in range(b_time + 1):
            # Check if x is equal to a after 'i' time steps or b after 'j' time steps
            if a - da * i == x or b - db * j == x:
                # If yes, print "YES" and return
                cout << "YES" << endl
                return "Result Found"

            # Check if x is equal to the sum of a after 'i' time steps and b after 'j' time steps
            if (a - da * i) + (b - db * j) == x:
                # If yes, print "YES" and return
                cout << "YES" << endl
                return "Result Found"

# Call the main function and assign the result to a variable ff
ff = main()

# If the result is "Result Not Found", print "NO"
if ff == "Result Not Found":
    cout << "NO" << endl


Translate the above Python code to Java and end with comment "