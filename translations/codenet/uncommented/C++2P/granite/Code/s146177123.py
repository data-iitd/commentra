
import sys

def seg(t):
    return [0,1,1,1,1,1,1] if t==0 else \
           [0,0,0,0,1,1,0] if t==1 else \
           [1,0,1,1,0,1,1] if t==2 else \
           [1,0,0,1,1,1,1] if t==3 else \
           [1,1,0,0,1,1,0] if t==4 else \
           [1,1,0,1,1,0,1] if t==5 else \
           [1,1,1,1,1,0,1] if t==6 else \
           [0,1,0,0,1,1,1] if t==7 else \
           [1,1,1,1,1,1,1] if t==8 else \
           [1,1,0,1,1,1,1] if t==9 else None

def main():
    for l in sys.stdin:
        n = int(l)
        if n == -1:
            break
        st = [0] * 7
        for i in range(n):
            t = int(input())
            ans = [str(st[i]^s) for i, s in enumerate(seg(t))]
            print("".join(ans))
            st = seg(t)

if __name__ == '__main__':
    main()

