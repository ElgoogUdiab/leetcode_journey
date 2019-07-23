# Merge k Sorted Lists

Note: N is the total number of nodes, k is the number of lists.

## Solution 1: The most stupid way

Merge to one list then sort the list.

Time complexity: O(N log N)

- Merge to one array: O(N)

- Sort: O(N log N)

- Array to list: O(N)

The worst solution, not using the **sorted** condition at all.

## Solution 2: Known problem is the best

One k-merge can be solved by (k-1) [2-merge](/21).

Time complexity: O(kN)

- 2-merge has its own O(N) time complexity

- O(k) 2-merge problems to solve

## Solution 2.1: Inspired by merge sort

What? Merging one by one? It feels like insertion sort!

So instead of doing (((list_1 + list_2) + list_3) + list_4), let's do this:
((list_1 + list_2) + (list_3 + list_4))

Time complexity: O(N log k)

Solution [here](merge.cpp)

## Solution 3: Inspired by 2-merge

Compare the heads, find the largest, put in the new list.

Time compexity: O(kN)

- O(k) comparisons to find the smallest from k numbers

- O(N) items to be put in the result

## Solution 3.1: Improved method

Wait, O(k) comparisons to find the smallest from k numbers? Seriously?

If your answer is yes, then you really need to review data structure. Listen! Heap is crying now!

Building a heap needs only O(k) time. Also, getting the minimal node is O(1). Editing a node takes O(log k) for the heap.

Time complexity: O(N log k)

- Build heap: O(k)

- O(log k) for each item

- O(N) items to operate

Solution [here](heap.cpp)
