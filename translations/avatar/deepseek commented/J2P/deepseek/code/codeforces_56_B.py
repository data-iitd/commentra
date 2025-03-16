def main():
    len_array = int(input())
    array = list(map(int, input().split()))
    
    start_index = 0
    end_index = 0
    flag = False
    is_unsorted = False
    
    for i in range(len_array):
        if array[i] != i + 1 and not flag:
            start_index = i + 1
            flag = True
            continue
        if array[i] != i + 1 and flag:
            end_index = i + 1
            if array[end_index - 1] > array[end_index - 2]:
                is_unsorted = True
                break
    
    if not is_unsorted:
        print(f"{start_index} {end_index}")
    else:
        print("0 0")

main()
