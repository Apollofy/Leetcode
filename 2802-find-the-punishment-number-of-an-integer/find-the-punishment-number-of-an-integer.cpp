class Solution {
public:
    bool check(int i, int currsum , string s, int num){
        if(i==s.length()){
            return currsum==num;
        }

        if(currsum>num){
            return false;
        }

        bool possible = false;
        for(int j=i;j<s.length();j++){
            string sub = s.substr(i,j-i+1);
            int val = stoi(sub);
            possible = possible || check(j+1,currsum+val,s,num);

            if(possible==true)return true;
        }
        return false;
    }
    int punishmentNumber(int n) {
        int result = 0;
        for(int i=1;i<=n;i++){
            int sq = i*i;
            string s = to_string(sq);
            if(check(0,0,s,i)) result+=sq;
        }
        return result;
    }
};
