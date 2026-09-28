#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

#define fo(a, b) for (auto i = a; i < b; ++i)

using namespace std;

/*
    Brute:
        - A pointer iterating over the array
        - we will do linear search for the next element in the array and keep doing it until we cant find one

    TC - O(N^2)
    SC - O(1)
*/

/*
    Better:
        - sort the array
        - keep the count of the consequtive elements
            - if the previous element is consequtive we will increase the count and update the longest
            - if it is equal we will do nothing
            - if it isnt consequtive, we will reset the counter to zero and continue the process
*/

int better(vi &arr)
{
    if (arr.size() == 0)
        return 0;

    int longest = 1, count = 0, prevEle = INT_MIN;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        if (prevEle == arr[i] - 1)
        {
            count++;
            prevEle = arr[i];
        }
        else if (prevEle != arr[i])
        {
            count = 1;
            prevEle = arr[i];
        }
        longest = max(longest, count);
    }

    return longest;
}

/*
    Optimal:
     
    TC - O(3N) - under the assumption that set takes O(1) time to find element
    SC - O(N)

*/

int optimal(vi &arr)
{
    int n = arr.size(), longest = 1;
    if (n == 0){
        return 0;
    }
    unordered_set<int> st;
    fo(0, n)
    {
        st.insert(arr[i]);
    }

    for (auto i : st)
    {
        if (st.find(i - 1) == st.end())
        {
            int cnt = 1, x = i;
            while (st.find(x + 1) != st.end())
            {
                cnt++;
                x++;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

int main()
{
    vi arr = {102, 4, 100, 1, 101, 3, 2, 1, 1};

    cout << optimal(arr) << endl;
    return 0;
}