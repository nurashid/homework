#include <unordered_set>
vector<string> wordBreakHelperMemo(string input, unordered_set<string> dict, unordered_map<string, vector<string>> memo)
{
    if (memo.find(input) != memo.end())
        return memo[input];
    vector<string> result;
    if (dict.find(input) != dict.end())
        result.push_back(input);
    
    for (int l = 1; l <= input.length(); l++) {
        string word = input.substr(0,l);
        if (dict.find(word) != dict.end()) {
            string remaining = input.substr(l);
            vector<string> remainingResult = wordBreakHelperMemo(remaining, dict, memo);
            vector<string> prev;
            for (auto str : remainingResult)
                prev.push_back(word + " " + str);
            
            result.insert(result.end(), prev.begin(), prev.end());
        }
    }
    memo[input] = result;
    return memo[input];
}

vector < string > wordBreak(string strWord, vector < string > strDict) {
    unordered_set<string> d(strDict.begin(), strDict.end());
    vector<string> sentences, sofar;
    unordered_map<string, vector<string>> memo;
    sentences = wordBreakHelperMemo(strWord, d, memo);
    return sentences;
}
