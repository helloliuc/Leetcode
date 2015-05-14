class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& pre) {
        vector<int> ans;
        int numEdges = pre.size();
        vector<int> out[numCourses];
        int cnt[numCourses];
        memset(cnt, 0, sizeof(cnt));

        for(int i=0; i<numEdges; i++) {
            out[pre[i].second].push_back(pre[i].first);
            cnt[pre[i].first] ++;
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++) {
            if(cnt[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            ans.push_back(front);
            for(int i=0; i<out[front].size();i++) {
                cnt[out[front][i]]--;
                if(cnt[out[front][i]] == 0) {
                    q.push(out[front][i]);
                }
            }
        }
        if(ans.size() != numCourses) {
            return vector<int>();
        }
        else {
            return ans;
        }
    }
};
