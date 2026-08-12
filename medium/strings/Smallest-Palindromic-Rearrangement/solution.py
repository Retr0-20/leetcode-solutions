from collections import Counter

class Solution(object):
    def smallestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        count = Counter(s)
        length = len(s)
        first_half = []
        fullString = ''

        for char in sorted(count.keys()):
            first_half.extend([char] * (count[char] // 2))

        left = ''.join(first_half)
        right = ''.join(reversed(first_half))
        middle = ''
        
        for char in count:
            if count[char] % 2 == 1:
                middle = char
                break

        if length % 2 == 1:
            fullString = left + middle + right
        else:
            fullString = left + right

        return fullString