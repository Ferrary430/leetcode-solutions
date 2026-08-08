class Solution:
    def validSequence(self, word1: str, word2: str) -> List[int]:
        n, m = len(word1), len(word2)
        last_match = [-1] * m

        j = m - 1
        for i in range(n - 1, -1, -1):
            if j >= 0 and word1[i] == word2[j]:
                last_match[j] = i
                j -= 1
                
        ans = []
        j = 0
        changed = False

        for i in range(n):
            if j == m:
                break

            if word1[i] == word2[j]:
                ans.append(i)
                j += 1
            elif not changed:
                if j + 1 == m or (last_match[j + 1] != -1 and last_match[j + 1] > i):
                    ans.append(i)
                    j += 1
                    changed = True
        
        return ans if len(ans) == m else []


# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna