#include <iostream>
#include <cstdlib>
#include <utility>
#include <queue>
#include <bits/stdc++.h> 
#include <string>
using namespace std;

//#define MAX 20
/*
template <typename Key, typename E> 
class Dictionary {
  private:
    void operator = (const Dictionary&) {}
    Dictionary(const Dictionary&) {}
    
  public:
    //Default constructor
    Dictionary(){}

    //Base destructor
    virtual ~Dictionary(){}
    
    virtual void clear() = 0; //reinitialize dictrionary
    
    virtual void insert(const Key& k, const E& e) = 0;//insert a record
                                                //k: The key for the record being inserted.
                                                //e: The record being inserted.
    virtual E remove(const Key& k) = 0; //Remove and return a record
                                      //k: The key of the record to be removed.
                                      //Return: A maching record. If multiple records match
                                      //"k", remove an arbitrary one. Return NULL if no record with key "k" exists.
    virtual E removeAny() = 0; //Remove and return an arbitrary record from                                           dictionary.
                                //Return: The record removed, or NULL if none exists.
    virtual E find(const Key& k) const = 0;//Return: A record matching "k"                                                       (NULL if none exists).
                                          //If multiple records match, return an arbitrary one.
                                          //k: The key of the record to find

    virtual int size() = 0; //return the number of records in the dictionary
};
*/


template <typename Key, typename E>
class MyDict //: public Dictionary<Key, E>
{
    private:

        queue <pair<Key, E>> OriginalQueue;
        queue <pair<Key, E>> CopiedQueue;

    public:
        MyDict(){}
        ~MyDict(){}
        void clear();
        void insert(const Key& k, const E& e);
        E remove(const Key& k);
        E removeAny();
        E find(const Key& k);
        int size();
    
};

template<typename Key, typename E>
void MyDict<Key, E>::clear()
{
    queue <pair<Key, E>> newqueue1;
    queue <pair<Key, E>> newqueue2;

    OriginalQueue.swap(newqueue1);
    CopiedQueue.swap(newqueue2);
}

template<typename Key, typename E>
void MyDict<Key, E>::insert(const Key& k, const E& e)
{
    OriginalQueue.push(make_pair(k, e));
}

template<typename Key, typename E>
E MyDict<Key, E>::remove(const Key &k){
  if(OriginalQueue.empty()){ 
    cout << "Queue underflow!!!" << endl;
  } else {
    int length = OriginalQueue.size();
    int lengthCop = 0;
    for(int i = 0; i < length; ++i){
      if(OriginalQueue.front().first == k){
        OriginalQueue.pop();
        cout << "Delete completed!!!" << endl;
        
        for(int j = 0; j < length - lengthCop - 1; ++j){
          CopiedQueue.push(make_pair(OriginalQueue.front().first, OriginalQueue.front().second));
          
          OriginalQueue.pop();
        }

        OriginalQueue.swap(CopiedQueue);
        break;

      } else {
        CopiedQueue.push(make_pair(OriginalQueue.front().first, OriginalQueue.front().second));
        OriginalQueue.pop();
        lengthCop++;
      }
    }
  }
  return 0;
}

template<typename Key, typename E>
E MyDict<Key, E>::removeAny(){ 
  if(OriginalQueue.empty()){ 
    cout << "Queue underflow!!!" << endl;
  } else {
    int random = rand()%OriginalQueue.size();
    int lengthCop = 0;
    int length = OriginalQueue.size();
    
    for(int i = 0; i <= random; ++i){
      if(i != random){
      CopiedQueue.push(make_pair(OriginalQueue.front().first, OriginalQueue.front().second));
        
      OriginalQueue.pop();
      lengthCop++;
      } else {
        OriginalQueue.pop();

        for(int j = 0; j < length - lengthCop - 1; ++j){
          CopiedQueue.push(make_pair(OriginalQueue.front().first, OriginalQueue.front().second));
          
          OriginalQueue.pop();
        }

        OriginalQueue.swap(CopiedQueue);
        cout << "Delete completed!!!" << endl;
      }
    }
  }
  return 0;
}

template<typename Key, typename E>
E MyDict<Key, E>::find(const Key& k){
  if(OriginalQueue.empty()){
    cout << "Queue underflow!!!" << endl;
  } else {
    int lengthCop = 0;
    int length = OriginalQueue.size();
    
    for(int i = 0; i < length; ++i){
      if(OriginalQueue.front().first == k){
      
      cout << "This name is located in position number " << CopiedQueue.size() + 1 << endl;
      
      for(int i = 0; i < length - lengthCop; ++i){
        CopiedQueue.push(make_pair(OriginalQueue.front().first, OriginalQueue.front().second));
          
        OriginalQueue.pop();
      }
      
      OriginalQueue.swap(CopiedQueue);
      break;

      } else {

          CopiedQueue.push(make_pair(OriginalQueue.front().first, OriginalQueue.front().second));
          
          OriginalQueue.pop();
          lengthCop++;
        
      }
    }
  }
return 0;
}

template<typename Key, typename E>
int MyDict<Key, E>::size(){ 
  cout << "Size of original stack: " << OriginalQueue.size() << endl;
  return 0;
}

int main(){

  MyDict <string, int> test1; 
  test1.insert("sang", 19);
  test1.insert("nhu", 21);
  test1.insert("tuan", 19);
  test1.insert("hung", 20);

  test1.find("tuan");
  test1.size();

  test1.removeAny();
  test1.size();

  return 0;
}
