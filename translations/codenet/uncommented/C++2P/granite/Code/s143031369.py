
import math

def sig(d):
    return abs(d) < 1e-8 and 0 or d < 0 and -1 or 1

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def set(self, x, y):
        self.x = x
        self.y = y

    def mod(self):
        return math.sqrt(self.x*self.x+self.y*self.y)

    def mod_pow(self):
        return self.x*self.x + self.y*self.y

    def output(self):
        print("x = %f, y = %f" % (self.x, self.y))

    def __lt__(self, p):
        return sig(self.x-p.x)!= 0 and self.x < p.x or sig(self.y-p.y) < 0

P = []
for _ in range(int(input())):
    x, y = map(float, input().split())
    P.append(Point(x, y))

ch = []
ang = [0.0] * len(P)
ans = [0.0] * len(P)

def dot(o, a, b):
    return (a.x-o.x)*(b.x-o.x) + (a.y-o.y)*(b.y-o.y)

def dot(a, b):
    return a.x*b.x + a.y*b.y

def cross(o, a, b):
    return (a.x - o.x)*(b.y - o.y)-(b.x - o.x)*(a.y - o.y)

def btw(x, a, b):
    return sig(dot(x, a, b))

def dis(a, b):
    return math.sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))

def cos(o, a, b):
    return dot(o,a,b)/dis(o,a)/dis(o,b)

def jarvis(p, n, ch):
    d, i, o, s, l, t = 0, 0, 0, 0, 0, 0
    for i in range(n):
        if p[i] < p[d]:
            d = i
    l = s = ch[0] = d
    d = 1
    while True:
        o = l
        for i in range(n):
            if (t:=sig(cross(p[o], p[l], p[i])))>0 or (t==0 and btw(p[l], p[o], p[i])<=0):
                l = i
        ch[d] = l
        if l == s:
            break
        d += 1
    return d-1

m = jarvis(P, len(P), ch)

if m == 2:
    ans[ch[0]] = 0.5
    ans[ch[1]] = 0.5
else:
    for i in range(m):
        ang[ch[i]] = math.pi - math.acos(cos(P[ch[i]], P[ch[(i-1+m)%m]], P[ch[(i+1)%m]]))
    for i in range(len(P)):
        ans[i] = ang[i]/2./math.pi

for i in range(len(P)):
    print("%.20f" % ans[i])

The above Python code is a translation of the given C++ code. It includes the necessary functions and classes to perform the same geometric calculations as the original C++ code. The code also includes the necessary input/output operations to read the input points and print the output angles.