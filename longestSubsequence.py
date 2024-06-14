from typing import List
def longestSubs(a: List[int]) -> int:
    n = len(a)
    longest = 0
    st = set()
    
    for i in range(n):
        st.add(a[i])
    
    for it in st:
        if it - 1 not in st:
            cnt = 1
            x = it
            while x + 1 in st:
                x += 1
                cnt += 1
            longest = max(longest, cnt)
    return longest

if __name__ == "__main__":
    a = [100, 200, 1, 2, 3, 4, 0]
    ans = longestSubs(a)
    print("The longest subsequence is ", ans)
    