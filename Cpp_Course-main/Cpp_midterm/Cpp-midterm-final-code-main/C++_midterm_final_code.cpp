#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

void getPolynomicals(int (&A)[10][2], char (&var)[10], int &sizeA){
  int i;

  cout << "Enter the number of terms in this polynomicals: ";
  cin >> sizeA;

  cout << "Enter the Coefficient, variable and exponent respectively: " << endl;

  for(i = 0; i < sizeA; i++){

    cin >> A[i][0] >> var[i] >> A[i][1];

  }
}

void printing(int (&A)[10][2], char (&var)[10], int sizeA)
{
  int i;

    for(i = 0; i < sizeA; i++){
        if(i != (sizeA - 1))
        {
         
         cout << A[i][0] << var[i] << "^" << A[i][1]<<" + ";
        
        } else {
          
          cout << A[sizeA-1][0] << var[sizeA-1] << "^" << A[sizeA-1][1]<<endl;
        
        }

    }
}

int multiplyPolynomicals(int (&A)[10][2], int (&B)[10][2], int (&C)[30][3], char (&varA)[10], char (&varB)[10], char (&varC)[30][5], int sizeA, int sizeB){
  int i, j, numberOfTerm = 0;
  
   for(i = 0; i < sizeA; i++){
     for(j = 0; j < sizeB; j++){
      if(varA[i] == varB[j]){

        C[numberOfTerm][0] = A[i][0] * B[j][0];
        C[numberOfTerm][1] = A[i][1] + B[j][1];
        C[numberOfTerm][2] = '\0';
        varC[numberOfTerm][0] = varA[i];
        varC[numberOfTerm][1] = '\0';

      } else {

        C[numberOfTerm][0] = A[i][0] * B[j][0];
        C[numberOfTerm][1] = A[i][1];
        C[numberOfTerm][2] = B[j][1];
        varC[numberOfTerm][0] = varA[i];
        varC[numberOfTerm][1] = varB[j];

      }   
      numberOfTerm++;
     }
   }

  
return numberOfTerm;
}

void deleteElement(char (&varC)[30][5], int &n, int position){
    // This array is empty!
    if(n <= 0){ 
        return;
    }
    // when pos <= 0, delete the front.
    if(position < 0){
        position = 0;
    }
    // when pos >= n, delete the end.
    else if(position >= n){
        position = n-1;
    }
    // When the element in the midle of array, starting pushing the back data in front. 
    for(int i = position; i < n - 1; i++){
        varC[i][0] = varC[i+1][0];
        varC[i][1] = varC[i+1][1];
    }
    // Reducing the number of element.
    --n;
}

void deleteElement2(int (&D)[30][3], int &n, int position){
    // This array is empty!
    if(n <= 0){
        return;
    }
    // when pos <= 0, delete the front.
    if(position < 0){
        position = 0;
    }
    // when pos >= n, delete the end.
    else if(position >= n){
        position = n-1;
    }
    // When the element in the midle of array, starting pushing the back data in front. 
    for(int i = position; i < n - 1; i++){
        D[i][0] = D[i+1][0];
        D[i][1] = D[i+1][1];
        D[i][2] = D[i+1][2];
    }
    // Reducing the number of element.
    --n;
}

