
import sys

# Function to return the minimum of two integers
def min(a, b):
    if a <= b:
        return a
    return b

# Function to process the chain of colors and return the count of remaining colors
def Chain(b, n):
    a = b[:] # Copy input array b to array a
    i = 0
    while i < n - 4:
        if a[i]!= 0 and a[i] == a[i + 1] and a[i] == a[i + 2] and a[i] == a[i + 3]:
            count = 0
            color = a[i]
            for j in range(i, n):
                if a[j] == color:
                    a[j] = 0
                    count += 1
                else:
                    break
            for j in range(0, n - count):
                a[j] = a[j + count]
            i = 0
        else:
            i += 1
    count = 0
    while a[count]!= 0:
        count += 1
    if count == 4 and a[0] == a[1] and a[0] == a[2] and a[0] == a[3]:
        return 0
    return count

# Main function to execute the program
def main():
    while True:
        n = int(input())
        if n == 0:
            break
        a = [0] * 10000
        ans = n
        for i in range(0, n):
            a[i] = int(input())
        for i in range(0, n - 4):
            count = [0, 0, 0]
            for j in range(i, i + 4):
                if a[j] - 1 >= 0:
                    count[a[j] - 1] += 1
            color = 0
            for j in range(0, 3):
                if count[j] >= 3:
                    color = j + 1
                    break
            if color!= 0:
                for j in range(i, i + 4):
                    buf = a[j]
                    a[j] = color
                    ans = min(ans, Chain(a, n))
                    a[j] = buf
        print(ans)

if __name__ == "__main__":
    main()

