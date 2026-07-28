# What tripped me up

- Understanding how std::string::replace() actually works (replaces ranges, not patterns)
- Chaining multiple find() calls to handle multiple occurrences
- The infinite loop bug from finding the . inside [.] we just inserted
- Using indexOfChar != true instead of indexOfChar != string::npos

---

# Conceptual mistakes

- Thought replace(start, end, old_char, new_string) would find and replace all occurrences—it doesn't, it replaces a range
- Tried mixing begin()/end() iteration with find()—these are conflicting approaches
- Didn't anticipate that inserting [.] creates a new . that subsequent searches would find

---

# C++ syntax / logic mistakes

- Used address.find(".") with a string instead of '.' char
- Declared int indexOfChar instead of size_t
- Wrote indexOfChar != true instead of indexOfChar != string::npos
- Had return address; inside the loop, exiting prematurely
- Updated indexOfChar + 1 instead of indexOfChar + 3 after replacing—kept finding the . inside [.]

---

# Process lessons

- Manual tracing exposed the infinite loop immediately
- Testing "1.1.1.1" revealed the cascading [.] problem faster than reading code
- After inserting [.] (3 chars), jump forward by 3 positions, not 1