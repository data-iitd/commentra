
import sys
import collections

# Main method is the entry point of the program
def main():
    # Creating a Scanner object for reading input
    in_ = sys.stdin
    # Creating a PrintWriter object for writing output
    out = sys.stdout

    # Reading the number of elements in the array from the input
    n = int(in_.readline())
    # Creating an integer array of size n
    ara = [0] * n
    # Creating an empty HashMap to store the frequency of each integer
    map = collections.defaultdict(int)

    # Reading elements of the array and updating the frequency in the HashMap
    for i in range(n):
        v = int(in_.readline())
        ara[i] = v
        if v not in map:
            map[v] = 1
        else:
            map[v] += 1

    # Finding the maximum frequency in the HashMap
    max = 0
    for i in map.values():
        max = max if max > i else i

    # Finding the element(s) with the maximum frequency
    mm = collections.defaultdict(int)
    for i in range(n):
        if ara[i] not in mm:
            mm[ara[i]] = 1
            if mm[ara[i]] == max:
                out.write(str(ara[i]) + '\n')
                break
        else:
            mm[ara[i]] += 1
            if mm[ara[i]] == max:
                out.write(str(ara[i]) + '\n')
                break

    # Closing the PrintWriter object
    out.close()

# A helper method for printing debugging information
def debug(*obj):
    print(obj)

# Main method
if __name__ == '__main__':
    main()

