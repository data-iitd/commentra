def main():
    H, W = map(int, input().split())  # Step 1: Reading the values of H and W from the standard input.

    ans = 0
    if H == 1 or W == 1:
        ans = 1  # Step 2: Handling the special case where either H or W is 1.
    else:
        m = H * W  # Step 3: Calculating the total area of the grid.
        if m % 2 == 0:
            ans = m // 2  # Step 4: If the area is even, half of it is the answer.
        else:
            ans = m // 2 + 1  # Step 5: If the area is odd, half of it plus one is the answer.
    print(ans)  # Step 6: Outputting the calculated minimum number of cells to be painted.


main()
