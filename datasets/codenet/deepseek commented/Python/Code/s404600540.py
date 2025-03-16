
def main():
    # Read the costs of different units of water
    q, h, s, d = map(int, input().split())
    
    # Read the total amount of water needed
    n = int(input())
    
    # Calculate the minimum cost for one unit of water
    # Consider all possible combinations: 4*q, 2*h, 2*q+h, and s
    min_1 = min(q*4, h*2, q*2+h, s)
    
    # Calculate the minimum cost for 2 units of water
    # This is either 2*min_1 or d, whichever is cheaper
    min_2 = min(min_1*2, d)
    
    # Calculate the total minimum cost based on whether n is even or odd
    # If n is odd, add the cost of one unit (min_1) to the cost of n//2 units of 2
    # If n is even, multiply the cost of 2 units (min_2) by n//2
    print((n % 2)*min_1 + (n // 2)*min_2)

if __name__ == '__main__':
    main()

