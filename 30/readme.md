# Substring with Concatenation of All Words

## First solution

Code [here](solution_1.cpp)

This piece of solution does the following things:

Make a dict, converting the `vector<string> words` to a `(word, count)` hash table.

Starting from the first character to the `s.length() - words.size() * word_length + 1`th character, try to minus the count of every word to zero.

There seems to be a better solution.

## Second solution

Code [here](solution_2.cpp)

The first step is preserved.

Instead of checking in the numerical order, we do the `mod word_length` order (in order `0, 3, 6, 1, 4, 7, 2, 5` if we have 7 items and `word_length` is 3).

So when we failed at one position because of too much of a word, like `"barfoobarthe" ["bar", "foo", "the"]` at the second `bar`, we don't need to give up the `foo` we've already get, we can just throw away the first `bar`.
