import sys

def is_solution(columns_count, x):
    all_xs = [True] * columns_count
    for i in range(12):
        if x[i] != 'X':
            all_xs[i % columns_count] = False
    return any(all_xs)

def main():
    input = sys.stdin.read
    data = input().splitlines()
    t = int(data[0])
    results = []
    
    for i in range(1, t + 1):
        possible_solutions = 0
        solutions = []
        s = data[i]
        
        if is_solution(12, s):
            solutions.append("1x12")
            possible_solutions += 1
        if is_solution(6, s):
            solutions.append("2x6")
            possible_solutions += 1
        if is_solution(4, s):
            solutions.append("3x4")
            possible_solutions += 1
        if is_solution(3, s):
            solutions.append("4x3")
            possible_solutions += 1
        if is_solution(2, s):
            solutions.append("6x2")
            possible_solutions += 1
        if is_solution(1, s):
            solutions.append("12x1")
            possible_solutions += 1
        
        results.append(f"{possible_solutions} {' '.join(solutions)}")
    
    print("\n".join(results))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
