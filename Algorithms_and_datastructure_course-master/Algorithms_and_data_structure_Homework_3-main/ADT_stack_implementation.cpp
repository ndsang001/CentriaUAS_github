#include <iostream>
#include <cstdlib>
#include <utility>
#include <stack>
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

        stack <pair<Key, E>> OriginalStack;
        stack <pair<Key, E>> CopiedStack;

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
    stack <pair<Key, E>> newstack1;
    stack <pair<Key, E>> newstack2;

    OriginalStack.swap(newstack1);
    CopiedStack.swap(newstack2);
}

template<typename Key, typename E>
void MyDict<Key, E>::insert(const Key& k, const E& e)
{
    OriginalStack.push(make_pair(k, e));
}

template<typename Key, typename E>
E MyDict<Key, E>::remove(const Key &k){
  if(OriginalStack.empty()){ 
    cout << "Stack underflow!!!" << endl;
  } else {
    int length = OriginalStack.size();
    int lengthCop = 0;
    for(int i = 0; i < length; ++i){
      if(OriginalStack.top().first == k){
        OriginalStack.pop();
        cout << "Delete completed!!!" << endl;
        
        for(int j = 0; j < lengthCop; ++j){
          OriginalStack.push(make_pair(CopiedStack.top().first, CopiedStack.top().second));
          
          CopiedStack.pop();
        }
        break;

      } else {
        CopiedStack.push(make_pair(OriginalStack.top().first, OriginalStack.top().second));
        OriginalStack.pop();
        lengthCop++;
      }
    }
  }
  return 0;
}

template<typename Key, typename E>
E MyDict<Key, E>::removeAny(){ 
  if(OriginalStack.empty()){ 
    cout << "Stack underflow!!!" << endl;
  } else {
    int random = rand()%OriginalStack.size();
    int lengthRan = OriginalStack.size() - random;
    int lengthCop = 0;
    
    for(int i = 0; i < lengthRan; ++i){
      if(i != lengthRan - 1){
      CopiedStack.push(make_pair(OriginalStack.top().first, OriginalStack.top().second));
        
      OriginalStack.pop();
      lengthCop++;
      } else {
        OriginalStack.pop();
        cout << "Delete completed!!!" << endl;
      }
    }

    for(int j = 0; j < lengthCop; ++j){
      OriginalStack.push(make_pair(CopiedStack.top().first, CopiedStack.top().second));
      
      CopiedStack.pop();
    }
  }
  return 0;
}

template<typename Key, typename E>
E MyDict<Key, E>::find(const Key& k){
  if(OriginalStack.empty()){
    cout << "Stack underflow!!!" << endl;
  } else {
    int length = OriginalStack.size();
    int lengthCop = 0;
    for(int i = 0; i < length; ++i){
      if(OriginalStack.top().first == k){
        cout << "This name is located in position number " << OriginalStack.size() << endl;
        
        for(int j = 0; j < lengthCop; ++j){
          OriginalStack.push(make_pair(CopiedStack.top().first, CopiedStack.top().second));
          CopiedStack.pop();
        }

        break;
      } else {
        CopiedStack.push(make_pair(OriginalStack.top().first, OriginalStack.top().second));
        OriginalStack.pop();
        lengthCop++;
      }
  }
  }
return 0;
}

template<typename Key, typename E>
int MyDict<Key, E>::size(){ 
  cout << "Size of original stack: " << OriginalStack.size() << endl;
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
