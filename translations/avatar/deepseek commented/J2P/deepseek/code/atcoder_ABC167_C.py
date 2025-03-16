import sys

def main():
    # Reading input
    n, m, x = map(int, sys.stdin.readline().split())
    a = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
    
    min_cost = float('inf')  # Initializing the minimum cost to a large value
    
    # Generating all possible combinations of ingredients
    for i in range(1 << n):
        status = [0] * n  # Array to store the status of each ingredient in the combination
        for j in range(n):
            if (i & (1 << j)):  # Checking if the j-th ingredient is included
                status[j] = 1
        
        res = [0] * (m + 1)  # Array to store the total nutrient amounts for the current combination
        for j in range(n):
            if status[j] == 1:  # Adding the nutrient amounts of included ingredients
                for k in range(m + 1):
                    res[k] += a[j][k]
        
        # Checking if the current combination meets the requirement
        if all(r >= x for r in res[1:]):
            min_cost = min(min_cost, res[0])  # Updating the minimum cost if the requirement is met
    
    # Outputting the result
    print(-1 if min_cost == float('inf') else min_cost)

if __name__ == "__main__":
    main()
