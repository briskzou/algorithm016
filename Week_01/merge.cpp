
法1：类插入法

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       
	for(int i=0;i<n;i++){
		int val=nums2[i];
		int j=m-1;
		while(j>=0 && nums1[j]>val){
			nums1[j+1]=nums1[j];
			j--;
		}
		nums1[j+1]=val;
		m++;
	}
}

法2:双指针法——从
 void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int tail=m+n-1;
        m--;
        n--;
        while(m>=0&&n>=0){
            if(nums2[n]>nums1[m]){
                nums1[tail--]=nums2[n--];
                
            }
            else{
                nums1[tail--]=nums1[m--];
            }
        }
        while(n>=0)
        {
            nums1[tail--]=nums2[n--];
        }
        
        
    }