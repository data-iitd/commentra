#include <iostream>
#include <queue>

using namespace std;

struct task:
    name: str
    time: int

def main():
    n, q = map(int, input().split())
    elaps = 0
    Q = queue.Queue()

    for i in range(n):
        tmp = task()
        tmp.name, tmp.time = input().split()
        Q.put(tmp)

    while not Q.empty():
        p = Q.get()
        if p.time <= q:
            elaps += p.time
            print(p.name, elaps)
        else:
            p.time -= q
            elaps += q
            Q.put(p)

    return 0

