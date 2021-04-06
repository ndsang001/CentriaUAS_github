#include <iostream>
#include <pthread.h>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <string>
using namespace std;

  size_t sumOdd{0};
  size_t sumEven{0};
  size_t oddCount{0};
  size_t evenCount{0};
  size_t produceCount{0};
  const size_t randTime{10};
  queue <unsigned int> randValue; // To create a queue

  pthread_mutex_t mutex_lock; // Declaration of mutex 
  pthread_cond_t condition_produce_lock; // Declaration of thread condition variable production
  pthread_cond_t condition_consume_lock; // Declaration of thread condition variable consumption

  void* insertQueue(void*){ // The function to generate and insert value into queue
    
    srand(time(NULL)); // To initialize the random seed

    while(true){
      pthread_mutex_lock(&mutex_lock); // To lock the queue by mutex

      if(produceCount < randTime){
        int randNum = rand()%100 + 1;

        randValue.push(randNum); // To push the random number into queue

        cout << "Random number: " << randNum << " has been pushed!" << endl;

        produceCount++;

        pthread_cond_broadcast(&condition_produce_lock); // allowing threads to contend for varying resource
      
      } else if(produceCount == randTime){

        pthread_mutex_unlock(&mutex_lock); 
        return NULL; 

      } 
      else {

         cout << "--> The insert function is in wait...!" << endl;
         pthread_cond_wait(&condition_consume_lock, &mutex_lock); // To makes the current thread to block until the condition variable get signaled

      }
      
      pthread_mutex_unlock(&mutex_lock); // The mutex unlocks
    }

  pthread_exit(NULL);
  }

  void* addFunction(void*){ // The function to classify and add the values
    
    while(true){
      pthread_mutex_lock(&mutex_lock); // To lock the queue by mutex
      
      if(!randValue.empty()){
        int number = randValue.front();

        if(number%2 == 0){

          sumEven += number; 

          randValue.pop();

          pthread_cond_signal(&condition_consume_lock); // To notify and allow a waiting thread to continue the execution

          evenCount++;

        } else if(number%2 == 1){

          sumOdd += number; 

          randValue.pop();

          pthread_cond_signal(&condition_consume_lock); // To notify and allow a waiting thread to continue the execution 

          oddCount++;
        }

      } else if((evenCount + oddCount) == randTime){

          pthread_mutex_unlock(&mutex_lock); 
          return NULL; 

      } else {

        cout << "--> The add function is in wait...!" << endl;
        pthread_cond_wait(&condition_produce_lock, &mutex_lock);

      }

    pthread_mutex_unlock(&mutex_lock); // The mutex unlocks
    }


  pthread_exit(NULL);
  }

int main(int argc, char* argv[]){

pthread_t thread1;
pthread_t thread2;
pthread_t thread3;

int t1 = pthread_create(&thread1, NULL, insertQueue, NULL); // To create the thread1
int t2 = pthread_create(&thread2, NULL, addFunction, NULL); // To create the thread2
int t3 = pthread_create(&thread3, NULL, addFunction, NULL); // To create the thread3

if(t1 != 0){
    cout << "Thread creation is error!!!" << endl;
    exit(1);
  } else if(t2 != 0){
    cout << "Thread creation is error!!!" << endl;
    EXIT_FAILURE;
  } else if(t3 != 0){
    cout << "Thread creation is error!!!" << endl;
    EXIT_FAILURE;
  }

pthread_join(thread1, NULL);
pthread_join(thread2, NULL);
pthread_join(thread3, NULL);

cout << "The sum of even number will be equal: " << sumEven << endl;
cout << "The sum of odd number will be equal: " << sumOdd << endl;

return 0;
}
