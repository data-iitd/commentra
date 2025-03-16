def check(n, wei, book):
    tmp = wei  # Temporary variable to hold the remaining weight
    n -= 1  # Decrease the number of available books by one
    for i in range(len(book)):
        # If the current weight exceeds the available weight
        if tmp < book[i]:
            # If there are still books left to use
            if n > 0:
                n -= 1  # Use one book
                tmp = wei  # Reset the temporary weight to the original weight
                # Check again if the current weight exceeds the available weight
                if tmp < book[i]:
                    return False  # Not possible to distribute
            else:
                return False  # No books left to use
        # Deduct the current book's weight from the temporary weight
        tmp -= book[i]
    return True  # Successfully distributed the weights

def main():
    while True:
        m, n = map(int, input().split())  # m: maximum weight, n: number of books
        if m == 0:
            break
        book = []  # List to store the weights of the books
        # Read the weights of the books
        for _ in range(n):
            tmp = int(input())  # Read each book's weight
            book.append(tmp)  # Add weight to the list

        l = 0  # Lower bound for binary search
        r = 1500000  # Upper bound for binary search
        ans = 0  # Variable to store the answer
        # Perform binary search to find the maximum weight that can be distributed
        while l < r:
            mid = (l + r) // 2
            # Check if the middle weight can be distributed
            if check(m, mid, book):
                ans = mid  # Update answer
                r = mid  # Move the upper bound down
            else:
                l = mid + 1  # Move the lower bound up

        print(ans)  # Output the maximum weight that can be distributed

if __name__ == "__main__":
    main()

# <END-OF-CODE>
