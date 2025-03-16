import sys

def main():
    n = int(input())  # Reading the number of ingredients
    m = int(input())  # Reading the number of nutrient types
    x = int(input())  # Reading the minimum requirement for each nutrient
    min_cost = sys.maxsize  # Initializing the minimum cost to a large value
    a = []  # Initializing the list to store nutrient amounts

    # Filling the list with nutrient amounts for each ingredient
    for _ in range(n):
        a.append(list(map(int, input().split())))

    # Generating all possible combinations of ingredients
    for i in range(1 << n):  # 2^n combinations
        status = [0] * n  # List to store the status of each ingredient in the combination
        for j in range(n):
            if (i & (1 << j)) != 0:  # Checking if the j-th ingredient is included
                status[j] = 1
        
        res = [0] * (m + 1)  # List to store the total nutrient amounts for the current combination
        for j in range(n):
            if status[j] == 1:  # Adding the nutrient amounts of included ingredients
                for k in range(m + 1):
                    res[k] += a[j][k]
        
        flag = True  # Flag to check if the current combination meets the requirement
        for j in range(1, m + 1):
            if res[j] < x:  # Checking if the nutrient requirement is met
                flag = False
                break
        
        if flag:
            min_cost = min(min_cost, res[0])  # Updating the minimum cost if the requirement is met

    # Outputting the result
    if min_cost == sys.maxsize:
        print(-1)  # Outputting -1 if no combination meets the requirement
    else:
        print(min_cost)  # Outputting the minimum cost if a valid combination is found

if __name__ == "__main__":
    main()

# <END-OF-CODE>
