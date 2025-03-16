import sys; # Importing the sys module for input operations

def main():
    D = int(sys.stdin.readline()); # Reading the number of problems
    G = int(sys.stdin.readline()); # Reading the target score
    p = [0] * D; # Array to store the number of problems completed
    c = [0] * D; # Array to store the bonus points for each problem

    # Reading the number of problems completed and the bonus points for each problem
    for i in range(D):
        p[i], c[i] = map(int, sys.stdin.readline().split());

    min = 100000; # Initializing the minimum number of problems solved to a large value

    # Using bitmask to iterate through all possible combinations of problem completions
    for bit in range(1 << D):
        score = 0; # Initializing the current score
        solve_num = 0; # Initializing the number of problems solved

        # Calculating the total score and the number of problems solved for the current combination
        for i in range(D):
            if (bit & (1 << i))!= 0:
                score += 100 * (i + 1) * p[i] + c[i];
                solve_num += p[i];

        # If the score is less than the target, try to maximize the score by completing remaining problems
        if (score < G):
            for i in range(D - 1, -1, -1):
                if (bit & (1 << i)) == 0:
                    for j in range(p[i] - 1):
                        score += 100 * (i + 1);
                        solve_num += 1;
                        if (score >= G):
                            break;

        # Updating the minimum number of problems solved if the current combination meets or exceeds the target score
        if (score >= G):
            min = min if min < solve_num else solve_num;

    # Output the minimum number of problems solved to achieve the target score
    print(min);

if __name__ == "__main__":
    main();

