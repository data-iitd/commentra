def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    n = int(data[0])
    FfriendPerDay = [0] * 367
    MfriendPerDay = [0] * 367
    answer = 0
    
    for i in range(1, n + 1):
        line = data[i].split()
        c = line[0]
        a = int(line[1])
        b = int(line[2])
        
        for j in range(a, b + 1):
            if c == 'M':
                MfriendPerDay[j] += 1
            else:
                FfriendPerDay[j] += 1
            
            if MfriendPerDay[j] < FfriendPerDay[j]:
                if MfriendPerDay[j] > answer:
                    answer = MfriendPerDay[j]
            else:
                if FfriendPerDay[j] > answer:
                    answer = FfriendPerDay[j]
    
    print(answer * 2)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
