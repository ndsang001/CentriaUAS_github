#include <iostream>
#include <stdlib.h>
#include <string>
#include <cmath>
using namespace std;

class Node{
  public:
   string name;
   double x, y;
   Node* next;

  Node(){
    name = {};
    x = 0;
    y = 0;
    next = NULL;
  }

  Node(double a, double b, string d){
    x = a;
    y = b;
    name = d;
  }
};

class cityList{
  public:
    Node* head;

    cityList(){
      head = NULL;
    }
    cityList(Node *n){
      head = n;
    }

    Node* cityExist(string d){ //check if city exists have the same name
      Node* temp = NULL;

      Node* ptr = head;

      while(ptr != NULL){
        if(ptr->name == d){

            temp = ptr;
        
        }
        ptr = ptr->next;

      }
    
      return temp;
    }

    Node* coordinatesExist(int a, int b){ //check if city's coordinates existed
      Node* temp2 = NULL;

      Node* ptr = head;

      while(ptr != NULL){
        if(ptr->x == a && ptr->y == b){

            temp2 = ptr;
        
        }
        ptr = ptr->next;

      }
    
      return temp2;
    }

    void insertEnd(Node *n){
      if(cityExist(n->name) != NULL){
        cout << "This city name already exists: " << n->name
        << " (Please insert new name with more detail!!!)" << endl;
      } else if(coordinatesExist(n->x, n->y) != NULL){
        cout << "These coordinates already exists: " << n->x << " and " << n->y << " (Please insert exact coordinate!!!)" << endl;
      }else {
        if(head == NULL){
          head = n;
          cout << "City has been added!" << endl;
        } else{
          Node *ptr = head;
          while(ptr->next != NULL){
            ptr = ptr->next;
          }
          ptr->next = n;
          cout << "City has been added!" << endl; 
        }
      }
    }

    void insertFront(Node *n){
      if(cityExist(n->name) != NULL){
        cout << "This city name already exists: " << n->name
        << " (Please insert new name with more detail!!!)" << endl;
      } else if(coordinatesExist(n->x, n->y) != NULL){
        cout << "These coordinates already exists: " << n->x << " and " << n->y << " (Please insert exact coordinate!!!)" << endl;
      }else{
        n->next = head;
        head = n;
        cout << "City has been added!" << endl;
      }
    }

    void insertArbitrary(string d, Node *n){
      Node* ptr = cityExist(d);
      if(ptr == NULL){
        cout << "There is no city name: " << d << endl;
      } else {
        if(cityExist(n->name) != NULL){
        cout << "This city name already exists: " << n->name
        << " (Please insert new name with more detail!!!)" << endl;
      } else if(coordinatesExist(n->x, n->y) != NULL){
        cout << "These coordinates already exists: " << n->x << " and " << n->y << " (Please insert exact coordinate!!!)" << endl;
      }else {
          n->next = ptr->next;
          ptr->next = n;
          cout << "City has been added!" << endl;
        }
      }
    }

    void deleteNode(string d){
      if(head == NULL){
        cout << "This city (linked) list is empty!!!" << endl;
      } else if(head != NULL){
        if(head->name == d){
          head = head->next;
          cout << "This city name is unlinked: " << d << endl;
        } else {
          Node* temp = NULL;
          Node* prevptr = head;
          Node* currentptr = head->next;
          while(currentptr != NULL){
            if(currentptr->name == d){
              temp = currentptr;
              currentptr = NULL;
            } else {
              prevptr = prevptr->next;
              currentptr = currentptr->next;
            }
          }
          if(temp != NULL){
            prevptr->next = temp->next;
            cout << "This city name is unlinked: " << d << endl;
          } else {
            cout << "There is no city name: " << d << endl;
          }
          
        }
      }
    }

    void printList(){
      if(head == NULL){
        cout << "This city (linked) list is empty!!!" << endl;
      } else {
        cout << endl << "The city (linked) List: " << endl;
        Node* temp = head;

        while(temp != NULL){
          cout << "(" << temp->name << " , " << temp->x << " , " << temp->y << ")-->";
          temp = temp->next; 
        }
      }
    }

