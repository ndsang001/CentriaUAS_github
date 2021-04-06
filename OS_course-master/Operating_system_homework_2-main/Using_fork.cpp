#include <iostream> 
#include <unistd.h> 
#include <sys/wait.h>
using namespace std; 
  

int main(int argc, char* argv[]) 
{

cout << "The program (function) name is: " << argv[0] << endl; 

double mul, div, n, a, b, c, d; 
n = fork(); 

if(argc < 5){ 
  cout << "Usage: " << argv[0] << " Number1 Number2" << endl; 
} else if( argc > 5){ 
  cout << "Usage: " << argv[0] << " Number1 Number2" << endl;
} else {

  if (n == 0){ 
    sscanf(argv[3], "%lf", &c);
    sscanf(argv[4], "%lf", &d);
    div = c/d;     
    cout << "Child process \n"; 
    cout << "Child process: Division of " << c << " by " << d << " is " << div << endl; 
  
  } else if (n > 0) { 
  sscanf(argv[1], "%lf", &a);
  sscanf(argv[2], "%lf", &b);
  cout << "Parent process \n"; 
  mul = a * b;
  wait(NULL);
  cout << "Parent process: Multiplication of " << a << " and " << b << " is " << mul << endl; 
  } else {
  cout << "The function fork() failed!" << endl;
  return 1;
  }
}
return 0; 
} 
