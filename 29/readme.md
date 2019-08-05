# Divide Two Integers

Solution [here](solution.cpp)

Positive number division is easier to be done, so first convert to positive division.

The sign of the result is determined by the XOR of the sign bits of dividend and divisor.

As for the result, it has `(digits_of_dividend - digits_of_divisor + 1)` digits. Since they can only be 0 and 1, so just check each bit of the result from the highest digit to the lowest digit.
