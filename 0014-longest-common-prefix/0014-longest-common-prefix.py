class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ''

        strs.sort()

        first_str = strs[0]
        last_str = strs[-1]
        res_str = ''

        for i in range(min(len(first_str), len(last_str))):
            if first_str[i] != last_str[i]:
                break
            res_str += first_str[i]
        
        return res_str
        

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna