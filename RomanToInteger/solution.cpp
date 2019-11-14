/*================================================================
*   Copyright (C) 2019 Sangfor Ltd. All rights reserved.
*   
*   @file:solution.cpp
*   @author: Sophistt
*   @date:2019-11-14 11:07
*   @description: 
*
================================================================*/


#include<iostream>
#include<map>
#include<string>

using namespace std;


class MapSolution {

private:
    map<char, int> m;

public:
    MapSolution() {
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
  }

    int romanToInt(string s) {
        int sum = 0;
        
        for (size_t i = 0; i < s.length(); i++) {
            
            if (m[s[i]] < m[s[i+1]]) {
                sum = sum + m[s[i+1]] - m[s[i]];
                i += 1;
            }
            else sum += m[s[i]];
        }
        
        return sum;
    }

};



class SwitchSolution {

public:
    int romanToInt(string s) {
        int ret = 0;
        int temp = 0;

        for(size_t i = 0; i < s.size(); i++) {
            char curr = s[i];
            int pos = 0;

            switch(curr) {
                case 'I': pos = 1; break;
                case 'V': pos = 5; break;
                case 'X': pos = 10; break;
                case 'L': pos = 50; break;
                case 'C': pos = 100; break;
                case 'D': pos = 500; break;
                case 'M': pos = 1000; break;
                default: return 0;
            }

            ret += pos;
            if (temp < pos) ret -= temp * 2;
            temp = pos;
        }
        return ret;
    }
};


int main() {
  
    MapSolution mapSolution;
    SwitchSolution switchSolution;
    string s = "MCMXCIV";
  
    // cout << switchSolution.romanToInt(s) << endl;
    cout << mapSolution.romanToInt(s) << endl;
    return 0;
}
