class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        int i=0;
        stack<int>st;
        while(i<n){
            bool flag=true;
            if(asteroids[i]<0 && (st.empty() || st.top()<0)) {
                st.push(asteroids[i]);
                i++;
            }
            else if(asteroids[i]<0 && !st.empty()){
                while(!st.empty() && st.top()>0 && st.top()<abs(asteroids[i])) st.pop();
                if(!st.empty() && st.top()>0 && st.top() == abs(asteroids[i])){
                    st.pop();
                    flag=false;
                }
                if((st.empty() || st.top()<0) && flag) st.push(asteroids[i]);
                i++;
            }
            else{
                st.push(asteroids[i]);
                i++;
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
