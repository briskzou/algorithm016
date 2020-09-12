//·¨1£ºµü´ú·¨

    vector<int> plusOne(vector<int>& digits) {
        int  plusIndex=digits.size()-1;
        
        while (plusIndex>-1){
            if(digits[plusIndex]<9){
                digits[plusIndex]+=1;
                return digits;
            }
            else{
                digits[plusIndex]=0;
                plusIndex-=1;
            }
        }
        auto it=digits.begin();
        digits.insert(it,1);
        return digits; 

    }