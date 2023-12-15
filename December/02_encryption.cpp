#include <iostream>
#include <string>
#include <vector>
using namespace std;

string decrypt( const string& word ) 
{
  // your code goes here
  // am i audible?
  
  // 110 - 100
  // 10 + (x * 26)
  // 97 - 122
  // 88 + 26 = 114 = r
  
  // x > 
  // i = 111
  // 111 - 214 (99 + 114)
  // -103 + (x * 26)
  // 105
  
  // 116 - (99 + 114 + 105)
  // 
  
  // intialize vector containing ascii value of char
  //modify 0th pos with val-1;
  //ans[i]=ans[i]-(ans[i-1]...ans[0]+1)
  //ans[i]=ans[i]+x*26 range(97--122)
  //ascii -- char--string
  if(word.size()==0){
    return word;
  }
  
  vector<int> ans;
  for(int i =0;i<word.size();i++){
    ans.push_back(word[i]);
  }
int k =ans[0];
  for(int i =1;i<word.size();i++){
    
    ans[i] = ans[i]-(k);
    while(ans[i]<97){
      ans[i]=ans[i]+26;
      
    }
    k=k+ans[i];
  }
  ans[0]=ans[0]-1;
  string s;
  for(int i =0;i<word.size();i++){
    char ss ='a'+(ans[i]-97);
    s.push_back(ss);
  }
  return s;
  
}

int main() {
     string s = "dnotq";
    int l = s.length();
    cout << decrypt(s);
 
    return 0;

}