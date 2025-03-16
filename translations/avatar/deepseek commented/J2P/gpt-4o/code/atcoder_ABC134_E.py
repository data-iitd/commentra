from collections import defaultdict  # Importing defaultdict for frequency counting

def main():
    n = int(input())  # Reading the integer n from the input
    freq_map = defaultdict(int)  # Initializing a defaultdict to store the frequency of numbers
    sorted_keys = []  # List to maintain the sorted keys

    # Looping n times to read n numbers
    for _ in range(n):
        num = int(input())  # Reading the next integer from the input

        # Checking if there is no key less than the current number
        if not sorted_keys or sorted_keys[-1] < num:
            # Incrementing the frequency of the current number
            freq_map[num] += 1
            if num not in sorted_keys:
                sorted_keys.append(num)
                sorted_keys.sort()  # Keep the keys sorted
        else:
            # Finding the largest key less than the current number
            key = max(k for k in sorted_keys if k < num)
            # Decrementing the frequency of the found key and removing it if frequency becomes zero
            if freq_map[key] == 1:
                del freq_map[key]
                sorted_keys.remove(key)
            else:
                freq_map[key] -= 1
            # Incrementing the frequency of the current number
            freq_map[num] += 1
            if num not in sorted_keys:
                sorted_keys.append(num)
                sorted_keys.sort()  # Keep the keys sorted

    # Calculating the sum of all frequencies in the map
    ans = sum(freq_map.values())

    # Printing the sum of frequencies
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
