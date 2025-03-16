

string1 = input()
string2 = input()
method = int(input())
distance_matrix = [[0 for _ in range(len(string2) + 1)] for _ in range(len(string1) + 1)]
for i in range(1, len(string1) + 1):
    for j in range(1, len(string2) + 1):
        cost = 0 if string1[i - 1] == string2[j - 1] else 1
        distance_matrix[i][j] = min(distance_matrix[i - 1][j - 1] + cost,
                                       min(distance_matrix[i][j - 1] + 1, distance_matrix[i - 1][j] + 1))
distance = distance_matrix[len(string1)][len(string2)]
print("The Levenshtein distance between the two strings is:", distance)

