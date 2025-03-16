def permutation(target, ans):
 if len(target) <= 1:
 return [ans + target]
 else:
 result = []
 for i in range(len(target)):
 result += permutation(target[:i] + target[i+1:], ans + target[i])
 return result

def main():
 n = int(input())
 number = ""
 for i in range(1, n+1):
 number += str(i)

 listA = permutation(number, "")

 sum = 0
 for _ in range(int(input())):
 line = input().split()
 for i in range(len(listA)):
 if listA[i] == line[0]:
 if sum == 0:
 sum += i
 else:
 sum -= i

 print(abs(sum))

main()

