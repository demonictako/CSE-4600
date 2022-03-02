#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

int A[][3] = {{5, 2, 3}, {4, 5, 7}, {6, 3, 7}, {1, 3, 4}};
int B[][4] = {{4, 5, 6, 1}, {3, 2, 3, 5}, {2, 8, 7, 7}};
int C[4][4];

int row = 0;

void * mult(void *arg)
{
	int i = row++;
	for (int j = 0; j < 4; j++)
      for (int k = 0; k < 4; k++)
        C[i][j] += A[i][k] * B[k][j]; 	
        
    return NULL;
}

int main()
{
	int* matrix;
	pthread_t tids[4];
	
	for (int i = 0; i < 4; i++) 
    {
        pthread_create(&tids[i], NULL, mult, (void*)(matrix));
    }
    
    for (int i = 0; i < 4; i++)
    {
        pthread_join(tids[i], NULL);   
    }
    
	//Print A
    cout << endl << "A" << endl;
    for (int i = 0; i < 4; i++) 
    {
        for (int j = 0; j < 3; j++)
        { 
        	cout << A[i][j] << " ";
       	}
        cout << endl;
    } 
    //Priny B
    cout << endl << "B" << endl;
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 4; j++)
        {
            cout << B[i][j] << " ";    
        }   
        cout << endl;
 	}   
	//Prit C
    cout << endl << "A and B" << endl;
    for (int i = 0; i < 4; i++) 
    {
        for (int j = 0; j < 4; j++)
        {
            cout << C[i][j] << " ";      
        } 
        cout << endl;
    }
   	 return 0;
}


