class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int mount=0;
        int i=0;
        int n=arr.size();
        while(i<n)
        {
            int j=i+1,k=i;
            while(j<n && k<n && arr[j]>arr[k])
            {
                j++;
                k++;
            }
            if(k!=i)
            {
                int temp=k;
                while(j<n && k<n && arr[j]<arr[k])
                {
                    j++;
                    k++;
                }
                if(k!=temp)
                {
                    mount=max(mount,k-i+1);
                }
                
            }
            i++;
        }
        return mount;
    }
};
