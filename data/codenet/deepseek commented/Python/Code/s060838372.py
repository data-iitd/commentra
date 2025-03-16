
N, K = map(int, input().split())
# Input N and K, where N is the number of elements in the list and K is the specific index.

S = list(input())
# Take a string input and convert it into a list of characters.

if S[K-1] == "A":
  # Check if the character at the K-th position (adjusted for 0-indexing) is 'A'.
  S[K-1] = "a"
  # If so, change it to 'a'.
elif S[K-1] == "B":
  # Check if the character at the K-th position is 'B'.
  S[K-1] = "b"
  # If so, change it to 'b'.
else:
  # Otherwise, the character must be 'C'.
  S[K-1] = "c"
  # Change it to 'c'.

ans = "".join(S)
# Join the list back into a string.

print(ans)
# Print the resulting string.

