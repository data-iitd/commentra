

n = int(input()) # read the number of contest results
ac_count = 0 # initialize the number of AC results
wa_count = 0 # initialize the number of WA results
tle_count = 0 # initialize the number of TLE results
re_count = 0 # initialize the number of RE results

for i in range(n): # read each contest result and update the corresponding counter
    s = input() # read the contest result (AC, WA, TLE, or RE)
    if s=="AC": # if the contest result is AC
        ac_count+=1 # increment the number of AC results
    elif s=="WA": # if the contest result is WA
        wa_count+=1 # increment the number of WA results
    elif s=="TLE": # if the contest result is TLE
        tle_count+=1 # increment the number of TLE results
    elif s=="RE": # if the contest result is RE
        re_count+=1 # increment the number of RE results

print("AC x", ac_count) # print the number of AC results
print("WA x", wa_count) # print the number of WA results
print("TLE x", tle_count) # print the number of TLE results
print("RE x", re_count) # print the number of RE results

