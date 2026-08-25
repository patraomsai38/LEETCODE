class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set <int> multiple;
        for(int i=0;i<nums.size();i++){
            multiple.insert(nums[i]);
        }
        for(int i=1;;i++){
            if(multiple.contains(k*i))
            {
                continue;
            }return k*i;
        }
        return -1;
    }
};