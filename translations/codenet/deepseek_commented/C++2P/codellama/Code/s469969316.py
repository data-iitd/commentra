#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define rep(i,n) for (int i = 0; i < int(n); i++)

string input, ss;
int a[3], it, cnt;

# Step 1: Define the Not function
def Not(x):
    return 2-x

# Step 2: Define the And function
def And(x, y):
    if x*y == 0: return 0
    if x == 2 and y == 2: return 2
    return 1

# Step 3: Define the Or function
def Or(x, y):
    if x == 2 or y == 2: return 2
    if x == 1 or y == 1: return 1
    return 0

# Step 4: Implement the parse function
def parse():
    c = ss[it]
    it += 1
    if '0' <= c and c <= '2': return int(c)
    if c == '-': return Not(parse())

    x = parse()
    c = ss[it]
    it += 1
    y = parse()
    it += 1
    return c == '*' and And(x, y) or Or(x, y)

# Step 5: Implement the main function
def main():
    while True:
        input = input()
        if input == ".": break
        rep (i,3) a[i] = i
        cnt = 0
        rep (i,3) rep (j,3) rep (k,3) {
            a[0] = i
            a[1] = j
            a[2] = k
            ss = input
            for i in range(len(ss)):
                if ss[i] == 'P': ss[i] = a[0]+'0'
                if ss[i] == 'Q': ss[i] = a[1]+'0'
                if ss[i] == 'R': ss[i] = a[2]+'0'
            it = 0
            if parse() == 2: cnt += 1
        }
        print(cnt)

# Step 6: Output the count


