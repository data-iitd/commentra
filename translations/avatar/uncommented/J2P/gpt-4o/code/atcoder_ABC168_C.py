import math

def main():
    A = int(input())
    B = int(input())
    H = int(input())
    M = int(input())
    
    AA = A
    BB = B
    HH = H
    MM = M
    
    mkaku = MM * 6
    hkaku = HH * 30 + M / 2
    kaku = mkaku - hkaku
    
    dkaku = abs(math.radians(kaku))
    
    AA2 = AA * AA
    BB2 = BB * BB
    CC = AA2 + BB2
    DD = 2 * math.cos(dkaku) * AA * BB
    
    ans2 = CC - DD
    dans2 = ans2
    
    ans = math.sqrt(dans2)
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
