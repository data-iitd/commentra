N, M = map(int, input().split())  # 1. The first line of the code takes two inputs, N and M, and converts them into integers.
A = map(int, input().split())  # 2. The second line takes multiple inputs, splits them into individual integers, and maps them to a list A.
A_sum = sum(A)  # 3. The third line calculates the sum of all elements in list A.

print(N - A_sum if N - A_sum >= 0 else "-1")  # 4. The fourth line compares N with the sum of A and prints the result. If N is greater than or equal to the sum of A, it prints the difference; otherwise, it prints "-1".
