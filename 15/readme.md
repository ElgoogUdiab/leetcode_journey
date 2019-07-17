# 3Sum

Here I've got two solutions, the hash table one and the two-pointer one.
Both solution would have O(n^2) time complexity, while two-ptr solution may take less space.

I'll implement the hash-map one first.

## Hash table (TLE)

Code [here](hash_table.cpp).

It's called *code* not *solution* due to the TLE.

What I want to do is divide the given 3-sum problem into O(n) 2-sum problems.

However this solution results in TLE on a `n=3000` case.

## Two pointer

Come on, this problem has literally two tags: **array** and **two pointer**.

Solution [here](two_ptr.cpp)

Explaination in comment.

The basic idea is the same, divide the given 3-sum problem into O(n) 2-sum problems.
However, instead of giving out the index, in this problem, we only need to return the value, therefore we can sort the array(vector) and use two pointers(LR) to swipe through the remaining array in O(n), skipping impossible solutions.

BTW, sorting is O(n log n) therefore not affecting the overall O(n^2) time complexity.
