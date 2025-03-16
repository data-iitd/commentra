import sys
import argparse
import tracemalloc

magic = 1000000007

def find(n, p):
    for value in p:
        if n == value:
            return 0
    return 1

def solve():
    # Create an input reader
    input = sys.stdin.read
    data = input().splitlines()
    
    # Parse input
    X = int(data[0])
    N = int(data[1])
    p = list(map(int, data[2:2 + N]))

    # Check if X or its neighbors are present in the p list
    for i in range(101):
        if find(X - i, p) == 1:
            print(X - i)
            return
        if find(X + i, p) == 1:
            print(X + i)
            return

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--cpuprofile', type=str, help='File to write CPU profile to')
    parser.add_argument('--memprofile', type=str, help='File to write memory profile to')
    args = parser.parse_args()

    if args.cpuprofile:
        import cProfile
        profiler = cProfile.Profile()
        profiler.enable()

    solve()

    if args.cpuprofile:
        profiler.disable()
        profiler.dump_stats(args.cpuprofile)

    if args.memprofile:
        tracemalloc.start()
        snapshot = tracemalloc.take_snapshot()
        with open(args.memprofile, 'w') as f:
            for stat in snapshot.statistics('lineno'):
                f.write(str(stat) + '\n')

if __name__ == "__main__":
    main()

# <END-OF-CODE>
