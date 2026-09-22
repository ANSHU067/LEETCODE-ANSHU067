class Solution {
public:
    int firstUniqChar(string s) {
        vector <int> freq(26,0);
        int n=s.size();
        for(int i=0;i<n;i++){
            int ch=s[i]-'a';
            freq[ch]++;   
        }
        for(int j=0;j<n;j++){
            int idx=s[j]-'a';
            if(freq[idx]==1){
                return j;
            }
        }
        return -1;
    }
};