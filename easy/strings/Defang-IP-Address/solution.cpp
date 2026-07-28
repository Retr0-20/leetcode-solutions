#include <string>

using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {

        size_t indexOfChar = address.find('.', 0);

        while (indexOfChar != string::npos) {
            address.replace(indexOfChar, 1, "[.]");
            indexOfChar = address.find('.', indexOfChar + 3);
        }

        return address;
    }
};