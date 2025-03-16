def main():
  n = int(input())  # 1. The function `main()` is the entry point of the program.
  sdic = {}  # 2. An empty dictionary `sdic` is initialized to store the sorted versions of the input strings and their counts.
  for _ in range(n):  # 4. A for loop runs `n` times, where in each iteration:
    s = [_s for _s in sorted(input().strip())]  # - It takes a string input, splits it into characters, sorts the characters, and joins them back into a string.
    s = ''.join(s)  # - This sorted string is then used as a key in the dictionary `sdic`.
    if s in sdic:  # - If the key already exists in the dictionary, its value is incremented by 1.
      sdic[s] += 1
    else:  # - If the key does not exist, a new entry is created with the value set to 1.
      sdic[s] = 1
  ans = 0  # 6. Another for loop iterates over the items in `sdic`, calculating the number of pairs of strings that can be formed with the same sorted version.
  for k, v in sdic.items():  # 7. The result is stored in the variable `ans`, which is the sum of the products of the count and (count - 1) divided by 2 for each key-value pair in `sdic`.
    ans += v*(v-1)//2
  print(ans)  # 8. Finally, the result is printed.


if __name__ == '__main__':
  main()
