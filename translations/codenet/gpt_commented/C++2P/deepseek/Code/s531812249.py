def main():
    # Read the number of groups n and m
    n, m = map(int, input().split())

    # Initialize the answer variable to store the total pairs
    ans = 0

    # Calculate the number of pairs within group n
    # The formula n*(n-1)//2 gives the number of ways to choose 2 from n
    ans += n * (n - 1) // 2

    # Calculate the number of pairs within group m
    # Similarly, m*(m-1)//2 gives the number of ways to choose 2 from m
    ans += m * (m - 1) // 2

    # Output the total number of pairs
    print(ans)


if __name__ == "__main__":
    main()
