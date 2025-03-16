def scan_int():
    return int(input().strip())

def main():
    r = scan_int()
    D = scan_int()
    x = scan_int()
    
    for i in range(10):
        x = r * x - D
        print(x)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
