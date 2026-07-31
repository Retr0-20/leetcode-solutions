**Conceptual mistakes**
- Tried slicing sorted(s)[:len//2] instead of counting frequencies—the slice doesn't respect character pairing and puts singletons in the first half incorrectly
- Assumed palindrome means "sorted first half + mirrored second half" without considering that characters must pair evenly
- Forgot to check for odd-length strings needing a middle character at all
- Initially tried combining left + right by overwriting fullString instead of concatenating both sides

**C++ syntax I got wrong**
- Used fullString.join(list) backwards—should be ''.join(list) to create string from list
- Called reversed() without converting to list: ''.join(reversed(list)) works because join accepts iterables
- Initialized middle unconditionally before checking length % 2 == 1, wasting computation
- Tried accessing sorted_s before defining it, causing NameError—stored it once and reused

**Brute force structure (for linked lists)**
- Start by sorting all characters: sorted_s = sorted(s)
- Count frequencies: count = Counter(s)
- Build first_half by looping through sorted unique keys and adding count // 2 copies of each
- Find middle character if length is odd (character with odd count)
- Join first_half, add middle if applicable, mirror first_half for second half
- Return left + middle + right or left + right depending on parity

**Process lessons**

- Before coding, trace what the sorted array looks like vs what the output should be to catch the pairing bug
- Don't trust sorted()[:n] blindly—verify each character has a pair before including it in first_half
- When debugging TLE or Wrong Answer, manually trace "babab" or "racecar" where counts are uneven
- Use Counter early; don't waste time slicing when you already have frequency data
- Save sorted(s) once to avoid typing sorted(s) three times and making typos
