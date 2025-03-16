

def generate_string():
    sb = ""
    for i in range(1, 1001):
        sb += str(i)
    return sb

def main():
    n = int(input())
    print(generate_string()[n-1])

if __name__ == "__main__":
    main()

