from collections import Counter

class Solution(object):
    def smallestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        count = Counter(s)
        length = len(s)
        sorted_s = sorted(s)
        first_half = []
        for char in sorted(count.keys()):
            first_half.extend([char] * (count[char] // 2))

        fullString = ''
        left = ''.join(first_half)
        right = ''.join(reversed(first_half))
        middle = sorted_s[length//2]

        if length % 2 == 1:
            middle = sorted_s[length // 2]
            fullString = left + middle + right
        else:
            fullString = left + right

        return fullString