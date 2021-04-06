#include <iostream>
using namespace std;

void getPolynomicals(int (&A)[10][2], char (&var)[10], int &sizeA){
  int i;

  cout << "Enter the number of terms in this polynomicals: ";
  cin >> sizeA;

  cout << "Enter the Coefficient, variable and exponent: " << endl;

  for(i = 0; i < sizeA; i++){

    cin >> A[i][0] >> var[i] >> A[i][1];

  }
}

void printing(int (&A)[10][2], char (&var)[10], int sizeA)
{
    for(int i = 0; i < sizeA; i++){
        if(i != (sizeA - 1))
        {
         
         cout << A[i][0] << var[i] << "^" << A[i][1]<<" + ";
        
        } else {
          
          cout << A[sizeA-1][0] << var[sizeA-1] << "^" << A[sizeA-1][1]<<endl;
        
        }

    }
}

int multiplyPolynomicals(int (&A)[10][2], int (&B)[10][2], int (&C)[10][3], char (&varA)[10], char (&varB)[10], char (&varC)[15][5], int sizeA, int sizeB){
  int i, j, numberOfTerm = 0 ;
  
   
   for(i = 0; i < sizeA; i++){
     for(j = 0; j < sizeB; j++){
      if(varA[i] == varB[j]){

        C[numberOfTerm][0] = A[i][0] * B[j][0];
        C[numberOfTerm][1] = A[i][1] + B[j][1];
        varC[numberOfTerm][0] = varA[i];

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

int main(){

int a[10][2], b[10][2], c[10][3], sizeA, sizeB, sizeC;
char varA[10], varB[10], varC[15][5];
int i, j, m = 1;

getPolynomicals(a, varA, sizeA);
cout << endl; 
printing(a, varA, sizeA);
cout << endl;

getPolynomicals(b, varB, sizeB);
cout << endl;
printing(b, varB, sizeB);
cout << endl;

sizeC = multiplyPolynomicals(a, b, c, varA, varB, varC, sizeA, sizeB);
    
    cout << "Multiplication of two polynomials" << endl;
    
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
        m++;
    }

  cout << endl;
  for(i = 0; i < sizeC; i++){
    for(j = 0; j < 2; j++){
      if(varC[i][j] == '\0'){
        break;  
      } else {
        cout << varC[i][j] <<" ";
      }
    }
  }
return 0;
}
