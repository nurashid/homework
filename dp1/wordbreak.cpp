#include <unordered_set>
void wordBreakHelper(string input, int st, unordered_set<string> dict, vector<string> sofar, vector<string>&result)
{
    if (st == input.length()) {
        string sentence;
        for (auto word : sofar)
            sentence += word + " ";
        result.emplace_back(sentence);
        return;
    }
    for (int l = 1; l + st <= (input.length()); l++) {
        string word = input.substr(st, l);
        if (dict.find(word) != dict.end()){
            sofar.emplace_back(word);
            wordBreakHelper(input, st+l, dict, sofar, result);
            sofar.pop_back();
        }
    }
    return;
}

vector < string > wordBreak(string strWord, vector < string > strDict) {
    unordered_set<string> d(strDict.begin(), strDict.end());
    vector<string> sentences, sofar;
    wordBreakHelper(strWord, 0, d, sofar, sentences);
    return sentences;
}


