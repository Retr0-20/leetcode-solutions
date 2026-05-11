**Palindrome Number — what tripped me up**

**Conceptual mistakes**

- I treated `reverse()` as if it returned a new reversed string. In C++, `std::reverse()` modifies the existing string in-place and returns `void`.
- I reversed `s` directly instead of reversing a copy. I needed to preserve the original string for comparison.
- I copied the string *after* reversing it, meaning both variables ended up identical even for invalid cases like `121`.
- I initially forgot that negative numbers include a  sign when converted to strings, so `121` becomes `121-` when reversed.

**C++ / STL mistakes**

- I tried doing:

```cpp
std::string rev_s = reverse(...);
```

because I assumed `reverse()` returned a string.

- I declared `rev_s` without assigning anything to it, so it stayed empty until explicitly copied from `s`.
- I manually returned `true`/`false` with an `if/else` instead of just returning the comparison directly:

```cpp
return rev_s == s;
```

**Process lessons**

- Walking through variable values line-by-line exposed the bug immediately.
- Edge cases matter. `121` passing did not mean the logic was correct.
- Compiler errors are usually literal. “Cannot convert void to string” directly meant `reverse()` returned nothing.
- My actual algorithm was correct from the start:

```
convert -> copy -> reverse -> compare
```

Most mistakes were from translating that logic into valid C++.