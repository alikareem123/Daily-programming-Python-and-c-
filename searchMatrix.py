from typing import List


def searchMatrix(arr: List[List[int]], target) -> bool:
    n = len(arr)
    m = len(arr[0])
    low = 0
    high = n * m - 1
    while low <= high:
        mid = (low + high) // 2
        row = mid // m
        col = mid % m
        if arr[row][col] == target:
            return True
        elif arr[row][col] < target:
            low = mid + 1
        else:
            high = mid - 1
    return False

if __name__ == "__main__":
    arr = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]
    print("The result is ")
    print(searchMatrix(arr, 45))


