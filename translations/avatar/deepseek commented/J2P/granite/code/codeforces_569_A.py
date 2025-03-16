

T = int(input())
S = int(input())
q = int(input())
previous = S
answer = 0
while previous < T:
    previous *= q
    answer += 1
print(answer)
