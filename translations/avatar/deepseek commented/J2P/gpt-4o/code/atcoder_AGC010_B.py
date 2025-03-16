def possible(N, A):
    total_sum = sum(A)  # Calculate the sum of the elements in the array A
    NS = N * (N + 1) // 2  # Calculate the sum of the first N natural numbers (NS)
    if total_sum % NS != 0:
        return False  # Check if the sum of the array A is divisible by NS. If not, return false
    K = total_sum // NS  # Calculate the value of K
    for i in range(N):
        j = N - 1 if i == 0 else i - 1  # Calculate the index of the previous element in the array A
        d = K - (A[i] - A[j])  # Calculate the difference
        if d < 0 or d % N != 0:
            return False  # Check if the difference is negative or not divisible by N. If so, return false
    return True  # If all elements satisfy the condition, return true


def main():
    N = int(input())  # Read the number of elements N from the user
    A = list(map(int, input().split()))  # Read N integers from the user and store them in the array A
    if possible(N, A):  # Call the possible method to check if the array A can be rearranged to satisfy a certain condition
        print("YES")  # Print "YES" if the condition is satisfied
    else:
        print("NO")  # Print "NO" if the condition is not satisfied


if __name__ == "__main__":
    main()

# <END-OF-CODE>
