## Conceptual mistakes

* I initially treated linked lists like arrays, expecting to access positions directly rather than moving node-by-node using pointers.
* I thought I needed to “get the head” of the list, when `list1` and `list2` already were the head pointers provided by LeetCode.
* I confused the node itself with the value stored inside the node. `list1` is a pointer to a node, while `list1->val` is just the integer value inside it.
* I compared `list1->next < list2->next`, which compared memory addresses rather than node values. The comparison needed to be between `list1->val` and `list2->val`.
* I thought writing `list1->next;` would move the pointer forward. It only accesses the pointer without changing anything. Actual movement requires assignment:

```cpp
list1 = list1->next;
```

* I misunderstood the role of the dummy node. Initially I reassigned the dummy pointer itself, when the dummy node should stay fixed as a permanent starting anchor for the merged list.
* I confused moving a pointer with changing the linked list structure. Writing:

```cpp
tail = list1;
```

only moves the pointer variable. It does not attach a node to the merged list. Actual attachment requires:

```cpp
tail->next = list1;
```

---

## What I did

I started by trying to think through the merge process manually using the visual examples from the problem statement. Once I understood that each node contains both a value and a pointer to the next node, the problem became about pointer movement rather than array indexing.

I gradually broke the problem into smaller steps:

* compare current node values
* attach the smaller node
* move the corresponding list pointer forward
* move the tail pointer forward
* repeat until one list ends

The major breakthrough was realising that linked list problems are mostly about manipulating pointers and chain structure rather than copying integer values around.