    void search(string d){
      int i = 0;
      if(head == NULL){
        cout << "This city (linked) list is empty!!!" << endl;
      } else if(head != NULL){
        if(head->name == d){
          cout << "This city " << d << " has the coordinates x = " << head->x << " and y = " << head->y <<  endl;
        } else {
          Node* prevptr = head;
          Node* currentptr = head->next;

          while(currentptr != NULL){
            if(currentptr->name == d){
              cout << "This city " << d << " has the coordinates x = " << currentptr->x << " and y = " << currentptr->y <<  endl;
              i = 1;
              break;
            } else {
              prevptr = prevptr->next;
              currentptr = currentptr->next;
            }
          }
          if(i == 0 ){
            cout << "There is no city name: " << d << endl;
          }
          
        }
      }
    }

    void check(double a, double b, double c){
      double i, j;
      double z;

      if(head == NULL){
        cout << "This city (linked) list is empty!!!" << endl;
      } else if(head != NULL){
        
        Node *currentptr = head;
        
          while(currentptr != NULL){
            i = currentptr->x;
            j = currentptr->y;
            z = sqrt(pow((i-a),2) + pow((j-b),2));
            if(z == c){
            cout << "This city is in the distance: " << currentptr->name << endl;
            } 
              currentptr = currentptr->next;
          }
        
      }
    }
};

int main() {
cityList city;
  int option;
  double x1, a1, y2, b1;
  double c1;
  string name1, d1;

  do {
    cout << "\nPlease enter the operation number you want to perform (or Enter 0 to exit): " << endl;
    cout << "1. Insert at the end (Lined list)" << endl;
    cout << "2. Insert at the front (Lined list)" << endl;
    cout << "3. insert at a arbitrary point()" << endl;
    cout << "4. Delete a city (node)" << endl;
    cout << "5. Print all (nodes) Linked list" << endl;
    cout << "6. Search a city in this (linked) list" << endl;
    cout << "7. Search city by providing a distance and a specified point" << endl;
    cout << "8. Clear Screen" << endl << endl;
 
    cin >> option;
    Node * n1 = new Node();
 
    switch (option) {
    case 0:

      break;
    
    case 1:
    
      cout << "Insert at the end operation \nEnter \"name\" of city and the the coordinates (x and y):" << endl;
      cin >> name1;
      cin >> x1;
      cin >> y2;
      n1 -> name = name1;
      n1 -> x = x1;
      n1 -> y = y2;
      city.insertEnd(n1);
      //cout<<n1.key<<" = "<<n1.name<<endl;
      break;
 
    case 2:
    
      cout << "Insert at the front operation \nEnter \"name\" of city and the the coordinates (x and y):" << endl;
      cin >> name1;
      cin >> x1;
      cin >> y2;
      n1 -> name = name1;
      n1 -> x = x1;
      n1 -> y = y2;
      city.insertFront(n1);
      break;
 
    case 3:

      cout << "Insert at a arbitrary point operation \nEnter \"name\" of existing city after which you want to insert new city: " << endl;
      cin >> d1;
      cout << "Enter name and the coordinates x and y: " << endl;
      cin >> name1;
      cin >> x1;
      cin >> y2; 
      n1 -> name = name1;
      n1 -> x = x1;
      n1 -> y = y2;
      city.insertArbitrary(d1, n1);
      break;
 
    case 4:
 
      cout << "Delete a city and its coordinates operation \nEnter the name to be deleted: " << endl;
      cin >> d1;
      city.deleteNode(d1);
 
      break;

    case 5:

      city.printList();
 
      break;

    case 6:

      cout << "Search city by name operation \nEnter name of the city expected: " << endl;
      cin >> d1;

      city.search(d1);
      break;
    
    case 7:

    cout << "Check with distance operation \nEnter the distance and a point (coordinates x and y): " << endl;
    cin >> a1;
    cin >> b1;
    cin >> c1;
    city.check(a1, b1, c1);
    break;

    case 8:

    system("clear");
    break;

    default:
      cout << "Please enter only \"option\" numbers!!!" << endl;
    }
 
  } while (option != 0);

  
return 0;
}
