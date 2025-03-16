
import sys

def read_long_lines(times):
    result = []
    for i in range(times):
        line = sys.stdin.readline()
        result.append(line)
    return result

def print_list(list):
    for i in range(len(list)):
        if i == 0:
            print(list[i], end='')
        else:
            print(' ' + str(list[i]), end='')
    print('')

def main():
    # Create a map to store unique elements.
    m = {}
    lines = read_long_lines(4)

    # Split the second line into individual elements and add them to the map.
    a = lines[1].split(' ')
    for i in range(len(a)):
        n = int(a[i])
        m[n] = 1

    # Process the fourth line to toggle the presence of elements in the map.
    result = []
    b = lines[3].split(' ')
    for i in range(len(b)):
        n = int(b[i])
        if n in m:
            del m[n]
        else:
            m[n] = 1

    # Extract the unique elements from the map and sort them.
    for k in m.keys():
        result.append(k)
    result.sort()

    # Print the sorted list of unique elements.
    for j in range(len(result)):
        print(result[j])

if __name__ == '__main__':
    main()

