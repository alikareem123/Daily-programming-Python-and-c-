def swapIfGreater(arr1, arr2, n, m):
    if arr1[n] > arr2[m]:
        arr1[n], arr2[m] = arr2[m], arr1[n]

def merge(arr1, arr2, n, m):
    len = n + m
    gap = (len // 2) + (len % 2)
    while gap > 0:
        left = 0
        right = left + gap
        while right < len:
            if left < n and right >= n:
                swapIfGreater(arr1, arr2, left, right - n)
            elif right > n:
                swapIfGreater(arr2, arr2, left - n, right - n)
            else:
                swapIfGreater(arr1, arr1, left, right)
            left += 1
            right += 1
        if gap == 1:
            break
        gap = (gap // 2) + (gap % 2)

if __name__ == '__main__':
    arr1 = [1, 4, 8, 10]
    arr2 = [2, 3, 9]
    n = 4
    m = 3
    merge(arr1, arr2, n, m)

    print("The merged arrays are:")
    print("arr1[] = ", end="")
    for i in range(n):
        print(arr1[i], end=" ")
    print("\narr2[] = ", end="")
    for i in range(m):
        print(arr2[i], end=" ")
    print()