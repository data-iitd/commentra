import sys

def main():
    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])
    x = int(data[1])
    sweet = []
    
    for i in range(2, 2 + N):
        sweet.append(int(data[i]))
    
    sweet.sort()
    num = 0
    
    for i in range(N):
        if x - sweet[num] >= 0:
            x -= sweet[num]
            num += 1
        else:
            break
    
    if num == N and x > 0:
        num -= 1
    
    print(num)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
