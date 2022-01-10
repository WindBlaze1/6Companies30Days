class Solution{
    public:
    string colName (long long int n)
    {
        string s;
        int k;
        while(n>0){
            n--;
            char k = 'A' + n%26;
            s = k + s;
            n /= 26;
        }
        return s;
    }
};
