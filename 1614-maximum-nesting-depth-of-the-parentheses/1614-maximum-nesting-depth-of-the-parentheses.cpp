class Solution {
public:
    int maxDepth(string s) {
        int count=0;
        vector<char>arr;
        for(int i=0;i<s.length();i++){
            if (s[i] == '(' ){
                arr.push_back(s[i]);
            }
            else if( s[i] == ')'){
                arr.pop_back();
               
            }
            count =max(count, (int)arr.size()); 

        }
        return count;
        
    }
};