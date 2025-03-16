from itertools import permutations

def main():
    n = int(input())
    line = [["" for _ in range(1)] for _ in range(2)]
    
    for i in range(2):
        for j in range(n):
            line[i][0] += input()
    
    number = ''.join(str(i) for i in range(1, n + 1))
    listA = [''.join(p) for p in permutations(number)]
    
    sum_value = 0
    for j in range(len(line)):
        for i in range(len(listA)):
            if listA[i] == line[j][0]:
                if sum_value == 0:
                    sum_value += i
                else:
                    sum_value -= i
    
    print(abs(sum_value))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
