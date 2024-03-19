class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> temp(26);
        for(auto ch : s){
            temp[ch - 'a']++;
        }
        for(int i=0; i<s.size(); i++){
            if(temp[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};