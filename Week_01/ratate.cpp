��1��������
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

ʱ�临�Ӷȣ�O(n*k)
�ռ临�Ӷȣ�O(1)