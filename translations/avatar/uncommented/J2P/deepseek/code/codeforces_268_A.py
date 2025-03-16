import sys

def main():
    n = int(input().strip())
    h = []
    g = []
    for _ in range(n):
        line = input().strip().split()
        h.append(int(line[0]))
        g.append(int(line[1]))
    
    result = 0
    for i in range(n):
        for j in range(n):
            if h[i] == g[j]:
                result += 1
    
    print(result)

if __name__ == "__main__":
    main()
