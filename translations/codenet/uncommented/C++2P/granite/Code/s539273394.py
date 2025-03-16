
import sys
sys.setrecursionlimit(1000000)

def sosuubunnpu():
    prime_or_not = [0]*1001
    prime_list = []
    prime_counter = 0
    for i in range(1,1001):
        prime_or_not[i] = 0
    for i in range(2,1001):
        for j in range(2,1001//i+1):
            if prime_or_not[i] == 0:
                prime_or_not[i*j] = 1
        if prime_or_not[i] == 0:
            prime_list.append(i)
            prime_counter += 1

def innsuubunnkai(N,n):
    time = 0
    while True:
        if N%n == 0:
            N = N//n
            time += 1
        else:
            break
    return [time,N]

def main():
    sosuubunnpu()
    N = int(input())
    innsuu = [0]*11
    prime_num = [0]*1001
    for current_num in range(2,N+1):
        kekka = innsuubunnkai(current_num,2)
        for i in range(prime_counter):
            kekka = innsuubunnkai(kekka[1],prime_list[i])
            prime_num[i] += kekka[0]
    for current_num in range(2,N+1):
        for i in range(11):
            innsuu[i] += A[current_num][i]
    result = 1
    for i in range(prime_counter):
        result = (result*(prime_num[i]+1))%1000000007
    print(result)

if __name__ == "__main__":
    main()

