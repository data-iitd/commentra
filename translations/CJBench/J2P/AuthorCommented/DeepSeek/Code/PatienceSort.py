def form_piles(array):
    piles = []
    last_elements = []

    for x in array:
        pos = binary_search(last_elements, x)
        if pos < 0:
            pos = -pos - 1

        if pos < len(piles):
            piles[pos].append(x)
            last_elements[pos] = x
        else:
            new_pile = [x]
            piles.append(new_pile)
            last_elements.append(x)

    return piles


def binary_search(lst, x):
    left, right = 0, len(lst)
    while left < right:
        mid = (left + right) // 2
        if lst[mid] <= x:
            left = mid + 1
        else:
            right = mid
    return left


def merge_piles(piles):
    import heapq
    pq = []
    for pile in piles:
        if pile:
            heapq.heappush(pq, (-pile[-1], pile))
    return pq


def extract_piles(array, pq):
    index = 0
    while pq:
        value, pile = heapq.heappop(pq)
        array[index] = -value
        index += 1
        if pile:
            heapq.heappush(pq, (-pile.pop(), pile))


def patience_sort(array):
    if not array:
        return array

    piles = form_piles(array)
    pq = merge_piles(piles)
    extract_piles(array, pq)

    return array


# Example usage:
if __name__ == "__main__":
    import sys
    input = sys.stdin.readline

    # Input: size of the array
    n = int(input().strip())
    array = list(map(int, input().strip().split()))

    # Sort the array using Patience Sort
    sorted_array = patience_sort(array)

    # Output: sorted array
    print(" ".join(map(str, sorted_array)))
