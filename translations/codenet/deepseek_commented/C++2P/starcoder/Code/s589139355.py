
# Initialize variables
a = 0
t = 0
h = 0

# Loop through the number of games
for i in range(a):
    # Read the names of Taro and Hana
    taro, hana = input().split()

    # Get the lengths of the names
    lt = len(taro)
    lh = len(hana)

    # Determine the maximum length of the names
    if(lt > lh):
        l = lt
    else:
        l = lh

    # Initialize score counters for this round
    tt = 0
    hh = 0

    # Compare the names and update the scores
    if(taro > hana):
        t = t + 3
    elif(hana > taro):
        h = h + 3
    elif(hana == taro):
        h = h + 1
        t = t + 1

# Output the final scores
print(t, h)

