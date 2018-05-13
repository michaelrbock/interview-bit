# https://www.interviewbit.com/problems/longest-consecutive-sequence/

class Solution:
    # @param A : tuple of integers
    # @return an integer
    def longestConsecutive(self, A):
        A_set = set(A)
        result = 0

        for index, elem in enumerate(A):
            prev = elem - 1
            next = elem + 1
            # Is this the start of a possible sequence?
            if prev not in A_set:
                while next in A_set:
                    next += 1
                result = max(result, next - elem)

        return result