#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

#define base 311
#define MOD 1e9 + 7


void RabinKapt(string pat, string str){
   int patLen = (int)pat.size();
   int strLen = (int)str.size();
   int i;
   long long hashP = 0;
   long long hashS = 0;
   long long POW = 1;
   bool ok = 0;
   for (i = 0; i < patLen - 1; i++){
       POW = (POW * base) % (long long)(MOD);
   }

   for (i = 0; i < patLen; i++){
       hashP = (hashP * base + pat[i]) % (long long)(MOD);
       hashS = (hashS * base + str[i]) % (long long)(MOD);
   }

   for (i = 0; i <= strLen - patLen; i++){
       if (hashP == hashS){
           cout << i << " ";
           ok = 1;
       }

       if (i < strLen - patLen){
           hashS = ((hashS - str[i]*POW) * base + str[i + patLen]) % (long long)(MOD);
       }
       if (hashS < 0)
           hashS = hashS + (long long)(MOD);
   }
   if(!ok){
       cout << "No matching\n";
   }
}

void KMP(string s, string t){
    s = " " + s;
    t = " " + t;
    bool ok = 0;
    int *pi = new int[(int)s.length()];
    pi[1] = 0;
    int j = 0;
    for(int i = 2; i < (int)s.length(); ++i){
        while(j > 0 && s[j + 1] != s[i])
            j = pi[j];
        if(s[j + 1] == s[i])
            j++;
        pi[i] = j;
    }
    j = 0;
    for(int i = 1; i < (int)t.length(); ++i){
        while(j > 0 && s[j + 1] != t[i])
            j = pi[j];
        if(s[j + 1] == t[i])
            j++;
        if(j == (int)s.length() - 1){
            ok = 1;
            cout << i - j << ' ';
            j = pi[j];
        }
    }
    if(!ok){
        cout << "No matching\n";
    }
}

int main(){
    
    string s = "aaa";
    string t = "aaaaa";
    cout << "Test with string sub: " << s << "\nstring pattern: " << t << '\n';
    cout << "Run KMP\n";
    KMP(s, t);
    cout << "\nRun Rabin Karp\n";
    RabinKapt(s, t);
    s = "ab";
    t = "ababadbcadacabdabba";
    cout << "\nTest with string sub: " << s << "\nstring pattern: " << t << '\n';
    cout << "Run KMP\n";
    KMP(s, t);
    cout << "\nRun Rabin Karp\n";
    RabinKapt(s, t);
    s = "az";
    t = "abcdefghijklmnopq";
    cout << "\nTest with string sub: " << s << "\nstring pattern: " << t << '\n';
    cout << "Run KMP\n";
    KMP(s, t);
    cout << "\nRun Rabin Karp\n";
    RabinKapt(s, t);

    return 0;
}
