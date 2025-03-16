from collections import defaultdict

def time2min(month, day, hour, minute):
    total_day_of_month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    total = 0
    for i in range(1, month):
        total += total_day_of_month[i - 1] * 24 * 60
    for i in range(1, day):
        total += 24 * 60
    total += hour * 60 + minute
    return total

def main():
    while True:
        N = int(input())
        if N == 0:
            break

        log = defaultdict(list)
        for _ in range(N):
            entry = input().strip().split()
            month, day = map(int, entry[0].split('/'))
            hour, minute = map(int, entry[1].split(':'))
            action = entry[2]
            id = int(entry[3])

            t = time2min(month, day, hour, minute)
            log[id].append(t)

        total = [0] * 1000

        for i in range(0, len(log[0]), 2):
            god_start = log[0][i]
            god_end = log[0][i + 1]

            for id, schedule in log.items():
                if id == 0:
                    continue
                for j in range(0, len(schedule), 2):
                    ppl_start = schedule[j]
                    ppl_end = schedule[j + 1]
                    start = max(god_start, ppl_start)
                    end = min(god_end, ppl_end)
                    total[id] += max(0, end - start)

        max_v = max(total)
        print(max_v)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
