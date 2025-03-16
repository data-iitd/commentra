
s = raw_input()

for j in range(len(s)):
    for i in range(len(s)):
        if i!= j and s[i] == s[j]:
            print "no"
            break
    else:
        print "yes"
        break

