def main():
    # Create a Scanner object to read input from the standard input stream
    sc = Scanner(System.stdin)

    # Read the number of switches (N) and the number of lights (M)
    N = sc.nextInt()
    M = sc.nextInt()

    # Initialize an ArrayList of integers with N elements, all set to 0
    a = [0] * N

    # Read M groups of integers, where each group represents a switch and its corresponding states
    for i in range(M):
        k = sc.nextInt()
        for j in range(k):
            s = sc.nextInt()
            s -= 1
            a[s] |= (1 << i)

    # Read the final state of each light
    p = 0
    for i in range(M):
        x = sc.nextInt()
        p |= (x << i)

    # Calculate the number of possible configurations of switch states that match the final state of the lights
    ans = 0
    for s in range(1 << N):
        t = 0
        for i in range(N):
            if (s >> i) & 1:
                t ^= a[i]
        if p == t:
            ans += 1

    # Print the result
    print(ans)

    # Close the Scanner object
    sc.close()

