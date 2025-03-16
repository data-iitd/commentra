import sys

def main():
    input = sys.stdin.readline
    N, K = map(int, input().split())
    S = input().strip()
    
    c1 = list(S)
    c3 = list(S)
    
    flag = False
    count = 0
    
    # Process c1 (Left to Right)
    for i in range(N):
        if flag and c1[i] == 'R':
            flag = False
            count += 1
        if count == K:
            break
        if c1[i] == 'L':
            flag = True
            c1[i] = 'R'
    
    flag = False
    count = 0
    
    # Process c3 (Right to Left)
    for i in range(N):
        if flag and c3[i] == 'L':
            flag = False
            count += 1
        if count == K:
            break
        if c3[i] == 'R':
            flag = True
            c3[i] = 'L'
    
    S1 = ''.join(c1)
    S3 = ''.join(c3)
    
    count = 1
    sum1 = 0
    bef = S1[0]
    
    # Count consecutive characters in S1
    for i in range(1, N):
        if S1[i] == bef:
            count += 1
            if i == N - 1:
                sum1 += count - 1
        else:
            bef = S1[i]
            sum1 += count - 1
            count = 1
    
    count = 1
    sum3 = 0
    bef = S3[0]
    
    # Count consecutive characters in S3
    for i in range(1, N):
        if S3[i] == bef:
            count += 1
            if i == N - 1:
                sum3 += count - 1
        else:
            bef = S3[i]
            sum3 += count - 1
            count = 1
    
    # Print the maximum of the two sums
    print(max(sum1, sum3))

if __name__ == "__main__":
    main()
