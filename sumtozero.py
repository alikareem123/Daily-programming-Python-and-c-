from typing import List
def solve(a: List[int]) -> int:
    n = len(a)
    sum = 0
    maxLen = 0
    mp = {}
    for i in range(n):
        sum += a[i]
        if sum == 0:
            maxLen = i + 1
        elif sum in mp:
            maxLen = max(maxLen, i - mp[sum])
        else: mp[sum] = i
    return maxLen

if __name__ == "__main__":
    a = [9, -3, 3, -1, 6, -5]
    print("The length is ", solve(a))
    