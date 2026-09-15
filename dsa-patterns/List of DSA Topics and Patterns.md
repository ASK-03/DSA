# List of DSA Topics and Patterns

This is the entry point for the whole `dsa-patterns` folder. Every topic below links to its own note. Work through them in order for a first pass, or jump straight to whichever one you're revising.

---

## How to Use This Folder

1. Pick one topic from the table below.
2. Open its file. Read **Recognize It** and the **Patterns table** first — that's the part you need to recall instantly in an interview.
3. Cover the **Must-Know Problems** table without looking, then solve the ones you blanked on from **Problem Links**.
4. Re-open a file only when you get a problem wrong — don't re-read files you already know cold.

---

## Note Format (use this for any new topic added later)

Every file in this folder follows the same 6-section shape, in this order. Keep new notes consistent with it — the fixed structure is what makes fast revision possible.

1. **Recognize It** — the exact trigger words/cues in a problem statement that point to this topic. This is the section you actually use mid-interview.
2. **Core Patterns table** — `Pattern | Example Problem | Key Idea`. One row per sub-pattern, never prose.
3. **Decision Checklist** — 3-5 yes/no questions to ask before picking an approach.
4. **Must-Know Problems table** — `Problem | Pattern | Key Idea`, ranked by how often it repeats, capped at ~10-12 rows.
5. **Code Templates** — the minimum code to memorize per pattern. No explanation prose inside code blocks, comments only where the logic isn't obvious from the code itself.
6. **Problem Links** — the actual queue of problems to solve, in the order to attempt them.

Rules that keep this ADHD-friendly:
- No emojis, no decorative symbols. They add visual noise, not information.
- No weekly/daily study plans inside individual topic files — the Must-Know Problems table IS the queue; a calendar on top of it just adds something to forget.
- Tables and code over paragraphs, always. If you're writing more than 2 sentences in a row, it should probably be a table row instead.
- Cap every list at what you'd actually act on today. A ranked list of 8 beats an exhaustive list of 30.

---

## Topics

| # | Topic | File |
|---|-------|------|
| 1 | Arrays & Hashing | [0. Arrays & Hashing.md](<./0. Arrays & Hashing.md>) |
| 2 | Two Pointers | [1. 2 Pointers.md](<./1. 2 Pointers.md>) |
| 3 | Sorting | [17. Sorting.md](<./17. Sorting.md>) |
| 4 | Binary Search | [3. Binary Search.md](<./3. Binary Search.md>) |
| 5 | Greedy | [2. Greedy.md](<./2. Greedy.md>) |
| 6 | Recursion & Backtracking | [4. Recursion & Backtracking.md](<./4. Recursion & Backtracking.md>) |
| 7 | Dynamic Programming | [5. Dynamic Programming.md](<./5. Dynamic Programming.md>) |
| 8 | Graph Algorithms | [6. Graphs.md](<./6. Graphs.md>) |
| 9 | Trie & String Algorithms | [7. Trie & String Algorithms.md](<./7. Trie & String Algorithms.md>) |
| 10 | Stacks and Queues | [8. Stacks & Queues.md](<./8. Stacks & Queues.md>) |
| 11 | Heap / Priority Queue | [9. Heap and PQ.md](<./9. Heap and PQ.md>) |
| 12 | Intervals | [10. Intervals.md](<./10. Intervals.md>) |
| 13 | Bit Manipulation | [11. Bit Manipulation.md](<./11. Bit Manipulation.md>) |
| 14 | Mathematics | [12. Mathematics.md](<./12. Mathematics.md>) |
| 15 | Linked List | [13. Linked List.md](<./13. Linked List.md>) |
| 16 | Trees & Binary Trees | [14. Trees & Binary Trees.md](<./14. Trees & Binary Trees.md>) |
| 17 | Binary Search Tree (BST) | [15. BST.md](<./15. BST.md>) |
| 18 | Segment Tree / Fenwick Tree | [16. Segment Trees & Fenwick Trees.md](<./16. Segment Trees & Fenwick Trees.md>) |
| 19 | Design Data Structures | [18. Design Data Structures.md](<./18. Design Data Structures.md>) |

