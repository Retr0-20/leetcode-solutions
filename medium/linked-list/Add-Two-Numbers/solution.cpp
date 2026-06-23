// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        // Pointers to traverse the input lists
        ListNode* currentl1 = l1;
        ListNode* currentl2 = l2;

        // DUMMY HEAD PATTERN:
        // We create a dummy node to simplify edge cases (like returning the head).
        // 'current' will always point to the last node in our result list as we build it.
        ListNode* dummy = new ListNode(0); 
        ListNode* current = dummy;         

        int carry = 0; // Initialize carry to 0. No overflow at the start.

        // Loop continues as long as there are digits left in EITHER list.
        // This handles lists of unequal length naturally.
        while (currentl1 != nullptr || currentl2 != nullptr) {
            
            // SAFELY GET VALUES:
            // If a list runs out (is nullptr), treat its value as 0.
            // This prevents null pointer dereference crashes.
            int val1 = (currentl1 != nullptr) ? currentl1->val : 0;
            int val2 = (currentl2 != nullptr) ? currentl2->val : 0;

            // CALCULATE SUM FOR THIS DIGIT:
            // (Current digit from list 1) + (Current digit from list 2) + (Carry from previous step)
            int total = val1 + val2 + carry;    

            // EXTRACT NEW DIGIT AND NEW CARRY:
            // The digit to store is the ones place (total % 10).
            // The carry is the tens place (total / 10), e.g., 15 -> carry 1.
            int digit = total % 10;
            carry = total / 10;

            // APPEND NODE TO RESULT LIST:
            // Create a new node with the calculated digit and link it after 'current'.
            current->next = new ListNode(digit);

            // MOVE THE RESULT POINTER FORWARD:
            // Now 'current' points to the newly added node so the next one goes after it.
            current = current->next;

            // SAFE POINTER ADVANCEMENT:
            // Only move forward if the current pointer is NOT null.
            // If it IS null, it stays null (treated as 0 in next iteration).
            if (currentl1 != nullptr) currentl1 = currentl1->next;
            if (currentl2 != nullptr) currentl2 = currentl2->next;
        }

        // FINAL CARRY CHECK:
        // After the loop, if both lists are empty but we still have a carry (e.g., 5+5=10),
        // we need to append one final node with that carry value.
        if (carry > 0) {
            current->next = new ListNode(carry);
        }

        // RETURN THE ACTUAL HEAD:
        // 'dummy' was just a placeholder. The real list starts at dummy->next.
        return dummy->next;
    }
};