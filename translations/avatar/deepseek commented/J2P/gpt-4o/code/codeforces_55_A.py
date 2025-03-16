def main():
    import sys
    input = sys.stdin.read
    data = input().strip().split()
    
    n = int(data[0])
    i = 0
    k = 0
    flag = True
    a = [0] * 1000

    # Step 6: Enter a while loop that continues until k is less than or equal to n
    while k <= n:
        # Step 7: Update the value of i by adding k to it
        i += k

        # Step 8: Adjust the value of i if it is greater than or equal to n
        if i >= n:
            while not (i < n):
                i -= n

        # Step 9: Increment the value of a[i] by 1
        a[i] += 1

        # Step 10: Increment the value of k by 1
        k += 1

    # Step 11: Enter a for loop to check if any value in the array a is 0
    for i in range(n):
        if a[i] == 0:
            flag = False
            break

    # Step 12: Check the value of flag and print "YES" if flag is true, otherwise print "NO"
    if flag:
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":
    main()
# <END-OF-CODE>
