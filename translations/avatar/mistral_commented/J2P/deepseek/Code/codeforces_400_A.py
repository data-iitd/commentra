def is_solution(columns_count, x):
    all_xs = [True] * columns_count

    for i in range(len(x)):
        if x[i] != 'X':
            all_xs[i % columns_count] = False

    for i in range(columns_count):
        if all_xs[i]:
            return True

    return False


def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    t = int(data[0])
    index = 1
    results = []

    for _ in range(t):
        possible_solutions = 0
        solutions = []

        s = data[index]
        index += 1

        if is_solution(12, s):
            solutions.append(" 1x12")
            possible_solutions += 1

        if is_solution(6, s):
            solutions.append(" 2x6")
            possible_solutions += 1

        if is_solution(4, s):
            solutions.append(" 3x4")
            possible_solutions += 1

        if is_solution(3, s):
            solutions.append(" 4x3")
            possible_solutions += 1

        if is_solution(2, s):
            solutions.append(" 6x2")
            possible_solutions += 1

        if is_solution(1, s):
            solutions.append(" 12x1")
            possible_solutions += 1

        results.append(f"{possible_solutions} {' '.join(solutions)}")

    print("\n".join(results))


main()
