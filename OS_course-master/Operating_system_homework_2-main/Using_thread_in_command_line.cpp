
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <string>
#include <stdlib.h> 
using namespace std;

struct argumentsData{
  double a;
  double b;
  double c;
  double d;
};

void* div(void* arg) 
{ 
  struct argumentsData *arguments = (struct argumentsData*) arg;
  double input3 = arguments->c;
  double input4 = arguments->d;
  double div;

  div = input3 / input4;

  cout << "The divison is processing" << endl;
  cout << "The division of " << input3 << " by " << input4 << " is " << div << endl;

  // exit the current thread 
  pthread_exit(NULL); 
} 

void* multi(void* arg) 
{ 
  struct argumentsData *arguments = (struct argumentsData*) arg;

  double input1 = arguments->a;
  double input2 = arguments->b;
  double mul;

  mul = input1 * input2;
  
  cout << "The multiplication is processing" << endl;
  cout << "The multiplication of " << input1 << " and " << input2 << " is " << mul << endl;
  
  // exit the current thread 
  pthread_exit(NULL); 
} 
  
void threadMain(int argc, char* argv[]) 
{ 
  pthread_t threadMulti, threadDiv; 
    
  struct argumentsData arguments;

  arguments.a = stod(argv[1]);
  arguments.b = stod(argv[2]);
  arguments.c = stod(argv[3]);
  arguments.d = stod(argv[4]);

  // Creating a new thread 
  int t1 = pthread_create(&threadMulti, NULL, &multi, (void*)&arguments); 
  int t2 = pthread_create(&threadDiv, NULL, &div, (void*)&arguments); 
  
  if(t1 != 0){
    cout << "Thread creation is error!!!" << endl;
    exit(1);
  } else if(t2 != 0){
    cout << "Thread creation is error!!!" << endl;
    EXIT_FAILURE;
  }
  // Waiting for the created thread to terminate 
  pthread_join(threadMulti, NULL); 
  pthread_join(threadDiv, NULL); 
  
  pthread_exit(NULL); 
} 

int main(int argc, char* argv[]) 
{ 
  cout << "The program (function) name is: " << argv[0] << endl; 

  double mul, div, n, a, b, c, d; 
  if(argc < 5){ 
  cout << "Usage: " << argv[0] << " Number1 Number2" << endl; 
} else if( argc > 5){ 
  cout << "Usage: " << argv[0] << " Number1 Number2" << endl;
} else {
    threadMain(argc, argv); 
}
    return 0; 
} 

