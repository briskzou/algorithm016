//˫ָ�뷨
int removeDuplicates(vector<int>& a) {
        
        int len=a.size();
        if(len==0) return 0;
        int i=0;
        int j=1;
        while (j<len)
        {
            if(a[j]!=a[i])
            {
                i++;                
                a[i]=a[j];             
              
            }
            j++;
        }
        return i+1;