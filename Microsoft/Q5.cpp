class Solution
{
   public:
   //Function to calculate the span of stockâ€™s price for all n days.
   vector <int> calculateSpan(int price[], int n)
   {
      // Your code here
      vector<int>ans(n,-1);
      stack<pair<int,int>>st;
      
      for(int i=0;i<n;i++){
          if(!st.empty() and st.top().first<=price[i]){
              while(!st.empty() and st.top().first<=price[i])
               st.pop();
               if(!st.empty()){
                   ans[i]=st.top().second;
                   
               }
          }
          else if(!st.empty() and st.top().first>price[i]){
              ans[i]=st.top().second;
              
          }
          
          st.push({price[i],i});
          ans[i]=i-ans[i];
      }
      
      return ans;
   }
};
