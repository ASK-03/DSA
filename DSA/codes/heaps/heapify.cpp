#include <bits/stdc++.h>

using namespace std;

void heapify(vector<int> &vec, int idx)
{
    int n = vec.size();
    if (n == 0)
    {
        cout << "Nothing to heapify" << endl;
        return;
    }

    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    int parent = idx;

    if (left < n && vec[left] > vec[parent])
    {
        parent = left;
    }

    if (right < n && vec[right] > vec[parent])
    {
        parent = right;
    }

    if (parent != idx)
    {
        swap(vec[parent], vec[idx]);
        heapify(vec, parent);
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    for (int i = (arr.size() - 1) / 2; i >= 0; i--)
    {
        heapify(arr, i);
    }

    for (int i : arr)
        cout << i << " ";
    cout << endl;
    return 0;
}