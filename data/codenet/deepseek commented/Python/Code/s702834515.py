
"""
i が 3 でも 5 でも割り切れるなら、ai=FizzBuzz
そうではなく i
が 3 で割り切れるなら、ai=Fizz
そうではなく i
が 5 で割り切れるなら、ai=Buzz
そうではないなら、ai=i
"""
n=int(input())  # Take an integer input `n`
r=0  # Initialize `r` to 0
for ii in range(n):  # Loop `n` times
  if (ii+1)%3!=0 and (ii+1)%5!=0:  # Check if `ii` (plus 1) is not divisible by 3 or 5
    r+=(ii+1)  # Add `ii` (plus 1) to `r`
print(r)  # Print the value of `r`

