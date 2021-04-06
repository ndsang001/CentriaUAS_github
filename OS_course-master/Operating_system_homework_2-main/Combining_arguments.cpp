#include<iostream>
#include<stdio.h>
using namespace std; 
  
int main(int argc,char* argv[]) 
{ 
int i;
double a, b, c;
    
cout << "The program (function) name is: " << argv[0] << endl; 

if(argc < 3){ 
  cout << "Usage: " << argv[0] << " Number1 Number2" << endl; 
} else if( argc > 3){ 
  cout << "Usage: " << argv[0] << " Number1 Number2" << endl;
} else {
  sscanf(argv[1], "%lf", &a);
  sscanf(argv[2], "%lf", &b);

  c = a * b;

  cout << "The multiplication of " << a << " and " << b << " is " << c << endl;
  
} 
    return 0; 
}
