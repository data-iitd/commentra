
def generateString():
    sb = ""
    for i in range(1, 1001):
        sb += str(i)
    return sb

if __name__ == '__main__':
    n = int(input())
    print(generateString()[n-1])

