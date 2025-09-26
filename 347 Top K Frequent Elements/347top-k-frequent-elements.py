class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = defaultdict(int) # maps each value to its count
        for value in nums:
            freq[value] += 1 # iterating through the hash map

        # frequ.items iterates through hash
        # key = shows what value to use comparing items
        # lambda creates anon function and x is each item from freq.items hash
        # reverse = descending order
        freq = dict(sorted(freq.items(), key=lambda x: x[1], reverse=True))

        res = list(freq.keys())[:k]

        return res
        