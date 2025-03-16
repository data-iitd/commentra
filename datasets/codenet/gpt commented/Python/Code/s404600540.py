def main():
    # Read the prices of each type of ingredient (q, h, s, d) from input
    q, h, s, d = map(int, input().split())
    
    # Read the number of ingredients needed (n) from input
    n = int(input())
    
    # Calculate the minimum cost for one ingredient
    # This considers:
    # - Buying 4 of the cheapest ingredient (q)
    # - Buying 2 of the second cheapest ingredient (h)
    # - Buying 2 of the cheapest (q) and 1 of the second cheapest (h)
    # - Buying 1 of the third cheapest ingredient (s)
    min_1 = min(q*4, h*2, q*2+h, s)
    
    # Calculate the minimum cost for two ingredients
    # This considers either buying two of the minimum cost for one ingredient (min_1) or the cost of the bulk option (d)
    min_2 = min(min_1*2, d)

    # Calculate the total cost based on the number of ingredients needed (n)
    # If n is odd, add the cost of one ingredient (min_1)
    # If n is even, add the cost of two ingredients (min_2) for half of n
    print((n % 2)*min_1 + (n // 2)*min_2)

if __name__ == '__main__':
    main()
