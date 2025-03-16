# Initialize variables
a = int(input())
t = 0
h = 0

# Loop through the number of games
for _ in range(a):
    # Read the names of Taro and Hana
    taro, hana = input().split()
    
    # Get the lengths of the names
    lt = len(taro)
    lh = len(hana)
    
    # Determine the maximum length of the names (not used in scoring)
    l = max(lt, lh)
    
    # Compare the names and update the scores
    if taro > hana:
        t += 3
    elif hana > taro:
        h += 3
    else:  # if taro == hana
        h += 1
        t += 1

# Output the final scores
print(t, h)

# <END-OF-CODE>
