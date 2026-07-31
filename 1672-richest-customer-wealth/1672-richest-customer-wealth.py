class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        return max(sum(client) for client in accounts)

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna