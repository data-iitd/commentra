
N, K = map(int, input().split())  # Read the number of students (N) and the number of preferences (K)
A = []  # Initialize an empty list to keep track of students' preferences

for i in range(N):  # Initialize the list A with zeros for all students
    A.append(0)

for i in range(K):  # Loop through each of the K students
    d = int(input())  # Read the number of preferences for the i-th student
    AA = list(map(int, input().split()))  # Read the list of preferences for the i-th student
    for j in range(d):  # Loop through each of the student's preferences
        A[AA[j] - 1] = 1  # Mark the student's preference in the list A

n = 0  # Initialize a counter to count students without any preferences
for i in range(N):  # Loop through each student to count those without preferences
    if A[i] == 0:
        n += 1
print(n)  # Print the count of students without any preferences

