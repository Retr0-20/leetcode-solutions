**Conceptual mistakes**

- I thought DataFrame might be a database I needed to query. It's actually a pandas data structure, essentially a labelled in-memory table.
- Printed instead of returning, again. Same mistake as Two Sum. Default rule: always return unless explicitly debugging.
- Tried using `iloc[3]`, which returns only the single row at the index provided (a Series, not a DataFrame). The correct call was either `.head(3)` or `iloc[:3]` (slice notation).
- Wrapped the input in `pd.DataFrame(employees)` when it was already one. The function signature `employees: pd.DataFrame` told me the type. Read the signature before adding conversion.

**What I did:**

I looked at the pandas documentation, specifically relating to DataFrame, searching for methods that could perform the action I needed: returning rows up to an index. The LeetCode AI also nudged me toward `.head()` after I'd tried `iloc[3]` first. From there it was trial and error with the syntax until `.head()` worked.