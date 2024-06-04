from typing import List

def overlappingInterval(arr: List[List[int]]) -> List[List[int]]:
    n = len(arr)
    ans = []
    arr.sort()
    for i in range(n):
        if not ans or arr[i][0] > ans[-1][1]:
            ans.append(arr[i])
        else:
            ans[-1][1] = max(arr[i][1], ans[-1][1])
    return ans

if __name__ == "__main__":
    arr = [[1, 3], [8, 10], [2, 6], [15, 18]]
    ans = overlappingInterval(arr)
    print("The merged intervals are: ")
    for it in ans:
        print(f"[{it[0]}, {it[1]}]", end=" ")
    print()
