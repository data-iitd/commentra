
a,b=map(int,input().split())
# Take two integer inputs from the user and assign them to variables `a` and `b`.

print(a+b if a==b else max(a,b)*2-1)
# Check if `a` is equal to `b`.
# If `a` is equal to `b`, print the sum of `a` and `b`.
# If `a` is not equal to `b`, print the result of `max(a,b)*2-1`.

