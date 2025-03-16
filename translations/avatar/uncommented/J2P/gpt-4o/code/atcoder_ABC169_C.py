def main():
    import sys
    
    a = int(sys.stdin.readline().strip())
    b = sys.stdin.readline().strip()
    
    bStr = ''.join([char for char in b if char != '.'])
    bInt = int(bStr)
    
    result = (a * bInt) // 100
    print(result)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
