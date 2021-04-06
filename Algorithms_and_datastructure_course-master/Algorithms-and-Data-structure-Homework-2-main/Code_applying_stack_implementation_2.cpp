#include <iostream>
#include <string.h>
#include <stack>

using namespace std;

int main(){
int lengthOfString, i, j, count = 0;
char b, c;
char originalString[100];
stack <char> copiedString;
stack <char> copiedString2;

cout << "Enter a string to check \"Palindrome\": ";
cin.get(originalString, 100);

lengthOfString = strlen(originalString);

for(i = 0; i < lengthOfString; ++i){
  copiedString.push(originalString[i]);
}

j = 0;
for(i = lengthOfString - 1; i >= 0; --i){
  copiedString2.push(originalString[i]);
  j++;
}

while (!copiedString.empty()){
  if (copiedString.top() == copiedString2.top()){
    count++;
  } else {
    cout << "This string is not a \"Palindrome\"!";
    exit(0);
  }

  copiedString.pop();
  copiedString2.pop();
}

if(count == lengthOfString){
  cout << "This string is a \"Palindrome\"!";
}

  return 0;
}
