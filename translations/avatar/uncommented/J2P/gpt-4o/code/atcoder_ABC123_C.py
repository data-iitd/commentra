import math

def main():
    N = int(input())
    min_value = None
    for i in range(5):
        if i == 0:
            min_value = int(input())
        else:
            min_value = min(min_value, int(input()))
    
    result = math.ceil(N / min_value) + 4
    print(result)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
