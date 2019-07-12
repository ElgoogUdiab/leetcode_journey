# Longest Palindromic Substring

Well, a tough one.

Three methods will be mentioned here.

## Brute force

Solution [here](brute_force.cpp)

Go through EVERY substring and see if this substring is a palindrome. O(n^3) time complexity. The horrible solution.

## Dynamic programming

Solution [here](dp.cpp)

Not actually the way to solve this problem, but worth mentioning.

Use dynamic programming to find the longest common substring of the given string and the reverse of the given string.

Find the result by finding the longest upper-left arrow chain in the direction matrix and that chain repersents the result.

O(n^2) time complexity, O(n^2) space complexity.

## Manachar's Algorithm

Solution [here](manacher.cpp)

A very very clever way to find the longest palindrome.

Adding empty character between each character, then find and store the longest palindrome radius starting from each character.

There are some clever ways to reduce the amount of characters that the radius need to be calculated by using symmetry.

O(n) time complexity, O(n) space complexity.

## The final solution

Solution [here](solution_sample_0ms)

This solution is the sample 0ms solution given by leetcode.

Analysis is written in the source code.
