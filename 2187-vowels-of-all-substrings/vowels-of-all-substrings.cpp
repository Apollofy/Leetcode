class Solution {
public:
    long long countVowels(string word) {
        long long ans=0;
        int n=word.size();
        for(int i=0;i<n;i++){
            char c = word[i];
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
                ans+= (1LL*(i+1)*(n-i));
            }
        }
        return ans;
    }
};