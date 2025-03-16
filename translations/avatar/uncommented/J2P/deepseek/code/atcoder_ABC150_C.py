import sys

def permutation(target, ans):
    if len(target) <= 1:
        return [ans + target]
    else:
        result = []
        for i in range(len(target)):
            result.extend(permutation(target[:i] + target[i+1:], ans + target[i]))
        return result

def main():
    n = int(input().strip())
    line = [input().strip() for _ in range(2)]
    number = ''.join(str(i) for i in range(1, n + 1))
    listA = permutation(number, "")
    sum = 0
    for j in range(2):
        for i in range(len(listA)):
            if listA[i] == line[j]:
                if sum == 0:
                    sum += i
                else:
                    sum -= i
    print(abs(sum))

if __name__ == "__main__":
    main()
