## [Longest Well-Performing Interval](https://leetcode.com/problems/longest-well-performing-interval/)
1. Uses two pointers only, I think I should work on 2 pointers.
2. I was not able to think of using map; so that I can find the least index with has sum as currsum-1; 
3. Two major problems in my code were 
	1. ❌ Bug 1: `mp[0] = 0` is **incorrect**. This initialization implies that the prefix sum `0` first occurred at index `0`, **but that's not true**
	2. **maxi = max(maxi, r-mp[sum-1] + 1)**, we dont have to add 1. `r-mp[sum-1]` is already enough. 
