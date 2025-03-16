N = 1000

while True:
    su = ['0'] * N
    susum = 0
    j = 0
    
    while True:
        for j in range(N):
            char_input = input()
            if char_input == '\n':
                break
            su[j] = char_input
            susum += int(su[j])
        if su[0] == '0':
            break
        print(susum)
        susum = 0
