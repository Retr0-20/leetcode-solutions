# What tripped me up

- I initially tried to simulate the operation by subtracting `1` from values.
- I focused too much on changing individual array elements instead of looking at the total sum.
- I confused calculating the final divisible sum with calculating the number of operations needed.

---

# Conceptual mistakes

- I thought I needed to repeatedly modify `nums[i]`, but the problem only asks for the minimum number of operations.
- I missed the key idea that every operation decreases the total sum by exactly `1`.
- I wrote loops that tried to reduce `total` until it became divisible, but then returned the final total instead of the operation count.
- I counted the number of elements in the array at one point, which gave `nums.size()`, not the number of required operations.
- I created an infinite loop when checking `while(total % k)` without changing `total` inside the loop.

---

# C++ syntax / logic mistakes

- I used division logic at first instead of modulo. Divisibility should be checked with `%`, not `/`.
- I wrote `nums[i] - 1;` and `total - 1;`, but these do nothing unless the result is assigned back to a variable.
- I used a `while(total % k)` loop before fully recognising that `total % k` already gives the answer.
- I declared extra variables like `count` and `equalsZero` when they were not needed.
- I incremented `count` inside the sum loop, which counted array elements rather than operations.

---

# Process lessons

- The important step was reframing the problem from “change the array” to “change the total sum”.
- Since each operation decreases the sum by `1`, the number of operations needed is the remainder when `total` is divided by `k`.
- Modulo problems often become much simpler once I ask: “what does the remainder represent?”
- I should avoid simulating operations when a direct mathematical shortcut exists.
- The final solution is:
    - calculate the total sum
    - return `total % k`