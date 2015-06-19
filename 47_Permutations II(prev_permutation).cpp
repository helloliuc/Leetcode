class Solution {
public:
    template<typename BidirectionalIterator>
    bool my_prev_permutation(BidirectionalIterator first, BidirectionalIterator last) {
        if(last - first <= 1) return false;
        for(BidirectionalIterator i = last - 1; i > first; i--) {
            if(*(i - 1) > *i) {
                for(BidirectionalIterator j = last - 1; j >= i; j--) {
                    if(*(i - 1) > *j) {
                        iter_swap(i - 1, j);
                        reverse(i, last);
                        return true;
                    }
                }
            }
        }
        reverse(first, last);
        return false;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> >ans;
        sort(nums.begin(), nums.end(), greater<int>());
        do {
            ans.push_back(nums);
        } while(my_prev_permutation(nums.begin(), nums.end()));
        return ans;
    }
};
