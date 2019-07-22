# Generate Parentheses

```
n = 1
l
└── l Failed (left max reached) Result: ()

n = 2
l
├── l
│   └── l Failed (left max reached) Result: (())
└── r
    ├── l
    │   └── l Failed (left max reached) Result: ()()
    └── r Failed (right > left, abort)

n = 3
l
├── l
│   ├── l
│   │   ├── l Failed (left max reached) Result: ((()))
│   └── r
│       ├── l
│       │   └── l Failed (left max reached) Result: (()())
│       └── r
│           ├── l
│           │   └── l Failed (left max reached) Result: (())()
│           └── r Failed (right > left, abort)
└── r
    ├── l
    │   ├── l
    │   │   └── l Failed (left max reached) Result: ()(())
    │   └── r
    │       ├── l
    │       │   └── l Failed (left max reached) Result: ()()()
    │       └── r Failed (right > left, abort)
    └── r Failed (right > left, abort)
```

So a pattern can be seen.

However, since n is a variable, either a stack is maintained by programmer (iterative), or the call stack is used (recursive).

[This solution](recursive.cpp) uses the recursive method, and [this solution](iterative.cpp) uses the iterative method.

Note: recursive method uses more memory, and iterative method is much easier to write when a working recursive solution is available.
