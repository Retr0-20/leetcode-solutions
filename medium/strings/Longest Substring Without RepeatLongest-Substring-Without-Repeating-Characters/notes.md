**Conceptual mistakes**
- Confused substring (contiguous) with subsequence (non-contiguous)
- Tried including characters by skipping over duplicates instead of sliding a continuous window
- Counted unique characters globally across entire string instead of tracking what's in the current window
Locked left and right pointers together with right = left + 1, preventing independent movement
- Forgot to shrink the window when duplicates appear—only expanded forward
- Didn't realize I needed to track the maximum valid window size, not just count characters

**C++ syntax I got wrong**
- Used while(rightPointer != len(s)) instead of for right in range(len(s))—less Pythonic, harder to manage
- Tried using count2 = count2 + 1 to track unique chars instead of max_len = max(max_len, right - left + 1)
- Didn't initialize seen = set() before the loop—would cause NameError on first access
- Forgetting to increment left when shrinking—left += 1 needs to happen inside the inner while loop
- Window size calculation off-by-one: right - left instead of right - left + 1 (inclusive range)

**Brute force structure (for linked lists)**
- Initialize left = 0, seen = set(), max_len = 0
- Loop right from 0 to end of string (expand pointer moves unconditionally)
- Inside the loop:
    Check if s[right] already in seen (duplicate detection)
    If yes: while loop shrinking left, removing s[left] from seen, until duplicate removed
    Add s[right] to seen (expand window)
    Update max_len = max(max_len, right - left + 1)
- Return max_len after outer loop completes

**Process lessons**
- Before coding, visually trace the window as a "flashlight beam"—simulate moving left/right edges manually
- Test with "pwwkew" specifically—it exposes the duplicate-handling bug where slicing approaches fail
- When stuck, ask: "What do I need to track? How do I grow? When do I shrink?"
- Sliding window requires nested loops: outer expands, inner shrinks on violation
- Don't overthink—this is just watching a moving boundary and remembering how big it ever got without repeats 