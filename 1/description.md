# 1. Two Sum

## The first solution: Brute force

Here's my [first solution](solution_1.cpp).
This is literally the first solution come into my mind, with O(1) space complexity and O(n^2) time complexity.

Can it be faster? Yes!

## The second solution: Hash-table

The solution is [here](solution_2.cpp).

Hash table is usually a good way to reduce the time for finding something again and again from the same place.

So when we get a number from the input vector, we first find this number in the hash table.
If not found (which is usual), we take `target-number` as key and the index as the value and store it into the table.
If found, we return the value we found and the index we have.

Thanks to the hash table, the avearge search time is O(1), therefore the average time complexity is O(n).
