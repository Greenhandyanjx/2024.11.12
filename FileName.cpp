#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        string res;
        int n = s.length();
        for (int i = 0;i<n;i++) {
            if (isalpha(s[i]))res += s[i];
            else if (isdigit(s[i])) {
                int num = s[i] - '0';
                i++;
                string temp;
                int sum = 1;
                while (sum != 0) {
                    temp += s[i++];
                    if (s[i] == '[')sum++;
                    else if (s[i] == ']')sum--;
                }
                for (int j = 0; i < num; j++) {
                    s.insert(s.begin() + i + 1+num*j, temp.begin(), temp.end());
                    n += num;
                }
            }
        }
        return res;
    }
};
//int main() {
//    vector<int>b{ 255, 120, 2 };
//    bool a = validUtf8(b);
//}
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int flag1 = 128, flag2 = 64;
        int sum = 0;
        for (auto& i : data) {
            if (i & flag1) {
                i = i << 1;
                if ((i & flag1) && sum != 0)return false;
                else if (!(i & flag1) && sum == 0)return false;
                else if (!(i & flag1) && sum != 0)sum--;
                else {
                    while (i & flag1) {
                        sum++;
                        i = i << 1;
                    }
                    if (sum >= 4)return false;
                }
            }
            else {
                if (sum != 0)return false;
            }
        }
        return sum == 0;
    }
};