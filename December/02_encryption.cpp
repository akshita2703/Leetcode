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

Decrypt Message
An infamous gang of cyber criminals named “The Gray Cyber Mob”, which is behind many hacking attacks and drug trafficking, has recently become a target for the FBI. After intercepting some of their messages, which looked like complete nonsense, the agency learned that they indeed encrypt their messages, and studied their method of encryption.

Their messages consist of lowercase latin letters only, and every word is encrypted separately as follows:

Convert every letter to its ASCII value. Add 1 to the first letter, and then for every letter from the second one to the last one, add the value of the previous letter. Subtract 26 from every letter until it is in the range of lowercase letters a-z in ASCII. Convert the values back to letters.

For instance, to encrypt the word “crime”

Decrypted message:	c	r	i	m	e
Step 1:	99	114	105	109	101
Step 2:	100	214	319	428	529
Step 3:	100	110	111	116	113
Encrypted message:	d	n	o	t	q
The FBI needs an efficient method to decrypt messages. Write a function named decrypt(word) that receives a string that consists of small latin letters only, and returns the decrypted word.

Explain your solution and analyze its time and space complexities.

Examples:

input:  word = "dnotq"
output: "crime"

input:  word = "flgxswdliefy"
output: "encyclopedia"
Since the function should be used on messages with many words, make sure the function is as efficient as possible in both time and space. Explain the correctness of your function, and analyze its asymptotic runtime and space complexity.

Note: Most programing languages have built-in methods of converting letters to ASCII values and vica versa. You may search the internet for the appropriate method.

Constraints:

[time limit] 5000ms

[input] string word

The ASCII value of every char is in the range of lowercase letters a-z.
[output] string