from typing import List

def gridPath(i, j , n, m,dp: List[List[int]]) -> int:
    if i == n - 1 and j == m - 1:
        return 1
    if i >= n or j >= m:
        return 0
    if dp[i][j] != -1: return dp[i][j]
    else: 
        dp[i][j] = gridPath(i+1, j, n, m, dp) + gridPath(i, j + 1, n, m, dp)
        return dp[i][j]

if __name__ == "__main__":
    n, m = 3, 7
    dp = [[-1 for _ in range(n + 1)] for _ in range(m + 1)]
    print("The total number of paths is ", gridPath(0, 0, n, m, dp))
