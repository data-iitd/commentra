def naive_main(string1, string2):
    n = len(string1)
    m = len(string2)
    distance_matrix = [[0] * (m + 1) for _ in range(n + 1)]

    for i in range(n + 1):
        for j in range(m + 1):
            if i == 0:
                distance_matrix[i][j] = j
            elif j == 0:
                distance_matrix[i][j] = i
            else:
                cost = 0 if string1[i - 1] == string2[j - 1] else 1
                distance_matrix[i][j] = min(distance_matrix[i - 1][j - 1] + cost,
                                            min(distance_matrix[i][j - 1] + 1, distance_matrix[i - 1][j] + 1))

    return distance_matrix[n][m]


def optimized_main(string1, string2):
    n = len(string1)
    m = len(string2)
    if n == 0:
        return m

    previous_distance = list(range(n + 1))

    for j in range(1, m + 1):
        current_distance = [j] * (n + 1)
        for i in range(1, n + 1):
            deletion_cost = previous_distance[i] + 1
            insertion_cost = current_distance[i - 1] + 1
            substitution_cost = 0 if string1[i - 1] == string2[j - 1] else 1
            current_distance[i] = min(deletion_cost, min(insertion_cost, previous_distance[i - 1] + substitution_cost))
        previous_distance = current_distance

    return previous_distance[n]


def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    string1 = data[0]
    string2 = data[1]
    method = int(data[2])

    if method == 1:
        distance = naive_main(string1, string2)
    else:
        distance = optimized_main(string1, string2)

    print("The Levenshtein distance between the two strings is:", distance)


main()
