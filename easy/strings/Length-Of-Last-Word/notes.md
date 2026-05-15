# What tripped me up

- Handling trailing whitespace correctly before counting the last word.
- Separating the problem into two phases:
  1. skip trailing spaces
  2. count the final word

---

# Conceptual mistakes

- I initially thought I needed to trim or modify the string itself. In reality, I only needed to move the index backwards and ignore spaces.
- I tried combining “skip spaces” and “count characters” into one loop, which made the logic confusing and contradictory.
- I forgot that I only care about the final word, so processing the entire string from the front was unnecessary.
- I initially treated the string like a raw C-style character array rather than using the higher-level std::string operations available in C++.

---

# C++ syntax / logic mistakes

- I used sizeof(s) instead of s.size(). sizeof returns the size of the string object in memory, not the number of characters in the string.
- I started at s.size() instead of s.size() - 1, causing out-of-bounds indexing.
- I wrote while(s[i] >= 0), which checked the ASCII value of the character instead of whether the index itself was valid.
- I confused logical operators in conditions. I originally used if(s[i] != '\0' || s[i] != ' '), which is almost always true.
- I initially checked s[i] before checking i >= 0, risking out-of-bounds access. The correct order was while(i >= 0 && s[i] == ' ') because && short-circuits left-to-right.

---

# Process lessons

- Working backwards from the end of the string was the key insight because the problem only cares about the final word.
- Breaking the problem into two separate loops made the logic much easier to reason about:
  - skip trailing spaces
  - count characters in the last word
- Tracing test cases manually exposed contradictions in my loop conditions very quickly.
- Testing edge cases early ("a", "a ", "Hello World ", " ") helped validate both the boundary logic and whitespace handling.
- The final solution became much simpler once I stopped trying to modify the string and instead just moved the index pointer backwards.