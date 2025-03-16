import sys

class Main:
    MOD = 1000000007
    MAX = sys.maxsize
    LMAX = sys.maxsize

    def do_it(self):
        sc = sys.stdin
        N = int(next(sc).strip())
        K = int(next(sc).strip())
        A = list(map(lambda x: int(x) - 1, next(sc).strip().split()))

        used = set()
        idx = [0] * N
        pos = [0] * N
        next_idx = 0
        cur_idx = 0

        while next_idx not in used:
            used.add(next_idx)
            idx[next_idx] = cur_idx
            pos[cur_idx] = next_idx
            next_idx = A[next_idx]
            cur_idx += 1

        cycle_length = cur_idx - idx[next_idx]
        cycle_start = idx[next_idx]
        ans = (10000 * cycle_length + K - cycle_start) % cycle_length + cycle_start

        if cycle_start > K:
            ans = K

        print(pos[ans] + 1)

if __name__ == "__main__":
    Main().do_it()
