vector<vector<string>> groupAngagrams(vector<string> & strs) {
  unordered_map<string, multiset<string>> hashMap;
  for (string s: strs) {
    string t = s;
    sort(t.begin(), t.end());
    mp[t].insert(s);
  }
  vector<vector<string>> anagrams;
  for (auto m: mp) {
    vector<string> anagram(m.second.begin(), m.second.end());
    anagrams.push_back(anagram);
  }
  return anagrams;
}
