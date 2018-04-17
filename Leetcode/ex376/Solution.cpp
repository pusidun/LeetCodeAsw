class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() < 2)
            return nums.size();
        static const int BEGIN = 0;
        static const int UP = 1;
        static const int DOWN = 2;
        int STATE = BEGIN;
        int max_length = 1;
        for(int i = 1; i < nums.size(); i++){
            switch(STATE){
                case BEGIN:
                    if(nums[i]>nums[i-1]){
                        max_length++;
                        STATE = UP;
                    }
                    else if(nums[i]<nums[i-1]){
                        max_length++;
                        STATE = DOWN;
                    }
                break;
                case UP:
                    if(nums[i]<nums[i-1]){
                        STATE = DOWN;
                        max_length++;
                    }
                break;
                case DOWN:
                    if(nums[i]>nums[i-1]){
                        max_length++;
                        STATE = UP;
                    }
                break;
            }
        }
        return max_length;
    }
};