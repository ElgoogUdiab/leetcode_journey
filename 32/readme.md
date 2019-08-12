# Longest Valid Parentheses

Solution [here](solution.cpp)

A dynamic programming problem

With `dp[i]` means the length of the longest valid parentheses sequence ends at `s[i]`, the following equation can get the solution.

```
dp[0] = 0

dp[1] = 2                              s.substr(0, 2) == "()"
        0                              otherwise

dp[i] = dp[i-2] + 2                    s[i] == ')' && s[i-1] == '('
        dp[i-1] + 2                    s[i] == ')' && s[i-1] == ')' && s[i-1-dp[i-1]] == '(' && i-1-dp[i-1] == 0
        dp[i-1] + 2 + dp[i-dp[i-1]-2]  s[i] == ')' && s[i-1] == ')' && s[i-1-dp[i-1]] == '(' && i-1-dp[i-1] > 0
        0                              otherwise
```

Situation 1 stands for `(some valid sequence)()`.

Situation 2 stands for `#start_of_s#((some valid sequence))`.

Situation 3 stands for `(some valid sequence)((some valid sequence))`.

Note: an empty sequence is also considered as a "valid" sequence.

The result is `max(dp)`.
