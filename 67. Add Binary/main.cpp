//
//  main.cpp
//  67. Add Binary
//
//  Created by chenyufeng on 10/4/16.
//  Copyright © 2016 chenyufeng. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string addBinary(string a, string b)
{
    vector<char> A;
    vector<char> B;

    for (int i = 0; i < a.length(); i++)
    {
        A.push_back(a[i]);
    }

    for (int i = 0; i < b.length(); i++)
    {
        B.push_back(b[i]);
    }

    long lengthR = A.size() >= B.size() ? A.size() + 1 : B.size() + 1;
    vector<char> result(lengthR);
    // 初始化
    for (int i = 0; i < lengthR; i++)
    {
        result[i] = '0';
    }

    // 逆转后再进行加运算
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    for (int i = 0; i < lengthR - 1; i++)
    {
        if (A[i] == '1' && B[i] == '1')
        {
            result[i + 1] = '1';
        }
        else if (A[i] == '0' && B[i] == '0')
        {

        }
        else
        {
            if (result[i] == '1')
            {
                result[i] = '0';
                result[i + 1] = '1';
            }
            else
            {
                result[i] = '1';
            }
        }
    }

    reverse(result.begin(), result.end());
    vector<char>::iterator resultIte = result.begin();
    if (result[0] == '0')
    {
        result.erase(resultIte);
    }

    string resultStr;
    for (int i = 0; i < result.size(); i++)
    {
        resultStr += result[i];
    }

    return resultStr;
}

int main(int argc, const char * argv[])
{

    string ss = addBinary("0", "0");
    cout << ss;

    return 0;
}






