class Solution {
 public:
  string lastSubstring(string s) {
    int i = 0;
    int j = 1;
    int k = 0;  

    while (j + k < s.length()) {
      if (s[i + k] == s[j + k]) {
        ++k;
      } else if (s[i + k] > s[j + k]) {
        j += k + 1;
        k = 0;
      } else {
        i = max(i + k + 1, j);
        j = i + 1;
        k = 0;
      }
    }

    return s.substr(i);
  }
};