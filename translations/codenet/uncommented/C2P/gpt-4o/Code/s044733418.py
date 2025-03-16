import sys

def compare(a, b):
    return b - a

def main():
    array = []
    for i in range(10):
        array.append(int(sys.stdin.readline().strip()))
    
    array.sort(key=lambda x: -x)  # Sort in descending order using a key function
    
    for i in range(3):
        print(array[i])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
