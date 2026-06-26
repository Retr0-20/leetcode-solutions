## Conceptual mistakes ##

The main issue was breaking the “one input → one output” rule. Each index must produce exactly one string, but the implementation appends both a conditional result and the number, which duplicates entries and corrupts the sequence. The correct approach is to evaluate all conditions first, then commit a single final value per iteration.

Another mistake is treating conditions as independent actions instead of mutually exclusive outcomes. For this problem, “FizzBuzz” must override all other cases, so logic must be structured as a strict priority chain.

## C++ syntax I got wrong ##

vector::insert(myVector.end(), value) is unnecessary here and makes the logic harder to reason about. The correct tool is push_back, which clearly expresses single-value insertion.

The unconditional append of std::to_string(i) must not sit outside the decision structure. It must only execute in the else case.

Correct control flow must ensure only one branch runs per iteration using if / else if / else.

Brute force structure (for FizzBuzz-style iteration problems)

Loop from 1 to n
For each value of i, decide exactly one output:
if divisible by 3 and 5 → "FizzBuzz"
else if divisible by 3 → "Fizz"
else if divisible by 5 → "Buzz"
else → convert i to string
Append that single result to the vector
Continue until loop ends

Invariant:
Each iteration produces exactly one element in the result list.

## Process lessons ##

Always define the output constraint before coding:
“One loop iteration = one output element.”

Use that as a structural guardrail while implementing.

When debugging, compare expected vector size to n. If it exceeds n, multiple outputs per iteration are being produced.

Think in terms of selection, not accumulation:
You are choosing one label per i, not stacking multiple results.