#include <vector>
#include <string>

namespace std {
    using std::vector;
    using std::string;
}

class Solution {
public:
    std::vector<std::string> fizzBuzz(int n) {
        std::vector<std::string> myVector;
        int i = 1;

        while(i <= n) {

            if(i % 3 == 0 && i % 5 == 0) {
                myVector.insert(myVector.end(), "FizzBuzz");
            } else if(i % 5 == 0) {
                myVector.insert(myVector.end(), "Buzz");
            } else if(i % 3 == 0) {
                myVector.insert(myVector.end(), "Fizz");
            } else {
                myVector.insert(myVector.end(), std::to_string(i));
            }
            
            i++;
        }

        return myVector;    
    } 
};