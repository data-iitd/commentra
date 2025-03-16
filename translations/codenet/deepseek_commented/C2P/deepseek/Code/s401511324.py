def count_valid_triangles(l):
    l.sort()
    cnt = 0
    for i in range(len(l) - 2):
        for j in range(i + 1, len(l) - 1):
            for k in range(j + 1, len(l)):
                if l[i] + l[j] > l[k]:
                    cnt += 1
                else:
                    break
    return cnt

# Read the number of elements in the array
n = int(input())
# Read the elements of the array
l = list(map(int, input().split()))
# Count the number of valid triangles that can be formed
cnt = count_valid_triangles(l)
# Print the count of valid triangles
print(cnt)
