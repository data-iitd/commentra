

S = input()

i = 2

while i <= len(S):
    if S[:(len(S)-i)//2] == S[(len(S)-i)//2:len(S)-i]:
        print(len(S) - i)
        break
    i += 2

