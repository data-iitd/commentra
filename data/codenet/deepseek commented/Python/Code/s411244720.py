
N, K = [int(_) for _ in input().split()]  # Read the total number of students (N) and the number of clubs (K)
S = set()  # Initialize an empty set to store unique members of all clubs

for i in range(K):  # Loop through each club
    d = int(input())  # Read the number of members in the current club
    A = [int(_) for _ in input().split()]  # Read the list of members in the current club
    S = S | set(A)  # Update the set S to include all members from the current club

print(N - len(S))  # Calculate and print the number of students who are not members of any club

