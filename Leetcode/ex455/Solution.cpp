class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int child=0, cookie=0;
        while(true){
            if(child>g.size() || cookie>s.size())
                break;
            if(s[cookie] < g[child])
                cookie++;
            else{
                cookie++;
                child++;
            }
        }
        return child;
    }
};