/*
 * InsertionSort.py
 *
 *  Created on: 2014/07/25
 *      Author: WanWan1985
 */
 
def sort(vecIntValue):
 
    for i in range(len(vecIntValue)):
 
        if i != 0:
 
            iIntValue = vecIntValue[i]
            j = i - 1
            while (j >= 0) and (vecIntValue[j] > iIntValue):
                vecIntValue[j+1] = vecIntValue[j]
                j -= 1
            vecIntValue[j+1] = iIntValue
 
        for k in range(len(vecIntValue)):
            print(vecIntValue[k], end=" ")
        print()
 
if __name__ == "__main__":
 
    iNum = int(input())
    vecIntValue = []
    while iNum:
        iIntValue = int(input())
        vecIntValue.append(iIntValue)
        iNum -= 1
 
    sort(vecIntValue)
 
    # 