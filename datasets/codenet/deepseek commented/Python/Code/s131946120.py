
n=int(input())  # Take the number of strings as input
print(len(set([input() for _ in range(n)])))  # Take n strings, remove duplicates, and print the count of unique strings

