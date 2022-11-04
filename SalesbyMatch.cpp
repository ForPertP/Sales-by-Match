#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'sockMerchant' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY ar
 */

int sockMerchant(int n, vector<int> ar)
{
    int result = 0;
    std::set<int> s;

    for_each(ar.cbegin(), ar.cend(),
        [&](int n)
        {
            std::pair<std::set<int>::iterator, bool> ret;
            ret = s.insert(n);
            if (ret.second == false)
            {
                s.erase(ret.first);
                result++;
            }
        }
    );

    return result;
}


int sockMerchant1(int n, vector<int> ar)
{
    int result = 0;
    std::map<int, int> m;
    
    for_each (ar.cbegin(), ar.cend(),
        [&](int n)
        {
            std::pair<std::map<int,int>::iterator,bool> ret;
            ret = m.insert(std::pair<int,int>(n, 1));
            if (ret.second == false)
            {
                ret.first->second++;
            }
        }
    );
    
    for_each( m.cbegin(), m.cend(),
        [&result](auto n)
        {
            result += n.second / 2;      
        }
    );
    
    return result;
}


int sockMerchant2(int n, vector<int> ar)
{
    std::sort(ar.begin(), ar.end());
    
    int result = 0;
    int number = ar[0];
    int mode = number;
    int count = 1;

    for (int i = 1; i < n; i++)
    {
        if (ar[i] == number)
        {
            ++count;
            if (count == 2)
            {
                result++;
                count = 0;
            }
        }
        else
        {
            count = 1;
            number = ar[i];
        }
    }

    return result;
}
