**Conceptual mistakes**

 The biggest conceptual error was focusing on the integer sum rather than building the required data structure, leading to returning an int instead of a ListNode*. The fix is always returning dummy->next. Another major issue was using && in the loop condition, which stops prematurely if lists are different lengths; you must use || to process all digits. Finally, treating sum as a running total across iterations corrupted the math—each digit calculation needs a fresh, local total variable.

**C++ syntax I got wrong**

 In C++, declaring a pointer like ListNode* p without initialization points to garbage memory and causes crashes. You must explicitly allocate memory with new ListNode(0). Never access .val or .next without checking for nullptr first, as advancing unconditionally breaks when a list ends. Also, remember that variables like carry must be initialized to 0; otherwise, they hold random stack values. Finally, syntax like dummy->sum is invalid because sum isn't a node property; you must link nodes using current->next = new ListNode(digit).

**Brute force structure (for linked lists)**

 Always start with a Dummy Head pattern to simplify tracking the list's start, then return dummy->next. When accessing values, safely treat nullptr nodes as 0. The critical logic order is: calculate the total, extract the digit (% 10), update the carry (/ 10), create a new node, and finally advance pointers. Don't forget to check for a remaining carry > 0 after the loop finishes to handle cases like 5 + 5 = 10.

**Process lessons**

 Before coding, verify the function's return type to avoid compilation errors. Visualize the problem by drawing the linked lists and tracing pointer movement mentally. Test edge cases specifically, such as unequal list lengths and carry overflow at the very end. Build incrementally: get equal-length lists working first, then add complexity for unequal lengths, and finally handle the final carry. Remember your goal is to construct a data structure, not just compute a number.
