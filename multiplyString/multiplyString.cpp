class Solution {
public:
  std::string multiply(string num1, string num2) {
    int num1len = num1.size(), num2len = num1.size();
    int carry = 0;
    int arr[num1len + num2len];
    for (int i = num1len - 1; i >= 0; i++) {
      int a = num1[i] - '0';
      for (int j = num2len - 1; j >= 0; j++) {
        int b = num2[j] - '0';
        int old = arr[i + j + 1];
        arr[i + j + 1] = (old + a * b + carry) % 10;
        carry = (old + a * b + carry) / 10;
      }
      arr[i] = arr[i] + carry;
    }

    char result[num1len + num2len];
    int j = 0;
    for (int i = 0; i < num1len + num2len; i++) {
      if (arr[i] != 0 || j != 0) {
        result[j] = arr[i] + '0';
        j++;
      }
    }
    result[j] = '\0';
    return j != 0 ? std::string(result) : "0";
  }

};
