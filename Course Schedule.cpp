//CE
//AC
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& pre) {
        set<int> in[numCourses], out[numCourses];
        for(vector<pair<int, int>>::iterator it = pre.begin(); it != pre.end(); it++) {
            in[it->second].insert(it->first);
            out[it->first].insert(it->second);
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++) {
            if(in[i].size() == 0) {
                q.push(i);
            }
        }
        int count = 0;
        while(!q.empty()) {
            int num = q.front();    q.pop();
            count++;
            for(set<int>::iterator it = out[num].begin(); it != out[num].end(); it++) {
                in[*it].erase(num);
                if(in[*it].size() == 0) {
                    q.push(*it);
                }
            }
        }
        return count == numCourses;
    }
};
