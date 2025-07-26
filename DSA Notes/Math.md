## [Broken Calculator](https://leetcode.com/problems/broken-calculator/)
1. Tried using bfs but it gave tle. 
2. Tried to think about the math solution but wasnt able to. I think I will have to work on math as well. 
3. I think it is crazy how this dividing and adding 1 is working and then adding (startValue-target) in the result is working but it is correct.

```cpp
int brokenCalc(int startValue, int target) {	
	int result = 0;
	while (target > startValue) {
		result++;
		if (target % 2 == 0) target/=2;
		else target++;
	}
	result += (startValue-target);
	return result
}
```

## [Sum of k-Mirror Numbers](https://leetcode.com/problems/sum-of-k-mirror-numbers/) 
1. I was able to think of the solution but didnt know how to generate palindrome.

```cpp
class Solution {
public:
    long long createPalindrome(long long num, bool odd) {
        long long x = num;
        if (odd) x /= 10;
        while (x > 0) {
            num = num * 10 + x % 10;
            x /= 10;
        }
        return num;
    }

    bool isPalindrome(long long num, int base) {
        vector<int> digits;
        while (num > 0) {
            digits.push_back(num % base);
            num /= base;
        }
        int i = 0, j = digits.size() - 1;
        while (i < j) {
            if (digits[i++] != digits[j--]) return false;
        }
        return true;
    }

    long long kMirror(int k, int n) {
        long long sum = 0;
        for (long long len = 1; n > 0; len *= 10) {
            for (long long i = len; n > 0 && i < len * 10; i++) {
                long long p = createPalindrome(i, true);
                if (isPalindrome(p, k)) {
                    sum += p;
                    n--;
                }
            }
            for (long long i = len; n > 0 && i < len * 10; i++) {
                long long p = createPalindrome(i, false);
                if (isPalindrome(p, k)) {
                    sum += p;
                    n--;
                }
            }
        }
        return sum;
    }
};
```

### Create a Palindrome 

```cpp
long long createPalindrome(long long num, bool odd) {
	long long x = num;
	if (odd) x /= 10; // to generate odd length palindrome eg. from 10 we can generate 101

	while (x>0) {
		num = num * 10 + x % 10;
		x /= 10;
	}

	return num;
}
```

### To Generate Palindrome in Sequence from 1..n
```cpp
vector<long long> generateNPalindrome(long long n) {
	vector<long long> palindromes;
	for(long long len=1; n>0; len*=10) {
		for(long long i=len; n>0 && i<len*10; i++) {
			palindromes.push_back(createPalindrome(i, true));
			n--;
		}
		for(long long i=len; n>0 && i<len*10; i++) {
			palindromes.push_back(createPalindrome(i, false));
			n--;
		}
	}
	return palindromes;
}
```
