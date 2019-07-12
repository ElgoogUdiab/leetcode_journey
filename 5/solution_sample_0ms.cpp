class Solution {
public:
    string longestPalindrome(string s) {
        int max_len = 0, start = 0;
        for (int i = 0; i < s.size(); ) {
            // Starting from the s[i], let l and r be the left side and the right side of the palindrome substring.
            // The string is [i:j], both ends are included.
            int l = i, r = i;
            // Skip all duplicated characters.
            // e.g. lizssssssssssssssszp.
            // When i==3, r will go through all duplicated 's' and stop at the last one
            while (r < s.size() - 1 && s[r] == s[r + 1]) r++;
            i = r + 1;
            // Expanding the palindrome substring
            while (l > 0 && r < s.size() - 1 && s[l - 1] == s[r + 1]) {
                l--;
                r++;
            }
            // If the length is longer, store the new length and the starting point
            if (r - l + 1 > max_len) {
                max_len = r - l + 1;
                start = l;
            }
        }
        return s.substr(start, max_len);
    }
};