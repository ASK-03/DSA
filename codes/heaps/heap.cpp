#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class MaxHeap
{
    vector<int> heap;
    int capacity; // max size of the heap
    int size;     // current size of the heap

public:
    MaxHeap(int c)
    {
        size = 0;
        capacity = c;
    }

    void insert(int val)
    {
        if (size >= capacity)
        {
            cout << "Heap capacity full! Can't add new element" << endl;
            return;
        }

        size++;
        heap.push_back(val);
        int idx = size - 1;
        while (idx > 0)
        {
            int parent = (idx & 1) ? idx / 2 : idx / 2 - 1;

            if (parent >= 0 && heap[parent] < heap[idx])
            {
                swap(heap[parent], heap[idx]);
                idx = parent;
            }
            else
            {
                break;
            }
        }
    }

    void print()
    {
        if (size == 0)
        {
            cout << "No element in heap to print" << endl;
            return;
        }

        for (int i : heap)
        {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main()
{
    MaxHeap heap = MaxHeap(5);
    heap.insert(5);
    heap.insert(4);
    heap.insert(3);
    heap.insert(2);
    heap.insert(6);

    heap.print();

    return 0;
}