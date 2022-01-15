// { Driver Code Starts
//Initial Template for C



#include<stdio.h>

 // } Driver Code Ends
//User function Template for C


void rotate(vector<vector<int> >& matrix)
{
   for(auto &i: matrix)
   {
       reverse(i.begin(),i.end());
   }
   for(int i=0; i<matrix.size(); i++)
   {
       for(int j=i; j<matrix[i].size(); j++)
       {
           swap(matrix[i][j],matrix[j][i]);
       }
   }
}

// { Driver Code Starts.

int main()
{
    int t;
    scanf("%d",&t); 
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n][n];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                scanf("%d",&a[i][j]);
        }
        rotate(n,a);
        for (int i = 0; i < n; ++i)
        {
            for(int j=0; j<n; j++)
                printf("%d ",a[i][j]);
            printf("\n");
        }
    }
    return 0;
}

  // } Driver Code Ends
