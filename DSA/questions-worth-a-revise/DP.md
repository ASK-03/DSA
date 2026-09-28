## [Count Number of Maximum Bitwise-OR Subsets](https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/)
1. The constraints are low (1<=len<=16), so the recursion and memoization works.
2. Problem arises when trying to optimize the for better space complexity and bottom up solution
3. In normal bottom up solution, with vector<vector<>>

```c++
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        unordered_map<int, int> dp;
        dp[0] = 1;  // base case: empty subset has OR = 0

        for (int num : nums) {
            unordered_map<int, int> new_dp = dp;  // copy current state
            for (auto& [or_val, count] : dp) {
                new_dp[or_val | num] += count;
            }
            dp = move(new_dp);
        }

        // Find the maximum OR value
        int max_or = 0;
        for (int num : nums) max_or |= num;

        return dp[max_or];
    }
};
```

This solution actually takes into account all the possible OR values that can be made using all the subsets.
## [Largest Divisible Subset](https://www.geeksforgeeks.org/problems/largest-divisible-subset--170643/1)
1. I was able to code the backtracking solution, but changing that backtracking solution to optimal memoisation code was like changing the whole code.
2. First define the recurrence, check the recurrence relation and then code the recursive solution.
3. The most optimal code for this question

```cpp
class Solution {
public:
    vector<int> largestSubset(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
    
        vector<int> dp(n, 1), parent(n, -1);
        int maxSize = 1, maxIdx = 0;
    
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (arr[j] % arr[i] == 0) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    } else if (dp[j] + 1 == dp[i] && (parent[i] == -1 || arr[j] > arr[parent[i]])) {
                        parent[i] = j;
                    }
                }
            }
    
            if (dp[i] > maxSize || (dp[i] == maxSize && arr[i] > arr[maxIdx])) {
                maxSize = dp[i];
                maxIdx = i;
            }
        }
    
        vector<int> subset;
        int curr = maxIdx;
        while (curr != -1) {
            subset.push_back(arr[curr]);
            curr = parent[curr];
        }
    
        return subset;
    }
};   
```

