import java.util.HashMap;

/**
 * optimised_repeatingCharacter
 */
public class optimised_repeatingCharacter {

    public static int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> mp = new HashMap<Character, Integer>();
        int left = 0, right = 0;
        int n = s.length();
        int len = 0;
        while (right < n) {
            if (mp.containsKey(s.charAt(right))) {
                left = Math.max(mp.get(s.charAt(right)) + 1, left);
            }
            mp.put(s.charAt(right), right);
            len = Math.max(len, right - left + 1);
            right++;
        }
        return len;
    }

    public static void main(String[] args) {
        String str = "takeUforward";
        System.out.println("The longest subsequence is " + lengthOfLongestSubstring(str));
    }
}