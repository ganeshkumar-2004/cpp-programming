// Only use recurion 
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class StrPermutation
{
public:
    void Permute(string ip, string op, vector<string> &v)
    {
        if (ip.size() == 0)
        {
            v.push_back(op);
            return;
        }
        unordered_set<char> mp;
        for (int i = 0; i < ip.size(); i++)
        {
            if (mp.find(ip[i]) == mp.end())
            {
                mp.insert(ip[i]);
            }
            string newIP = ip.substr(0, i) + ip.substr(i + 1);
            string newOP = op + ip[i];
            Permute(newIP, newOP, v);
        }
    }
};
int main(){
    string ip="ABC";
    vector<string> Result;
    StrPermutation Sp;
    Sp.Permute(ip,"",Result);
    cout << "Unique permutations are: " << endl;
    for (const string& perm : Result) {
        cout << perm << endl;
    }

    return 0;
}
