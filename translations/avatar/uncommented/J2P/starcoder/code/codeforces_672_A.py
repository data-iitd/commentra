
# <START-OF-CODE>
def generateString():
    sb = []
    for i in range(1, 1001):
        sb.append(str(i))
    return ''.join(sb)

n = int(input())
print(generateString()[n-1])
# 