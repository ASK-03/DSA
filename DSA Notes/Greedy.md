## [Police and Thieves](https://www.geeksforgeeks.org/problems/police-and-thieves--141631/1)
1. Nice question. I am not able to solve greedy question. I should watch a video and work on this. 
2. [Failed Approach] - I was trying to mark the thieves that can be caught and then taking the minimum of catchable thieves and police. Sounds like a good approach but doesnot work for all. 
3. [Working Approach] - There are multiple working approaches, 2 queues, 1 queue, 2 pointers, but each one works on same principle that
	1. Explaining the 2 pointers approach
		- we move police pointer `p` that always points on police to first police in array
		- we move thief pointer `t` that always points on thief to first thief in array
		- now, we move on the array until one of p or t is out of array 
			- First we check if `abs(p-t) <= k` if yes then we increment count and increase p and t; (why coz we want them to go to next police and thief)
			- if `p<t` then we increment p
			- if `t<p` then we increment t
			- now we always bring `p` and `t` to point to police and thief resp.
	2. It was hard to think in my opinion, my first intuition was to check using array. I think my brain is not ready for greedy. I should solve more `greedy` question. 

```cpp
class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        int n = arr.size();
        int police = 0;
        int thief = 0;
        
        while (police<n && arr[police]!='P') {
            police++;
        }
        
        while (thief<n && arr[thief]!='T') {
            thief++;
        }
        
        int count=0;
        while (police<n && thief<n) {
            if (abs(police-thief)<=k) {
                count++;
                police++;
                thief++;
            }
            else if (police < thief) police++;
            else if (thief < police) thief++;
            
            while (police<n && arr[police]!='P') {
                police++;
            }
            
            while (thief<n && arr[thief]!='T') {
                thief++;
            }
        }
        
        return count;
    }
};
```
## [Minimum Deletions to Make String K-Special](https://leetcode.com/problems/minimum-deletions-to-make-string-k-special/)
1. I was able to almost reach the solution. It means I am going in write direction just have to get better at problem solving more.
2. What I was not able to think is that we can individually select an element as having the least characters in the final string. Then it can be used as a reference that maximum a character can have `x+k` characters in final string. below this we delete everyone as this is the one with minimum character in the final string and above this if in range of k we dont do anything but above k we remove `freq[j]-freq[i]-k` elements.
3. And why are we able to do this because it can be proved that if we choose one element as having the minimum and its also intuitive that then the chosen character frequency will not be removed as it is already in range of `k`. below this will be completely removed and above this in range of k will be unharmed but above range of `x+k` will have to be removed to get in range of `x+k`
4. Now we do this for every character and return the best one (minimum number of ops).

## [Maximum Manhattan Distance After K Changes](https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes/)
Nice Question with a witty solution. 
1. One solution is to choose a preferred direction out of `{ NE, NW, SE, SW }` and add 1 to distance when you get the character of choice and subtract when other char appears and `k` is over (k<=0). This way we can calculate the max distance that can be reached by `k` changes in the string. 
2. Second solution is given below, I was thinking in the same lines, but was not able to think about this witty method to use `min` to advantage and `count` function to calculate the profit in distance we gain by changing the character. 

```cpp
class Solution {
	private:
		int count (int d1, int d2, int t) {
			return abs(d1-d2) + t*2;
		}
		
	public:
		int maxDistance(string s, int k) {
			int ans = 0;
			int cn, cs, cw, ce;
			cn=0; cs=0; cw=0; ce=0;
			for(char ch: s) {
				if (ch == 'N') {
					cn++;
				}
				else if (ch == 'S') {
					cs++;
				}
				else if (ch == 'E') {
					ce++;
				}
				else {
					cw++;
				}
				
				int t1 = min({cn, cs, k}); // this is pure intelligence here.
				int t2 = min({cw, ce, k-t1}); // I wasn't able to think this
				ans = max(ans, count(cn, cs, t1) + count(cw, ce, t2));
			}
			return ans;
		}
};
```

## [Replace Question Marks in String to Minimize Its Value](https://leetcode.com/problems/replace-question-marks-in-string-to-minimize-its-value/)
1. The fact that we can check what all chars we can add and then add then after sorting is great here.
2. Greedy solution. Currently I am getting confused in greedy and dp solution. I should work more on dp and greedy.