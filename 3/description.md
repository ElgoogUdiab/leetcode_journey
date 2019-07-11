# Longest Substring Without Repeating Characters

Solution [here](solution_1.cpp)

Store where each possible character was met before.
When meet one repeating character, store the new position, then update the length with `index - the_new_tail`.
`the_new_tail` is determined by the latest second-met character and the new character we get.

O(n) time complexity, O(1) space complexity.

Q.E.D.
