
n = int(input())  # Read the integer n
a = list(map(int, input().split()))  # Read n integers into the list a

ans = 0  # Initialize ans to 0
ok = True  # Initialize ok to True
while ok:  # Start the main loop
    for i in range(n):  # Iterate over each element in the list a
        if a[i] % 2 == 1:  # Check if the element is odd
            print(ans)  # Print the current value of ans and exit
            break  # Exit the loop
        else:  # If the element is even
            a[i] //= 2  # Divide the element by 2
    else:  # If the loop completes without breaking
        ans += 1  # Increment ans after processing all elements

print(ans)  # Print the final value of ans

