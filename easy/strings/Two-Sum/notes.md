**Two Sum — what tripped me up**

**Conceptual mistakes**

- I implemented `const vector x; const vector y;` when they were not needed. This is because I confused the indices `i` and `j` with being the numbers at position num[i] rather than just being a container for the actual values. The final solution included using the two int counters from the for loops.
- My initial thoughts led to a solution that checked ONLY in adjacent pairs, so positions num[i] and num[i + 1] rather than num[i] and num[j]. That misses most pairs that may give an answer. The solution was to each element `i` against every other element after `i`, known as `j`.

**C++ syntax I got wrong**

- I tried using `nums.length` to get the array size. This is because I had Java muscle memory bleeding into C++. The correct method in C++ is `nums.size()`.
- I used `cout` and `printf` to display the answer rather than returning it. This is because I confused printing to stdout with returning a value from the function. LeetCode's grader only checks what the function `return`s, so my prints were invisible to it. The final solution was to use `return {i, j};`, where the curly braces construct a `vector<int>` inline.
- I wrote `return 0;` at the end of my function. This is because I forgot the return type was `vector<int>`, not an integer, so returning 0 was a type mismatch the compiler rejected. The correct fallback is `return {};`, which returns an empty vector.
- I called `printf` with comma-separated arguments expecting it to print them in order. This is because I assumed it worked like `cout`, but `printf` requires format specifiers like `%d` for ints to know how to interpret each argument. Without them the output is garbage. For this problem I didn't need `printf` at all once I switched from printing to returning.
- I added `const` to variables I planned to modify later. This is because I didn't fully grasp that `const` locks a variable to its initial value and forbids any reassignment. The rule going forward is to only use `const` when I genuinely don't want a variable to change.

**Brute force structure**

- The outer loop runs `i` from 0 to `nums.size()`, walking through each position as the first element of the pair. The inner loop then runs `j` from `i + 1`, walking through every later position to test as the second element. I initially started my inner loop at `j = 0`. This is because I didn't think through that pairs (i, j) and (j, i) are the same pair, and that comparing an element to itself is pointless. The correct start is `j = i + 1`, which skips self-pairs and avoids checking each pair twice.
- I wrote `i++` inside my inner loop instead of `j++`. This is because of a typo when setting up the nested loops, but the consequence is severe. The inner loop's counter never advances, so the loop runs forever. The takeaway is to always check that each loop increments its own counter.
- I declared `int a = i;` and `int b = j;` inside my loops without ever using them. This is because they were leftovers from an earlier version of my code where I was confused about what `i` and `j` represented. The lesson is to delete dead code, unused variables add noise without doing anything useful.

**Process lessons**

- I skimmed past the constraints initially. This is because I didn't realise they were giving me critical information about what time complexity my solution needed to fit within. With `n ≤ 10^4`, an O(n²) brute force passes comfortably. With larger constraints like `n ≤ 10^5` or higher, I would have been forced to find an O(n) solution from the start. Reading the constraints first sets the bar I need to clear.
- I was tempted to skip the brute force and jump straight to an optimal solution. This is because the brute force felt too obvious. The discipline I'm building is to always write the brute force first, get a working passing solution, then optimise from a known-good starting point.
- Once the brute force was working, the next step was identifying the waste in it. For Two Sum the brute force scans the array looking for `target - nums[i]` over and over for every position. That repeated lookup is the waste, and replacing it with a hash map makes each lookup O(1) instead of O(n). That's how the solution drops from O(n²) to O(n).
- I leaned on `cout` and `printf` to confirm my answer was correct. This is because print debugging is genuinely useful while I'm developing, but I conflated my own visibility with the grader's. The grader only checks the return value, so even if my prints showed the right answer, the function returning `{}` was still a fail. Print to debug, but always make sure the function actually returns what's needed.