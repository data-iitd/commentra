
# Read the weather condition from standard input
S = input()

# Use a switch statement to determine the next weather condition based on the input
if S == "Sunny":
    # If the input is "Sunny", print "Cloudy" as the next condition
    print("Cloudy")
elif S == "Cloudy":
    # If the input is "Cloudy", print "Rainy" as the next condition
    print("Rainy")
elif S == "Rainy":
    # If the input is "Rainy", print "Sunny" as the next condition
    print("Sunny")

