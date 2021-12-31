class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str2+str1 == str1+str2)
            return str1.substr(0,__gcd(str1.size(),str2.size()));
        return "";
    }
};
