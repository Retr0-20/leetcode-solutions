# Conceptual mistakes
- Compared i != val (index vs value) instead of nums[i] != val—comparing position to target value is meaningless
- Created newNums array instead of modifying nums in-place—problem explicitly requires in-place modification
- Count starts at 1 when it should start at 0—counts remaining elements, not iterations
- Allocated newNums inside the loop—wastes O(n²) memory on repeated allocations
- Never wrote results back to original nums array—return value must reflect first k elements of nums, not a separate array

# Java syntax I got wrong
- Post-increment j++ works correctly but placed allocation inside loop negates its efficiency benefit
- Didn't initialize array before loop—should allocate once: int[] result = new int[nums.length] outside the loop

# Two-pointer approach (correct solution)
- Initialize k = 0 as write pointer (tracks position for next valid element)
- Loop with read pointer i through entire array: for(int i = 0; i < nums.length; i++)
- Condition: if(nums[i] != val) to identify elements to keep
- Write in-place: nums[k++] = nums[i]—copies and increments write position simultaneously
- Return k as count of non-val elements now stored in nums[0...k-1]

# Process lessons
- Before coding, trace: [3,2,2,3] with val=3 → expect 2 and nums=[2,2,...]
- Problem states "modify nums in-place"—read constraints twice before choosing data structure
- Two-pointer pattern: one reads, one writes; never create auxiliary arrays unless required
- Debug by checking condition logic: i != val is always true except when index equals value—a logical trap
- Verify return value semantics: length of prefix, not total count variable