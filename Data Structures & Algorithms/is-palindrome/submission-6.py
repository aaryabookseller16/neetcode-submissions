class Solution:
    def isPalindrome(self, s: str) -> bool:
        clean_str = re.sub(r'[^a-zA-Z0-9]', '', s).lower()

        print(clean_str)

        i = 0
        j = len(clean_str) - 1

        while j >= i:
            if clean_str[i] != clean_str[j]:
                return False
            print(f"{i},{j}")
            i += 1
            j -= 1

        return True

        