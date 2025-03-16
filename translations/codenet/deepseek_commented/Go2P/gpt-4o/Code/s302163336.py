import sys

def next_int():
    return int(sys.stdin.readline().strip())

def main():
    n = next_int()  # Read the number of elements
    m = next_int()  # Read the number of comparisons
    h = [next_int() for _ in range(n)]  # Read the height of each element
    good = [True] * n  # Initialize list to track "good" status

    for _ in range(m):
        ai = next_int() - 1  # Read the first index and adjust for 0-based index
        bi = next_int() - 1  # Read the second index and adjust for 0-based index
        if h[ai] > h[bi]:  # Compare heights and update "good" status
            good[bi] = False  # Mark the second element as not good if overshadowed
        elif h[ai] < h[bi]:
            good[ai] = False  # Mark the first element as not good if overshadowed
        else:
            good[ai] = False  # Mark both elements as not good if heights are equal
            good[bi] = False

    ans = sum(good)  # Count the elements that are still good
    print(ans)  # Print the number of good elements

if __name__ == "__main__":
    main()

# <END-OF-CODE>
