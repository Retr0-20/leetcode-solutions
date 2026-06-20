class Solution {
    public boolean isValid(String s) {

        boolean truthCondition = false;

        if(s.contains("()")) {
            truthCondition = true;
            return truthCondition;
        } 
        if(s.contains("[]")) {
            truthCondition = true;
            return truthCondition;
        } 
        if(s.contains("{}")) {
            truthCondition = true;
            return truthCondition;
        }

        return truthCondition;
    }
}