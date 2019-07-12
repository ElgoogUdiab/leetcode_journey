# Regular Expression Matching

This problem is kind of silly, since usually a language will have its own regex library.

## C++ Regex

Solution [here](solution_lib.cpp)

## Dynamic programming

Solution [here](solution_dp.cpp)

Did something different here. The regex is tokenized so that `a` and `a*` are basically the same thing, which can shrink a little of the size of the dp matrix.
