#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct dataType{
  string name;
  int x;
  int y;
};

class municipality{
  public:

  int checkExist(int a, string name1, dataType *data1){
    int i;
    for(i = 0; i < a; i++){
      if(data1[i].name == name1){
        return i;
      }
    }
  return -1;
  }

  int checkExist2(int a, int x1, int y1, dataType *data1){
    int i;
    for(i = 0; i < a; i++){
      if(data1[i].x == x1 && data1[i].y == y1){
        return i;
      }
    }
    return -1;
  }

  bool checkExisted(int x1, int y1, string name1, int a, dataType *data1){
    int i;
    for(i = 0; i < a; ++i){
    if(data1[i].name == name1){
        return true;
    } else if(data1[i].x == x1 && data1[i].y == y1){
        return true;
    }
    }
    return false;
  }

  bool isEmpty(int a){
    if( a == 0){
    return true;
    }
    return false;
  }

  bool isFull(int a){
    if(a == 100){
      return true;
    }
  return false;
  }

  void insertCityEnd(int &a, int x1, int y1, string name1, dataType &data1){
    data1.name = name1;
    data1.x = x1;
    data1.y = y1;
    cout << "The data have been saved!" << endl << endl;
    a++;
  }

  void insertCityFront(int &a, int x1, int y1, string name1, dataType *data1){
    for(int i = a; i > 0 ;--i){
      data1[i] = data1[i-1];
    }
    a++;

    data1[0].name = name1;
    data1[0].x = x1;
    data1[0].y = y1;
    
    cout << "The data have been saved!" << endl << endl;
  }

  void insertArbitrary(int &a, int pos, int x1, int y1, string name1, dataType *data1){
    if(isEmpty(a)){
      cout << "This city list is empty!!!" << endl;
      cout << "This city will be saved in the first place!!!" << endl;
      data1[0].name = name1;
      data1[0].x = x1;
      data1[0].y = y1;
      a++;
      cout << "The data have been saved!" << endl << endl;
    } else if(isFull(a)){
      cout << "This city list is full!!!" << endl;
    } else{
    for(int i = a; i > pos; --i){
      data1[i] = data1[i-1]; 
    }
    a++;
    data1[pos].name = name1;
    data1[pos].x = x1;
    data1[pos].y = y1;
    cout << "The data have been saved!" << endl << endl;
    }
  }

  void printCity(int a, dataType data1){
    cout << "(";
    cout << data1.name << "\t";
    cout << "x = " << data1.x;
    cout << "  y = " << data1.y;
    cout << ")-->";
  }

  void deleteCityByName(int &a, string name1, dataType *data1){
    if(isEmpty(a) == true){
      cout << "This city list is empty!!!" << endl;
    } else if(checkExist(a, name1, data1) == -1){
      cout << "This city name does not exist!!!" << endl;
    } else {
      int pos = checkExist(a, name1, data1);
      for(int i = pos; i < a; ++i){
        data1[i] = data1[i+1];
      }
      a--;
      cout << "This city name " << name1 << " have been deleted!" << endl;
    }
  }

  void deleteCityByCoordinates(int &a, int x1, int y1, dataType *data1){
    if(isEmpty(a) == true){
      cout << "This city list is empty!!!" << endl;
    } else if(checkExist2(a, x1, y1, data1) == -1){
      cout << "These coordinates do not exist!!!" << endl;
    } else{
      int pos = checkExist2(a, x1, y1, data1);
      for(int i = pos; i < a; ++i){
        data1[i] = data1[i+1];
      }
      a--;
      cout << "These coordinates (and city) " << x1 << " and " << y1 << " have been deleted!" << endl;
    }
  }

  void searchCityByName(int a, string name1, dataType *data1){
    if(isEmpty(a) == true){
      cout << "This city list is empty!!!" << endl;
    } else if(checkExist(a, name1, data1) == -1){
      cout << "This city name does not exist!!!" << endl;
    }else {
      int pos = checkExist(a, name1, data1);
      cout << " This city " << name1 << " is located in position " << pos + 1 << endl;
      cout << "With the coordinates: " << " x = " << data1[pos].x << " and y = " << data1[pos].y << endl;
    }
  }

   void searchCityByCoordinates(int a, int x1, int y1, dataType *data1){
    if(isEmpty(a) == true){
      cout << "This city list is empty!!!" << endl;
    } else if(checkExist2(a, x1, y1, data1) == -1){
      cout << "These coordinates do not exist!!!" << endl;
    }else {
      int pos = checkExist2(a, x1, y1, data1);
      cout << " This city " << data1[pos].name << " is located in position " << pos + 1 << endl;
      cout << "With the coordinates: " << " x = " << data1[pos].x << " and y = " << data1[pos].y << endl;
    }
  }

