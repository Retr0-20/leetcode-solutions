# Conceptual mistakes
- Attempted to use GROUP BY email HAVING COUNT(email) > 1 inside a DELETE statement. MySQL's DELETE does not support GROUP BY in this manner. Removing duplicate rows requires joining the Person table to itself on matching emails and deleting the row with the larger id via DELETE p2 FROM Person p1 INNER JOIN Person p2 ON p1.email = p2.email WHERE p1.id < p2.id;.

# SQL syntax I got wrong
- Placed GROUP BY email HAVING COUNT(email) > 1 after the DELETE clause, producing a syntax error near line 4: "You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near 'GROUP BY email HAVING COUNT(email) > 1'".

# Process lessons
- Before writing a query, identify whether the task is a read (SELECT) or a modification (DELETE, UPDATE, INSERT) operation — this determines which SQL clauses are available. GROUP BY and HAVING are valid for SELECT but not for DELETE.