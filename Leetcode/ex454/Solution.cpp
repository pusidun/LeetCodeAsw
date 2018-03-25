class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> m;
        int cnt = 0;
        
        for(int a: A)
            for(int b: B)
                m[a+b]++;
        
        for(int c: C)
            for(int d: D)
            {
                auto it = m.find(-c-d);
                if(it!=m.end())
                    cnt+=it->second;
            }
        return cnt;
    }
};