int main(){

int a[10][2], b[10][2], c[30][3], sizeA, sizeB, sizeC, valueC[30][5], d[30];

char varA[10], varB[10], varC[30][5], check;

int i, j, result = 0, k;

cout << endl;

cout << "--Welcome to multiplication program!--" << endl << endl;

cout << "In this program, you can provide two polynomials for MULTIPLYING and EVALUATING!" << endl << endl;

cout << "***NOTICE***" << endl;

cout << "The maximum variable for each polynomial is 5 (10 for both)!" << endl;
cout << "Although you could provide more variable each polynomial," << endl;
cout << "this program does not make sure the product correctly!!!" << endl;

cout << "**-**" << endl;

cout << "If you want a term with negative sign," << endl; 
cout << "please enter and change the Coefficient or the value of variable to negative!!!" << endl;

cout << "****-****" << endl << endl;


getPolynomicals(a, varA, sizeA);
cout << endl; 
cout << "The fisrt polynomial: ";
printing(a, varA, sizeA);
cout << endl;

getPolynomicals(b, varB, sizeB);
cout << endl;
cout << "The second polynomial: ";
printing(b, varB, sizeB);
cout << endl;

sizeC = multiplyPolynomicals(a, b, c, varA, varB, varC, sizeA, sizeB);
    
    cout << "Multiplication of two polynomials: " << endl << endl;
    
    for(i=0 ; i < sizeC; i++){    
         
         if(c[i][2] == '\0'){
           if(i != (sizeC - 1)){
             
            cout << c[i][0] << varC[i][0] << "^" << c[i][1] << "  +  ";
           
           } else {
            
            cout << c[sizeC-1][0] << varC[i][0] << "^" << c[sizeC-1][1] << endl;

           }

         } else if(i != (sizeC - 1)) {

           cout << c[i][0] << varC[i][0] << "^" << c[i][1] << varC[i][1] << "^" << c[i][2] << "  +  ";

         } else {
          
          cout << c[sizeC-1][0] << varC[i][0] << "^" << c[sizeC-1][1] << varC[i][1] << "^" << c[sizeC-1][2] << endl;
         
        }
        
    }
  
cout << endl;

k = sizeC;
j = 0;
for(i = 0; i < sizeC; i++){
  for(j = i + 1; j < sizeC; j++){
        if(varC[i][0] == varC[j][0]){
            if(c[i][1] == c[j][1]){
                if(varC[i][1] == varC[j][1]){
                    if(c[i][2] == c[j][2]){
                    c[i][0] = c[i][0] + c[j][0];
                    deleteElement(varC, sizeC, j);
                    deleteElement2(c, k, j);
                    } else{
                        continue;
                    }
                } else{
                continue;
                }

            } else{
                continue;
            }
        } else if(varC[i][0] == varC[j][1]){
            if(c[i][1] == c[j][2]){
                if(varC[i][1] == varC[j][0]){
                    if(c[i][2] == c[j][1]){
                        c[i][0] = c[i][0] + c[j][0];
                    deleteElement(varC, sizeC, j);
                    deleteElement2(c, k, j);
                    } else{
                        continue;
                    }
                } else{
                    continue;
                }
            } else {
                continue;
            }
        } else {
            continue;
        }

}
}

for(i = 0; i < sizeC; i++){
  for(j = i + 1; j < sizeC; j++){
        if(varC[i][0] == varC[j][0]){
            if(c[i][1] == c[j][1]){
                if(varC[i][1] == varC[j][1]){
                    if(c[i][2] == c[j][2]){
                    c[i][0] = c[i][0] + c[j][0];
                    deleteElement(varC, sizeC, j);
                    deleteElement2(c, k, j);
                    } else{
                        continue;
                    }
                } else{
                continue;
                }

            } else{
                continue;
            }
        } else if(varC[i][0] == varC[j][1]){
            if(c[i][1] == c[j][2]){
                if(varC[i][1] == varC[j][0]){
                    if(c[i][2] == c[j][1]){
                        c[i][0] = c[i][0] + c[j][0];
                    deleteElement(varC, sizeC, j);
                    deleteElement2(c, k, j);
                    } else{
                        continue;
                    }
                } else{
                    continue;
                }
            } else {
                continue;
            }
        } else {
            continue;
        }

}
}

cout << "The result after simplifying: " << endl << endl;

for(i=0 ; i < sizeC; i++){    
         
         if(c[i][2] == '\0'){
           if(i != (sizeC - 1)){
             
            cout << c[i][0] << varC[i][0] << "^" << c[i][1] << "  +  ";
           
           } else {
            
            cout << c[sizeC-1][0] << varC[i][0] << "^" << c[sizeC-1][1] << endl;

           }

         } else if(i != (sizeC - 1)) {

           cout << c[i][0] << varC[i][0] << "^" << c[i][1] << varC[i][1] << "^" << c[i][2] << "  +  ";

         } else {
          
          cout << c[sizeC-1][0] << varC[i][0] << "^" << c[sizeC-1][1] << varC[i][1] << "^" << c[sizeC-1][2] << endl;
         
        }
        
    }

cout << endl;

cout << "Do you want to give the value(s) of variable(s) for evaluating this result?" << endl;
cout << "Enter Y (or y) for continuing or N (or n) for exiting the program: ";
cin >> check;

// check whether there are any problems with the alphabet
while(check != 'Y' && check != 'y' && check != 'N' && check != 'n'){

  cout << "\nYOUR INPUT IS WRONG! PLEASE TRY AGAIN!" << endl << endl;
  cout << "Do you want to give the value(s) of variable(s) for evaluating this result?" << endl;
  cout << "Enter Y (or y) for continuing or N (or n) for exiting the program: ";
  cin >> check;
}

cout << endl;

if(check == 'Y' || check == 'y' ) // user want to use the function
{
  for(i = 0; i < sizeC; i++){
    for(j = 0; j < 2; j++){
      if(varC[i][j] == '\0'){
        break;  
      } else {
        cout << "Enter value of " << varC[i][j] << " ";
        cin >> valueC[i][j];
      }
    }
  }

cout  << endl;
cout << "Change the variable(s) with the input value(s), we have: ";
for(i = 0 ; i < sizeC; i++){    
         
         if(c[i][2] == '\0'){
           if(i != (sizeC - 1)){
             
            cout << c[i][0] * (pow(valueC[i][0], c[i][1])) << " + ";
            d[i] =  c[i][0] * (pow(valueC[i][0], c[i][1]));
           
           } else {
            
            cout << c[sizeC-1][0] * pow(valueC[i][0], c[sizeC-1][1]);
            d[i] = c[sizeC-1][0] * pow(valueC[i][0], c[sizeC-1][1]);

           }

         } else if(i != (sizeC - 1)) {

            cout << c[i][0] * pow(valueC[i][0], c[i][1]) * pow(valueC[i][1], c[i][2]) << " + ";
            d[i] = c[i][0] * pow(valueC[i][0], c[i][1]) * pow(valueC[i][1], c[i][2]);

         } else {
          
          cout << c[sizeC-1][0] * pow(valueC[i][0], c[sizeC-1][1]) * pow(valueC[i][1], c[sizeC-1][2]);
          d[i] = c[sizeC-1][0] * pow(valueC[i][0], c[sizeC-1][1]) * pow(valueC[i][1], c[sizeC-1][2]);

        }
    result += d[i]; 
    }

cout << " = "<< result << endl << endl;

cout << "=> The result of the multiplication of two polynomials is " << result;
} else { // if user choose N or n, the app will stop 
  cout << "\n--Thank you for using my app!--" << endl; 
  cout << "\n--Have a nice day!!!--" << endl;
}  

return 0;
}
