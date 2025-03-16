import sys

def main():
    # Read input values and initialize variables
    n = int(sys.stdin.readline().strip())
    a = list(map(int, sys.stdin.readline().strip().split()))
    s = {}

    # Perform binary search to find the maximum k
    ng = 0
    ok = n
    while ok - ng > 1:
        k = (ng + ok) // 2
        # Check if it is possible to achieve the current k
        if is_possible(k):
            ok = k
        else:
            ng = k

    # Output the result
    print(ok)

def is_possible(k):
    # Check if it is possible to achieve the given k
    s.clear()
    current = 0

    # Iterate through each element in the array
    for ai in a:
        # If the current element is less than or equal to the current value
        if ai <= current:
            # If k is 1, return false as we cannot have duplicates
            if k == 1:
                return False

            # Remove elements from TreeMap that are greater than or equal to ai
            while s and s[max(s.keys())] >= ai:
                s.pop(max(s.keys()))

            p = ai - 1
            while True:
                # If p is less than 0, return false
                if p < 0:
                    return False

                # Get the count of p from TreeMap and increment it
                sp = s.get(p, 0) + 1
                s[p] = sp

                # If the count reaches k, remove p from TreeMap and decrement p
                if sp == k:
                    s.pop(p)
                    p -= 1
                else:
                    break
        current = ai
    return True

if __name__ == "__main__":
    main()

