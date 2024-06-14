
def repeating(a: str) -> float:
    if len(a) == 0:
        return 0
    max_ans = float('-inf')
    for i in range(len(a)):
        set = {}
        for j in range(i, len(a)):
            if a[j] in set:
                max_ans = max(max_ans, j - i)
                break
            set[a[j]] = 1
    return max_ans

if __name__ == "__main__":
    a = "takeUforward"
    print("The answer is ", repeating(a))
