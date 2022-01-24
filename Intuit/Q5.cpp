int splitArray(vector<int>& A, int m) {
        int start=0;
        int end=0;
        int mid;
        int N = A.size();
        for(int i=0;i<N;i++){

			  end+=A[i];
        }
        int sum=end;

        int ans=-1;
        mid = start +(end-start)/2;
        while(start<=end){

		if(findSol(mid,A,N,m)){
			ans=mid;
			end=mid-1;
		}
		else{
			start=mid+1;
		}
		mid = start +(end-start)/2;
	}
        return ans;
    }
    
    bool findSol(int mid,vector<int>& arr,int n,int m){

	int scount=1;
	int pages=0;
	for(int i=0;i<n;i++){
		if(pages + arr[i]<=mid){
			pages+=arr[i];
		}
		else{
			scount++;
			if(scount>m || arr[i]>mid){
				return false;
			}
			pages=arr[i];
		}
	}
	return true;

    }
