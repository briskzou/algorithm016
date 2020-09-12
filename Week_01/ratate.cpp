法1：暴力法
void rotate(vector<int>& nums, int k) {
       
        while(k>0)
        {
            int i=nums.size()-1;
            int val=nums[i];

            while(i>=1){
                nums[i]=nums[i-1];
                i--;
            }
            nums[0]=val;
            k--;
        }
    }

时间复杂度：O(n*k)
空间复杂度：O(1)