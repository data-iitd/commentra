def count_valid_triplets(l):
    n = len(l)
    l.sort()
    cnt = 0

    for i in range(n - 2):
        for j in range(i + 1, n - 1):
            for k in range(j + 1, n):
                if l[i] + l[j] > l[k]:
                    cnt += 1
                else:
                    break

    return cnt

# Read the number of elements
n = int(input())

# Input the elements into the list
l = list(map(int, input().split()))

# Count and output the number of valid triplets
print(count_valid_triplets(l))
