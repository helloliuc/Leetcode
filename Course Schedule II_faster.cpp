class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& pre) {
        vector<int> ans;
        set<int> out[numCourses], in[numCourses];

        for(int i=0; i<pre.size(); i++) {
            out[pre[i].second].insert(pre[i].first);
            in[pre[i].first].insert(pre[i].second);
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++) {
            if(in[i].size() == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int front = q.front();  q.pop();
            ans.push_back(front);
            for(set<int>::iterator it=out[front].begin(); it!=out[front].end(); it++) {
                in[*it].erase(front);
                if(in[*it].size() == 0) {
                    q.push(*it);
                }
            }
        }
        if(ans.size() != numCourses) {
            return vector<int>();
            //ans.resize(0);
        }
        return ans;
    }
};
