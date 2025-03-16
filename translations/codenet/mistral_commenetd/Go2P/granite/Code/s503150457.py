

s1, s2, s3 = input().split()

s1s = list(s1)
s2s = list(s2)
s3s = list(s3)

print(''.join([s.upper() for s in [s1s[0], s2s[0], s3s[0]]]))