---

## What Each Topic Covers

### 1. Arrays & Hashing
- Frequency Map / HashSet
- Prefix Sum
- Kadane's Algorithm
- Sorting as Preprocessing
- Cyclic Sort / Index Mapping

### 2. Two Pointers
- Left & Right Pointer Scan
- Sliding Window (Fixed and Variable)
- Fast & Slow Pointers (Floyd's Cycle)
- Meet in the Middle

### 3. Sorting
- Merge Sort, Quick Sort, Heap Sort
- Counting Sort
- Quickselect (Kth Largest/Smallest)
- Insertion Sort

### 4. Binary Search
- Standard Binary Search
- Search on Answer
- Lower/Upper Bound
- Peak Element / Bitonic Array
- Monotonic Predicate

### 5. Greedy
- Sort + Pick
- Min/Max Heap
- Two Pointers Greedy
- Stack for Undo
- Sweep Line
- Interval Merging

### 6. Recursion & Backtracking
- Subsets / Permutations
- N-Queens
- Sudoku Solver
- Palindrome Partitioning
- Combination Sum

### 7. Dynamic Programming (DP)
- 1D DP
- 2D DP (Grids, Strings)
- DP with State Compression (Bitmasking)
- DP on Trees
- Knapsack Patterns
- DP on Subsequences (LIS, LCS)
- Digit DP
- DP with Ranges (Matrix Chain, Burst Balloons)

### 8. Graph Algorithms
- BFS/DFS
- Topological Sort
- Dijkstra's Algorithm
- Bellman-Ford
- Floyd-Warshall
- Union-Find / Disjoint Set
- Minimum Spanning Tree (Prim's / Kruskal's)
- Bridges / Articulation Points
- Tarjan's Algorithm / Kosaraju's Algorithm (SCC)
- Cycle Detection

### 9. Trie / String Algorithms
- Trie Basics
- Prefix Trie with Count/Ends
- Rabin-Karp (Rolling Hash)
- KMP
- Z-Algorithm
- Palindrome Expansion / Manacher's
- Suffix Array / LCP

### 10. Stacks and Queues
- Monotonic Stack/Queue
- Next Greater Element
- Min Stack
- Stack Simulation (Expression Parsing)
- Sliding Window Maximum

### 11. Heap / Priority Queue
- K Largest/Smallest
- Median Maintenance (Two Heaps)
- Merge K Sorted Lists
- Huffman Coding
- Top K Frequent Elements

### 12. Intervals
- Interval Merging
- Line Sweep
- Difference Array
- Room/Platform Booking

### 13. Bit Manipulation
- Basic Bitwise Ops
- Subsets using Bits
- XOR Patterns
- Bitmask DP
- Trie + Bitmask (Max XOR)

### 14. Mathematics
- Prime Sieve
- GCD / LCM
- Modular Arithmetic
- Fast Exponentiation
- Combinatorics (nCr, Catalan)

### 15. Linked List
- Reverse in K-groups
- Detect Cycle
- Merge Sort on List
- Clone with Random Pointers
- Intersection Node

### 16. Trees & Binary Trees
- Inorder / Preorder / Postorder
- Level Order
- Diameter
- LCA
- Serialize/Deserialize

### 17. Binary Search Tree (BST)
- Insert/Delete/Search
- Kth Smallest/Largest
- Range Sum
- Convert to DLL

### 18. Segment Tree / Fenwick Tree
- Range Sum / Min / Max
- Lazy Propagation
- 2D BIT
- Persistent Segment Tree

### 19. Design Data Structures
- HashMap + Doubly Linked List (LRU Cache)
- HashMap + Frequency Buckets (LFU Cache)
- Two Stacks (Min Stack)
- HashMap + Array (O(1) Insert/Delete/Random)
- Trie / Nested HashMap (File System)
