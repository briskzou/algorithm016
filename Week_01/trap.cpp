方法一：暴力法
int trap(vector<int>& height) {

   int vol=0;
   for(int i=1;i<height.size();i++)
   {          
	   int max_right=0;
	   int max_left=0;
	   for(int j=i;j>=0;j--)
	   {
		  if(height[j]>max_left)
			max_left=height[j];
	   }
	   for(int j=i;j<height.size();j++)
	   {
		   if(height[j]>max_right)
		   {
			   max_right=height[j];
		   }
	   }
	   vol+= min(max_left,max_right)-height[i];
   } 
   return vol;
}
复杂度分析：
时间复杂度：O(n^2)
空间复杂度：O(1)

 //法2：动态法
int trap(vector<int>& height) {         
		 
   int size=height.size();
   if(size==0) return 0;

   vector<int> max_left(size),max_right(size);
   
   max_left[0]=height[0];
   for(int i=1;i<size;i++)
   {          
	   max_left[i] = max(height[i],max_left[i-1]);
   } 

   max_right[size-1]=height[size-1];       
   for(int i=size-2; i>=0;i--)
   {
	   max_right[i] = max(height[i],max_right[i+1]);
   }

   int vol=0;
   for(int i=1;i<size-1;i++)
   {
	   vol+= min(max_left[i],max_right[i])-height[i];
   }
   return vol;
}

复杂度分析：
时间复杂度：O(n)。

存储最大高度数组，需要两次遍历，每次 O(n) 。
最终使用存储的数据更新\text{ans}ans ，O(n)。
空间复杂度：O(n)

使用了额外的 O(n)空间用来放置 left_max 和 right_max 数组

//法3：栈的应用
    int trap(vector<int>& height) {
                
        int vol=0;
        int cur=0;
        stack<int> wt;
        while(cur<height.size()){
            
            while(wt.size()>0 && height[cur]>height[wt.top()]){          
                
                int bottom=height[wt.top()];
                wt.pop();
                
                if(wt.empty())
                    break;

                int distance = cur-wt.top()-1;
                int high=min(height[wt.top()],height[cur])-bottom;
                vol+=high* distance;
            }

            wt.push(cur++);
        }
        
        return vol;
        
    }
	
时间复杂度：O(n)
单次遍历 O(n) ，每个条形块最多访问两次（由于栈的弹入和弹出），并且弹入和弹出栈都是 O(1)O(1) 的。

空间复杂度：O(n)。 

栈最多在阶梯型或平坦型条形块结构中占用 O(n)O(n) 的空间。
 //法4：双指针法
    int trap(vector<int>& height) {
        int left=0,right=height.size()-1;
        int max_left=0,max_right=0;
        int vol=0;
        while (left<right)
        {
            if(height[left]<height[right])
            {
                height[left]>= max_left ? max_left=height[left]:vol+=max_left-height[left];
                left++;
            }
            else
            {
                height[right]>=max_right? max_right=height[right]:vol+=max_right-height[right];
                right--;
            }
        }
        return vol;
    }
	
时间复杂度：O(n)
单次遍历的时间O(n)O(n)。
空间复杂度：O(1)
额外空间。left, right,left_max 和right_max 只需要常数的空间

