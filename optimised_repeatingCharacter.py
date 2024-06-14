def lengthOfLongestSubstring(s: str) -> int:
    mp = [-1] * 256
    
    left, right = 0, 0
    n = len(s)
    length = 0
    while right < n:
        if mp[ord(s[right])] != -1:
            left = max(mp[ord(s[right])] + 1, left)
        
        mp[ord(s[right])] = right
        length = max(length, right - left + 1)
        right += 1
    return length

if __name__ == "__main__":
    a = "takeUforward"
    print("The longest subsequence is ", lengthOfLongestSubstring(a))
    