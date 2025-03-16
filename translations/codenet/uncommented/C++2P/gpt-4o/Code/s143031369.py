import math
import sys

PI = math.acos(-1.0)

def sig(d):
    return 0 if abs(d) < 1e-8 else (-1 if d < 0 else 1)

class Point:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    def set(self, x, y):
        self.x = x
        self.y = y

    def mod(self):
        return math.sqrt(self.x * self.x + self.y * self.y)

    def mod_pow(self):
        return self.x * self.x + self.y * self.y

    def __lt__(self, other):
        return sig(self.x - other.x) != 0 and self.x < other.x or sig(self.y - other.y) < 0

def dot(o, a, b):
    return (a.x - o.x) * (b.x - o.x) + (a.y - o.y) * (b.y - o.y)

def dot_simple(a, b):
    return a.x * b.x + a.y * b.y

def cross(o, a, b):
    return (a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y)

def btw(x, a, b):
    return sig(dot(x, a, b))

def dis(a, b):
    return math.sqrt((a.x - b.x) ** 2 + (a.y - b.y) ** 2)

def cos(o, a, b):
    return dot(o, a, b) / dis(o, a) / dis(o, b)

def jarvis(p, n):
    d = 0
    for i in range(n):
        if p[i] < p[d]:
            d = i
    l = s = ch[0] = d
    d = 1
    while True:
        o = l
        for i in range(n):
            t = sig(cross(p[o], p[l], p[i]))
            if t > 0 or (t == 0 and btw(p[l], p[o], p[i]) <= 0):
                l = i
        ch.append(l)
        if l == s:
            break
        d += 1
    return d - 1

if __name__ == "__main__":
    ang = [0] * 110
    ans = [0] * 110
    n = int(input())
    P = [Point() for _ in range(110)]
    for i in range(n):
        xx, yy = map(int, input().split())
        P[i].set(xx, yy)
    
    if n == 2:
        print("0.5")
        print("0.5")
    else:
        ch = []
        m = jarvis(P, n)
        sum = 0
        if m == 2:
            ans[ch[0]] = 0.5
            ans[ch[1]] = 0.5
        else:
            for i in range(m):
                ang[ch[i]] = PI - math.acos(cos(P[ch[i]], P[ch[(i - 1 + m) % m]], P[ch[(i + 1) % m]]))
            for i in range(n):
                ans[i] = ang[i] / 2.0 / PI
        
        for i in range(n):
            print(f"{ans[i]:.20f}")

# <END-OF-CODE>
