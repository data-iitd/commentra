import sys

def main():
    input = sys.stdin.read
    data = input().splitlines()
    
    n = int(data[0])
    vec = []
    
    for i in range(1, n + 1):
        vec.append(list(map(int, data[i].split())))
    
    ans = 500
    ansprice = 20000
    
    for i in range(n):
        fl = 1
        for j in range(n):
            if vec[i][0] < vec[j][0] and vec[i][1] < vec[j][1] and vec[i][2] < vec[j][2]:
                fl = 0
                break
        
        if fl == 1:
            if vec[i][3] < ansprice:
                ansprice = vec[i][3]
                ans = i + 1
    
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
