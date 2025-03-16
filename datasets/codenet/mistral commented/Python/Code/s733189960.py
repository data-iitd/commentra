# Define the main function
def main():
  # Read the number of strings from the user input
  n = int(input())

  # Initialize an empty dictionary to store the unique strings and their frequencies
  sdic = {}

  # Iterate through each string in the input for n times
  for _ in range(n):
    # Read a string from the user input, sort its characters in ascending order, and join them into a single string
    s = [_s for _s in sorted(input().strip())]
    s = ''.join(s)

    # If the string is already in the dictionary, increment its frequency by 1
    if s in sdic:
      sdic[s] += 1
    # Otherwise, add the string to the dictionary with a frequency of 1
    else:
      sdic[s] = 1

  # Calculate the answer by summing up the combinatorial number of ways two distinct strings of the same length can be chosen from the dictionary
  ans = 0
  for k, v in sdic.items():
    ans += v*(v-1)//2

  # Print the answer
  print(ans)

# Run the main function if the script is executed directly
if __name__ == '__main__':
  main()
