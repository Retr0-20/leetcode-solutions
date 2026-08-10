DELETE p2
FROM Person p1
INNER JOIN Person p2 on p1.email = p2.email
WHERE p1.id < p2.id