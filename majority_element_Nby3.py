from typing import List

def majority_elementby3(a: List[int]) -> List[int]:
    cnt1, cnt2 = 0, 0
    el1, el2 = float('-inf'), float('-inf')
    n = len(a)

    for i in range(n):
        if cnt1 == 0 and a[i] != el2:
            cnt1 = 1
            el1 = a[i]
        elif cnt2 == 0 and a[i] != el1:
            cnt2 = 1
            el2 = a[i]
        elif a[i] == el1: cnt1 += 1
        elif a[i] == el2: cnt2 += 1
        else:
            cnt1 -= 1
            cnt2 -= 1
    
    cnt1 = cnt2 = 0
    for i in range(n):
        if a[i] == el1: cnt1 += 1
        if a[i] == el2: cnt2 += 1
    
    min3 = int(n / 3) + 1
    ans = []
    if cnt1 > min3: ans.append(el1)
    if cnt2 > min3: ans.append(el2)
    
    return ans

if __name__ == "__main__":
    print("The majority elements are")
    a = [11, 33, 33, 11, 33, 11]
    ans = majority_elementby3(a)
    for it in ans:
        print(it, end=" ")
    print()