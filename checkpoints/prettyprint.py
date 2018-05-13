# https://www.interviewbit.com/problems/prettyprint/

class Solution:
    # @param A : integer
    # @return a list of list of integers
    def prettyPrint(self, A):
        if A == 1:
            return [[1]]
        length = A * 2 - 1
        end = length - 1
        result = [[0] * length for i in range(length)]
        for i in range(length):
            for j in range(length):
                decider = min(i, j, end - i, end - j)
                result[i][j] = A - decider
        return result