  void check(int a, int x1, int y1, int z, dataType *data1){
    if(isEmpty(a) == true){
      cout << "This city list is empty!!!" << endl;
    } else {
      int b ,c ,d, e = 0;
      for(int i = 0; i < a; ++i){
        b = data1[i].x;
        c = data1[i].y;
        d = sqrt(pow((x1-b),2) + pow((y1-c),2));
        if(d == z){
          cout << "This city is in the distance: " << data1[i].name << endl;
          e++;
        }
      }
      if(e == 0){
        cout << "There is no city in the distance" << endl;
      }
    }
  }
};

int main(){
  int size = 0, option, i;
  int x1, y1, pos , dis;
  string name1;
  struct dataType data1[100];
  municipality city; 

  
  do{

    cout << "\nMenu option: " << endl;
    cout << "1. Insert a city (at the end)" << endl;
    cout << "2. Insert a city (at the front)" << endl;
    cout << "3. Insert a city (at the arbitrary point)" << endl;
    cout << "4. Print all city" << endl;
    cout << "5. Delete a city by name" << endl;
    cout << "6. Delete a city by coordinates" << endl;
    cout << "7. Search a city by name" << endl;
    cout << "8. Search a city by coordinates" << endl;
    cout << "9. Search city by providing a distance and a specified point" << endl;
    cout << "10. Clear screen!" << endl << endl;
    cin >> option;

  switch(option){
    case 0:
    break;

    case 1:
    cout << "Insert at the end operation \nEnter the name and then coordinates: " << endl;
    cin >> name1;
    cin >> x1;
    cin >> y1;
    if(!city.checkExisted(x1, y1, name1, size, data1)){
    city.insertCityEnd(size, x1, y1, name1, data1[size]);
    } else {
    cout << "The name or the coordinates have been existed!!! \nPlease try again!!!" << endl;
    }
    break;

    case 2:
    cout << "Insert at the front operation \nEnter the name and then coordinates: " << endl;
    cin >> name1;
    cin >> x1;
    cin >> y1;
    if(!city.checkExisted(x1, y1, name1, size, data1)){
    city.insertCityFront(size, x1, y1, name1, data1);
    } else {
    cout << "The name or the coordinates have been existed!!! \nPlease try again!!!" << endl;
    }
    break;

    case 3:
    cout << "Insert at an arbitrary point operation \nEnter the name and coordinates: " << endl;
    cin >> name1;
    cin >> x1;
    cin >> y1;
    cin >> pos;
    if(!city.checkExisted(x1, y1, name1, size, data1)){
    city.insertArbitrary(size, pos, x1, y1, name1, data1);
    } else {
    cout << "The name or the coordinates have been existed!!! \nPlease try again!!!" << endl;
    }
    break;

    case 4:
    if(city.isEmpty(size)){
      cout << "This city list is empty!!!" << endl;
    }
    for(i = 0; i < size; ++i){
    city.printCity(i, data1[i]);
    }
    cout << endl;
    break;

    case 5:
    cout << "Delete city by name operation \nEnter city name expected to delete: " << endl;
    cin >> name1;
    city.deleteCityByName(size, name1, data1);
    break;
    
    case 6:
    cout << "Delete city by coordinates operation \nEnter coordinates expected to delete: " << endl;
    cin >> x1;
    cin >> y1;
    city.deleteCityByCoordinates(size, x1, y1, data1);
    break;

    case 7:
    cout << "Search city by name operation \nEnter name of the city expected to search: " << endl;
    cin >> name1;
    city.searchCityByName(size, name1, data1);
    break;

    case 8:
    cout << "Search city by coordinates operation \nEnter coordinates of the city expected to search: " << endl;
    cin >> x1;
    cin >> y1;
    city.searchCityByCoordinates(size, x1, y1, data1);
    break;

    case 9:
    cout << "Check with distance operation \nEnter the distance and a point (coordinates x and y): " << endl;
    cin >> dis;
    cin >> x1;
    cin >> y1;
    city.check(size, x1, y1, dis, data1);
    break;

    case 10:
    system("clear");
    break;
    
    default:
    cout << "Please choose the proper option" << endl << endl;
    break;
  }
  } while(option != 0);

return 0;
}
