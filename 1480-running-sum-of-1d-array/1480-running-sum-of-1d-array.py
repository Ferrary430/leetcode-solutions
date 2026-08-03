class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        total = 0
        sums = []
        for num in nums:
            total += num
            sums.append(total)
        return sums


# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna