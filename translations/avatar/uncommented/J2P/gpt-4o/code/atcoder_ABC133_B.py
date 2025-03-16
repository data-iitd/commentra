import math

def main():
    N = int(input())
    D = int(input())
    vectors = []

    for _ in range(N):
        vector = list(map(int, input().split()))
        vectors.append(vector)

    answer = 0
    for i in range(N - 1):
        for j in range(i + 1, N):
            dist = 0
            for d in range(D):
                x = vectors[i][d] - vectors[j][d]
                dist += (x * x)
            sq = math.sqrt(dist)
            answer += 1 if abs(sq - math.floor(sq)) < 0.001 else 0

    print(answer)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
