class Solution {
public:
    long long getnum(string &s, vector<int> &charmp){
        //simple word to number conversion according to character map
        long long num = 0;
        for(auto ch:s){
            int n = charmp[ch - 'A'];
            num = num*10 + n;
        }
        return num;
    }
    bool solve(int ind, vector<char> &unique, vector<int> &charmp, vector<bool> &usednum, vector<string>& words,    string &result, set<char> &firstnum){
        if(ind >= unique.size()){
            long long res = getnum(result, charmp), sum = 0;
            for(auto &ch:words){
                long long num = getnum(ch, charmp);
                sum += num;
                if(sum > res)return false;
            }
            if(sum == res)return true;
            return false;
        }

        char ch = unique[ind];
        for(int digit=0; digit<=9; digit++){
            if(usednum[digit] == false){ //proccede on if the digit is unused
                if(digit==0 and firstnum.find(ch) != firstnum.end())continue;  
                usednum[digit] = true;
                charmp[ch - 'A'] = digit;
                if(solve(ind+1, unique, charmp, usednum, words, result, firstnum) == true)return true;
                charmp[ch - 'A'] = -1;
                usednum[digit] = false;
            }
        }
        return false;
    }
    bool isSolvable(vector<string>& words, string result) {
        vector<int> charmp(26, -2); //store character with value
        vector<bool> usednum(10, false); // track to check number used or not
        set<char> firstnum; //store frst character of word to avoid the leading zero for further calculation
        vector<char> unique; //store unique character

        for(auto word:words){
            if(word.size() > result.size()) return false; 
            if(word.size() > 1)firstnum.insert(word[0]); 
            for(auto &ch:word){
                if(charmp[ch-'A'] != -1){ 
                    unique.push_back(ch);
                    charmp[ch-'A'] = -1;
                }
            }
        }
        
        if(result.size() > 1)firstnum.insert(result[0]);
        for(auto ch:result){
            if(charmp[ch-'A'] != -1){ 
            unique.push_back(ch);
            charmp[ch-'A'] = -1;
            }
        }
        return solve(0, unique, charmp, usednum, words, result, firstnum);
    }
};