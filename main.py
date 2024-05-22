from typing import List
class Solution:
    def hanota(self, A: List[int], B: List[int], C: List[int]) -> None:
        """
        Do not return anything, modify C in-place instead.
        """
        self.move(len(A), A, B, C)
        print(C)

    def move(self, n, A, B, C):
        if n == 1:
            C.append(A.pop())
        else:
            self.move(n - 1, A, C, B)
            C.append(A.pop())
            self.move(n - 1, B, A, C)


if __name__ == '__main__':
    solution = Solution()
    solution.hanota([2, 1, 0], [], [])
