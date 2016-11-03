public class Solution {
  public List<Integer> findSubstring(String s, String[] words) {
    List<Integer> results = new ArrayList<Integer>();
    if (words.length == 0) return null;
    int sizePerWord = words[0].length(), total = (1 + words.length) * words.length / 2;
    HashMap<String, Integer> map = new HashMap<String, Integer>();
    for (int i = 0;i < words.length; i++) {
      if (map.containsKey(words[i])) {
        map.put(words[i], map.get(words[i]) + 1);
      } else {
        map.put(words[i], 1);
      }
    }

    for (int i = 0; i < s.length() && i + sizePerWord * words.length < s.length() + 1; i++) {
      int sum = 0;
      HashMap<String, Integer> tmpMap = new HashMap<String, Integer>();
      for (int j = 0; j < sizePerWord * words.length; j+=sizePerWord) {
        String str = s.substring(i+j,i+j+sizePerWord);
        if (map.containsKey(str)) {
          if (tmpMap.containsKey(str)) {
              if (tmpMap.get(str) == 0) break;
              tmpMap.put(str, tmpMap.get(str) - 1);
          } else {
              tmpMap.put(str, map.get(str) - 1);
          }
          sum++;
        } else {
          break;
        }
      }
      if (sum == words.length) {
          results.add(i);
      }
    }
    return results;
  }
}