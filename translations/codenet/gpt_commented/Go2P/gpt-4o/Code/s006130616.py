def main():
    # Declare variables for the number of participants (n), number of skills (m), and the minimum skill level required (x)
    n, m, x = map(int, input().split())

    # Initialize a list to hold skill levels and a list for participant points
    a = []
    p = []
    
    # Read participant points and their respective skill levels
    for i in range(n):
        # Read the points for participant i
        points = list(map(int, input().split()))
        p.append(points[0])  # First element is the points
        a.append(points[1:])  # Remaining elements are the skill levels

    # Initialize the answer to a large number and other variables for tracking total points and skill validation
    ans = 1200001
    tot = 0
    ok = True

    # Iterate through all possible combinations of participants using bit manipulation
    for bits in range(1 << n):
        # Reset total points and skill validation flag for the current combination
        tot = 0
        ok = True
        # Initialize a list to accumulate skill levels for the current combination
        skill = [0] * m

        # Check each participant to see if they are included in the current combination
        for i in range(n):
            if (bits >> i) & 1 == 1:
                # Add the points of the selected participant to the total
                tot += p[i]
                # Accumulate the skill levels of the selected participant
                for j in range(m):
                    skill[j] += a[i][j]

        # Check if the accumulated skill levels meet the minimum requirement
        for v in skill:
            if v < x:
                ok = False  # If any skill level is below x, mark as not okay
                break

        # If the combination is valid (all skills meet the requirement), update the answer if the total points are lower
        if ok:
            if ans > tot:
                ans = tot

    # Output the result: the minimum points needed or -1 if no valid combination was found
    if ans != 1200001:
        print(ans)
    else:
        print("-1")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
