T = int(input())
S = int(input())
q = int(input())
previous = S
answer = 0

while previous < T:
    answer += 1
    previous *= q

print(answer)  # <END-OF-CODE>
