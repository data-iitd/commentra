def main():
    n, m = map(int, input().split())  # Read the number of elements and comparisons
    h = list(map(int, input().split()))  # Read the heights of the elements
    counter = set()  # Create a set to keep track of elements that cannot be the highest
    for _ in range(m):
        a, b = map(int, input().split())  # Read each comparison
        if h[a - 1] < h[b - 1]:  # Check if the height of the first element is less than the second
            counter.add(a)  # Mark the first element as not being the highest
        elif h[a - 1] > h[b - 1]:  # Check if the height of the first element is greater than the second
            counter.add(b)  # Mark the second element as not being the highest
        else:  # If the heights of the two elements are equal
            counter.add(a)  # Mark both elements as not being the highest
            counter.add(b)
    print(n - len(counter))  # Print the number of elements that cannot be the highest


if __name__ == "__main__":
    main()
