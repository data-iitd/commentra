

import sys

def main():
    input = sys.stdin.read().splitlines()
    m, s, f = map(int, input[0].split())
    max_t = -1
    map = {}

    for i in range(1, m + 1):
        k, a, b = map(int, input[i].split())
        max_t = max(max_t, k)
        map[k] = [a, b]

    actions = []
    direction = 'R' if s < f else 'L'
    step = 1 if s < f else -1
    current = s
    a = -1
    b = -1

    for t in range(1, max_t + 1):
        if t in map:
            a, b = map[t]
            if current >= a and current <= b or current + step >= a and current + step <= b:
                actions.append('X')
            else:
                actions.append(direction)
                current += step
            if current == f:
                break
        else:
            actions.append(direction)
            current += step

    while current!= f:
        actions.append(direction)
        current += step

    print(''.join(actions))

if __name__ == '__main__':
    main()

