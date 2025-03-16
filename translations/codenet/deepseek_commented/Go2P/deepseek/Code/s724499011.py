def main():
    # Read the integer n and the string s from the standard input
    n = int(input())
    s = input()
    
    # Convert the characters in s to their corresponding integer values
    # 'R' -> 0, 'G' -> 1, 'B' -> 2
    ns = [ord(c) - ord('A') for c in s]
    
    # Construct a cumulative count array rgb to keep track of the counts of each color up to each position
    rgb = [[0] * 3 for _ in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(3):
            rgb[i][j] = rgb[i - 1][j]
        rgb[i][ns[i - 1]] += 1
    
    # Calculate the number of valid triplets (i, j, k) where ns[i] != ns[j] != ns[k] and ns[k] == tn
    # where tn is the third color different from ns[i] and ns[j]
    sum = 0
    for i in range(n - 2):
        for j in range(i + 1, n - 1):
            if ns[i] != ns[j]:
                tn = (3 - ns[i] - ns[j]) % 3
                sum += rgb[n][tn] - rgb[j + 1][tn]
                k = 2 * j - i
                if k < n and ns[k] == tn:
                    sum -= 1
    
    # Print the result
    print(sum)

main()
