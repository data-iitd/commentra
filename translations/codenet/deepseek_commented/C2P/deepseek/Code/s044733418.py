def compare(a, b):
    return b - a

def main():
    array = []
    for _ in range(10):
        array.append(int(input()))
    array.sort(key=compare)
    for i in range(3):
        print(array[i])

main()
