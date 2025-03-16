N = 1000

while True:
    su = ['0'] * N
    susum = 0
    j = 0
    
    while True:
        su[j] = input()[0]  # Read a single character
        if su[j] == '\n':
            break
        susum += (ord(su[j]) - ord('0'))
        j += 1
        
    if su[0] == '0':
        break
    print(susum)
    susum = 0

# <END-OF-CODE>
