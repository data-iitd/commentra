def main():
    n = int(input())  # Step 1: Read the size of the array
    a = list(map(int, input().split()))  # Step 1: Read the elements of the array 'a'

    s = [0] * (n + 1)  # Step 2: Create the prefix sum array 's' of size 'n+1'
    for i in range(n):
        s[i + 1] = s[i] + a[i]  # Step 2: Calculate the prefix sums

    s.sort()  # Step 3: Sort the prefix sum array 's'

    ans = 0  # Step 4: Initialize the answer variable
    count = 0  # Step 4: Initialize the count variable
    for i in range(n):
        if s[i] == s[i + 1]:  # Step 4: Check for consecutive equal sums
            count += 1  # Step 4: Increment the count if sums are equal
        elif count > 0:  # Step 4: If count is greater than 0, calculate combinations
            ans += combi(count + 1, 2)  # Step 4: Calculate combinations using the combi function
            count = 0  # Step 4: Reset the count

    if count > 0:  # Step 4: Check if there are any remaining counts to calculate combinations for
        ans += combi(count + 1, 2)  # Step 4: Calculate combinations for the remaining counts

    print(ans)  # Step 5: Print the final answer


def combi(n, r):  # Step 4: Define the combi function to calculate combinations
    c = 1
    for i in range(1, r + 1):
        c = c * (n - i + 1) // i
    return c


main()
