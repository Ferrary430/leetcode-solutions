class Solution:
    def myAtoi(self, s: str) -> int:
        s = s.lstrip()
        if not s:
            return 0
        i = 0
        sign = 1
        if s[0] == '-':
            sign = -1
            i += 1
        if s[0] == '+':
            i += 1
        res = 0
        while i < len(s) and s[i].isdigit():
            res = res * 10 + int(s[i])
            i += 1
        
        res *= sign
        MIN,MAX = -2**31, 2**31 - 1
        if res < MIN: return MIN
        if res > MAX: return MAX
        return res

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna