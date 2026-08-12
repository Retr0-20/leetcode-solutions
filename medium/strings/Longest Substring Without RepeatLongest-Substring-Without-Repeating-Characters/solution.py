class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """

        left = 0
        seen = set()
        max_length = 0

        for right in range(len(s)):
            char = s[right]

            while char in seen:         # If duplicate exists
                seen.remove(s[left])    # Remove leftmost char
                left += 1               # Shrink the window

            seen.add(char)              # Add new char
            max_length = max(max_length, right - left + 1) # Track Length

        return max_length
