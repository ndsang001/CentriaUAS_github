#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

struct dataType{
  char name[20];
  int x;
  int y;
};

  int checkExist(int a, char name1[20], struct dataType *data1){
    int i;

    for(i = 0; i < a; i++){

      if(strcmp(data1[i].name, name1) == 0){
        return i;
      }

    }
  return -1;
  }

  int checkExist2(int a, int x1, int y1, struct dataType *data1){
    int i;

    for(i = 0; i < a; i++){
      if(data1[i].x == x1 && data1[i].y == y1){
        return i;
      }
    }
    return -1;
  }

  bool checkExisted(int x1, int y1, char name1[20], int a, struct dataType *data1){
    int i;

    for(i = 0; i < a; ++i){
    if(strcmp(data1[i].name, name1) == 0){
        
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

  void insertCityEnd(int *a, int x1, int y1, char name1[20], struct dataType *data1){
    int i = *a;

    if(checkExisted(x1, y1, name1, i, data1) == true){

      printf( "The name or the coordinates have been existed!!! \nPlease try again!!!");

    } else {
    
    strcpy(data1[i].name, name1);
    data1[i].x = x1;
    data1[i].y = y1;

    i++;
    *a = i;

    printf("The data have been saved!\n\n");
    }
  return;
  }

  void insertCityFront(int *a, int x1, int y1, char name1[20], struct dataType *data1){
    int j = *a;

    if(checkExisted(x1, y1, name1, j, data1) == true){

      printf( "The name or the coordinates have been existed!!! \nPlease try again!!!");

    } else {

    for(int i = j; i > 0 ;--i){

      data1[i] = data1[i-1];
    
    }

    j++;
    *a = j;

    strcpy(data1[0].name, name1);
    data1[0].x = x1;
    data1[0].y = y1;
    
    printf("The data have been saved!\n\n");
    }
  }

 void insertArbitrary(int *a, int pos, int x1, int y1, char name1[20], struct dataType *data1){
    int i = *a;

    if(isEmpty(i)){
      printf("This city list is empty!!!\n");
      printf("This city will be saved in the first place!!!\n");

      strcpy(data1[0].name, name1);
      data1[0].x = x1;
      data1[0].y = y1;
      i++;
      *a = i;
      
      printf("The data have been saved!\n\n");
    } else if(isFull(i) == true){

      printf("This city list is full!!!\n");
    
    } else{

    for(int j = i ; j > pos; --j){
      data1[j] = data1[j-1]; 
    }
    i++;
    *a = i;
    
    strcpy(data1[pos].name, name1);
    data1[pos].x = x1;
    data1[pos].y = y1;
    printf("The data have been saved!\n\n");
    }
  }

  void printCity(int a, struct dataType *data1){
    if(isEmpty(a) == true){

      printf("This city list is empty!!!\n");

    } else{
    
      for(int i = 0; i < a; ++i){
        printf("(%s x = %d y = %d)-->", data1[i].name, data1[i].x, data1[i].y);
      }
    }
  }

  void deleteCityByName(int *a, char name1[20], struct dataType *data1){
    int i = *a;

    if(isEmpty(i) == true){

      printf("This city list is empty!!!\n");

    } else if(checkExist(i, name1, data1) == -1){

      printf("This city name does not exist!!!\n");

    } else {
      int pos = checkExist(i, name1, data1);

      for(int j = pos; j < i; ++j){
        data1[j] = data1[j+1];
      }
      i--;
      *a = i;

      printf("This city name %s have been deleted!\n", name1);
    }
  }

  void deleteCityByCoordinates(int *a, int x1, int y1, struct dataType *data1){
    int i = *a;

    if(isEmpty(i) == true){

      printf("This city list is empty!!!\n");

    } else if(checkExist2(i, x1, y1, data1) == -1){

      printf("These coordinates do not exist!!!\n");

    } else{

      int pos = checkExist2(i, x1, y1, data1);

      for(int j = pos; j < i; ++j){
        data1[j] = data1[j+1];
      }
      i--;
      *a = i;

      printf("These coordinates (and city) %d and %d have been deleted!\n", x1, y1);
    }
  }

  void searchCityByName(int a, char name1[20], struct dataType *data1){

    if(isEmpty(a) == true){

      printf("This city list is empty!!!\n");

    } else if(checkExist(a, name1, data1) == -1){

      printf("This city name does not exist!!!\n");

    }else {
      int pos = checkExist(a, name1, data1);
      
      printf("This city %s is located in position %d\n", name1, pos + 1);
      printf("With the coordinates: x = %d and y = %d\n" , data1[pos].x, data1[pos].y);
    
    }
  }

   void searchCityByCoordinates(int a, int x1, int y1, struct dataType *data1){

    if(isEmpty(a) == true){

      printf("This city list is empty!!!\n");

    } else if(checkExist2(a, x1, y1, data1) == -1){

      printf("These coordinates do not exist!!!\n");

    }else {
      int pos = checkExist2(a, x1, y1, data1);

      printf("This city %s is located in position %d\n", data1[pos].name, pos + 1);
      printf("With the coordinates: x = %d and y = %d\n", data1[pos].x, data1[pos].y);

    }
  }

  void check(int a, int x1, int y1, int z, struct dataType *data1){

    if(isEmpty(a) == true){

      printf("This city list is empty!!!\n");

    } else {
      int b ,c ,d, e = 0;

      for(int i = 0; i < a; ++i){
        b = data1[i].x;
        c = data1[i].y;
        d = sqrt(pow((x1-b),2) + pow((y1-c),2));

        if(d == z){
          printf("This city is in the distance: %s\n", data1[i].name);
          e++;
        }
      }

      if(e == 0){
        printf("There is no city in the distance\n");
      }
    }
  }


int main(){
  int size = 0, option, i;
  int x1, y1, pos , dis;
  char name1[20];
  struct dataType data1[100];
  FILE *fptr;
  
do{

    printf("\nMenu option (choose 0 for exit): \n");
    printf("1. Insert a city (at the end)\n");
    printf("2. Insert a city (at the front)\n");
    printf("3. Insert a city (at the arbitrary point)\n");
    printf("4. Print all city\n");
    printf("5. Delete a city by name\n");
    printf("6. Delete a city by coordinates\n");
    printf("7. Search a city by name\n");
    printf("8. Search a city by coordinates\n");
    printf("9. Search city by providing a distance and a specified point\n");
    printf("10. Save the data\n");
    printf("11. Clear screen!\n");
    scanf("%d", &option);

    switch(option){

      case 0:
      break;

      case 1:

      printf( "Insert at the end operation\n");
      printf("Enter the name and then coordinates: ");
      scanf("%s", name1);
      scanf("%d", &x1);
      scanf("%d", &y1);

      insertCityEnd(&size, x1, y1, name1, data1);
      break;

      case 2:

      printf( "Insert at the front operation\n");
      printf("Enter the name and then coordinates: ");
      scanf("%s", name1);
      scanf("%d", &x1);
      scanf("%d", &y1);

      insertCityFront(&size, x1, y1, name1, data1);
      break;

      case 3:

      printf( "Insert at an arbitrary point operation\n");
      printf("Enter the name and coordinates: ");
      scanf("%s", name1);
      scanf("%d", &x1);
      scanf("%d", &y1);
      scanf("%d", &pos);
    
      if(checkExisted(x1, y1, name1, size, data1) == false){

      insertArbitrary(&size, pos, x1, y1, name1, data1);
      
      } else {

      printf( "The name or the coordinates have been existed!!!\n");
      printf("Please try again!!!");
      
      }
      break;

      case 4:
    
      printCity(size, data1);
    
      printf("\n");
      break;

      case 5: 

      printf( "Delete city by name operation\n");
      printf("Enter city name expected to delete: ");
      scanf("%s", name1);

      deleteCityByName(&size, name1, data1);
      break;

      case 6:

      printf( "Delete city by coordinates operation\n");
      printf("Enter coordinates expected to delete: ");
      scanf("%d", &x1);
      scanf("%d", &y1);
      
      deleteCityByCoordinates(&size, x1, y1, data1);
      break;

      case 7:

      printf( "Search city by name operation\n");
      printf("Enter name of the city expected to search: ");
      scanf("%s", name1);
      
      searchCityByName(size, name1, data1);
      break;

      case 8:

      printf( "Search city by coordinates operation\n");
      printf("Enter coordinates of the city expected to search: ");
      scanf("%d", &x1);
      scanf("%d", &y1);
      
      searchCityByCoordinates(size, x1, y1, data1);
      break;

      case 9:

      printf( "Check with distance operation\n");
      printf("Enter the distance and a point (coordinates x and y): ");
      scanf("%d", &dis);
      scanf("%d", &x1);
      scanf("%d", &y1);
      
      check(size, x1, y1, dis, data1);
      break;

      case 10:
      if ((fptr = fopen("program.txt","w")) == NULL){
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
      }

      for(int k = 0; k < size; ++k){

        fprintf(fptr,"%s ", data1[k].name);
        fprintf(fptr,"%d ", data1[k].x);
        fprintf(fptr,"%d ", data1[k].y);

      }

      fclose(fptr); 

      printf("Data have been saved and changed in program.txt file!!!\n");
      break;

      case 11:
      system("clear");
      break;
    
      default:

      printf( "Please choose the proper option\n");

      break;
      }

  } while(option != 0);

return 0;
}
