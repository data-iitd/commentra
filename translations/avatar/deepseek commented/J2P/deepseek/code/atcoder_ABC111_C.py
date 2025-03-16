import sys

def main():
    n = int(input().strip())  # Read the size of the array
    v = list(map(int, input().strip().split()))  # Read the values into the array
    vo = [0] * 100010  # Initialize arrays to count odd and even numbers
    ve = [0] * 100010
    vt = [0] * 100010
    
    for i in range(n):
        vt[v[i]] += 1  # Count all numbers
        if i % 2 == 0:
            ve[v[i]] += 1  # Count even numbers
        else:
            vo[v[i]] += 1  # Count odd numbers
    
    vo_max = max(vo)
    ve_max = max(ve)
    vt_max = max(vt)
    
    vo_index = vo.index(vo_max)
    ve_index = ve.index(ve_max)
    
    if vo_max + ve_max == vt_max:
        ans = min(n - vo_max - ve[list(reversed(vo)).index(sorted(vo)[-2])], n - vo[list(reversed(ve)).index(sorted(ve)[-2])] - ve_max)
    else:
        ans = n - vo_max - ve_max
    
    print(ans)

if __name__ == "__main__":
    main()
