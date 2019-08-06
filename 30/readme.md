# Substring with Concatenation of All Words

## First solution

Code [here](solution_1.cpp)

This piece of solution does the following things:

Make a dict, converting the `vector<string> words` to a `(word, count)` hash table.

Starting from the first character to the `s.length() - words.size() * word_length + 1`th character, try to minus the count of every word to zero.

There seems to be a better solution.
