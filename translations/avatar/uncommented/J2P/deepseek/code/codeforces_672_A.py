def generate_string():
    sb = ""
    for i in range(1, 1001):
        sb += str(i)
    return list(sb)

def main():
    n = int(input())
    string_list = generate_string()
    print(string_list[n - 1])

if __name__ == "__main__":
    main()
