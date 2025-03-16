
N = int(input())  # Taking an integer input N, which represents the number of elements in the list Hs.
Hs = list(map(int, input().split()))  # Taking a list of integers as input, which are stored in the list Hs.

ans = 0  # Initializing ans to 0, which will be used to count the number of elements that are not less than the maximum height encountered so far.
maxH = 0  # Initializing maxH to 0, which will be used to keep track of the maximum height encountered so far.
for H in Hs:  # Entering a for loop to iterate through each element H in the list Hs.
    if maxH <= H:  # Checking if the current element H is greater than or equal to maxH.
        ans += 1  # Incrementing ans by 1 if the condition is true.
        maxH = H  # Updating maxH to H.

print(ans)  # Printing the value of ans, which represents the number of elements that are not less than the maximum height encountered so far.


