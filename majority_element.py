from typing import List
def majority_element(a: List[int]) -> int:
    n = len(a)
    cnt = 0
    elem = 0
    for i in range(0, n):
        if cnt == 0:
            cnt = 1
            elem = a[i]
        elif elem == a[i]:
            cnt += 1
        else: cnt -= 1
    cnt = 0

    for i in range(n):
        if a[i] == elem:
            cnt += 1
    if cnt > (n // 2): return elem
    return -1

if __name__ == "__main__":
    print("The majority element is :")
    a = [2, 2, 1, 1, 1, 2, 2]
    print(majority_element(a))
