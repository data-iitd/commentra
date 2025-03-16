
import sys

S = sys.stdin.readline().strip()
for i in range(2, len(S)+1, 2):
    if S[:len(S)-i] == S[len(S)-i:]:
        print(len(S)-i)
        break

