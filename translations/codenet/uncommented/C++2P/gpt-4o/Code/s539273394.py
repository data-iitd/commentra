def sosuubunnpu():
    global prime_or_not, prime_list, prime_counter
    prime_or_not = [0] * 1001
    prime_list = []
    prime_counter = 0
    
    for i in range(2, 1001):
        if prime_or_not[i] == 0:
            prime_list.append(i)
            prime_counter += 1
            for j in range(i * 2, 1001, i):
                prime_or_not[j] = 1

def innsuubunnkai(N, n):
    time = 0
    while N % n == 0:
        N //= n
        time += 1
    return time, N

def main():
    sosuubunnpu()
    N = int(input())
    prime_num = [0] * 1001
    result = 1
    
    for current_num in range(2, N + 1):
        kekka = [0, current_num]
        for i in range(prime_counter):
            time, kekka[1] = innsuubunnkai(kekka[1], prime_list[i])
            prime_num[i] += time
    
    for i in range(prime_counter):
        result = (result * (prime_num[i] + 1)) % 1000000007
    
    print(result)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
