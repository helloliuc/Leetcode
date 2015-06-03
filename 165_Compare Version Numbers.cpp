class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i,j;
        for(i=0, j=0; i<version1.length() && j<version2.length();i++, j++) {
            int v1=0, v2=0;
            for(; version1[i] != '.' && version1[i] != '\0'; i++) {
                v1=v1*10+version1[i]-'0';
            }
            for(; version2[j] != '.' && version2[j] != '\0'; j++) {
                v2=v2*10+version2[j]-'0';
            }
            if(v1 < v2) return -1;
            else if(v1 > v2)    return 1;
        }
        if(i < version1.length()) {
            for(;i< version1.length(); i++) {
                if(version1[i] != '.' && version1[i] != '0') {
                    return 1;
                }
            }
        }
        else if(j < version2.length()) {
            for(;j<version2.length(); j++) {
                if(version2[j] != '.' && version2[j] != '0') {
                    return -1;
                }
            }
        }
        return 0;

    }
};
