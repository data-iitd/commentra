import numpy as np

n, k = map(int, input().split())

# Step 1: Input Reading
# The code starts by reading two integers, `n` and `k`, from the standard input.

if n > k:
    # Step 2: Condition Check
    # The code then checks if `n` is greater than `k`.
    
    tmp = n % k
    # Step 3: Modulo Operation
    # If `n` is greater than `k`, the code calculates the remainder of `n` divided by `k` and stores it in `tmp`.
    
    if tmp >= k - tmp:
        # Step 4: Comparison and Assignment
        # The code then checks if `tmp` is greater than or equal to `k - tmp`. If true, it assigns `k - tmp` to `ans`; otherwise, it assigns `tmp` to `ans`.
        ans = k - tmp
    else:
        ans = tmp
elif n < k:
    # Step 5: Alternative Condition
    # If `n` is not greater than `k`, the code checks if `n` is less than `k`.
    
    if n >= k - n:
        # Step 6: Similar Comparison and Assignment
        # If `n` is less than `k`, the code compares `n` with `k - n`. If `n` is greater than or equal to `k - n`, it assigns `k - n` to `ans`; otherwise, it assigns `n` to `ans`.
        ans = k - n
    else:
        ans = n
else:
    # Step 7: Equality Condition
    # If `n` is equal to `k`, the code assigns `0` to `ans`.
    ans = 0

# Step 8: Output the Result
# Finally, the code prints the value of `ans`.
print(ans)
