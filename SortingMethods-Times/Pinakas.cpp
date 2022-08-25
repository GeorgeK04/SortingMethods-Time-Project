#include "Pinakas.h"
#include "RandMT.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <algorithm>   //bibliothiki gia thn 50% sorted 50% random
using namespace std;

void  Pinakas::setArraySize(int  n1) 
{
   n = n1; 	
}

void  Pinakas::createArray()
{
   p = new int[n];  	
}

void  Pinakas::freeArrayMem()
{
   delete []p;
} 

void Pinakas::copyArray(Pinakas ant)
{
    int i;
   for(i=0; i<n; i++) 
       ant.p[i] = p[i];	
}

void  Pinakas::printArray()
{
    unsigned long i;
    for(i=0; i<n; i++)
	{
        cout << p[i] << "   ";
    }
}


void  Pinakas::fillArrayRandom()  // 100% random
{
    RandMT myRandom;
    RandMT(time(NULL));
    unsigned long i;
    for(i=0;i<n;i++)
    {
        p[i]=myRandom();
    }

}

void  Pinakas::fillArraySortedandRandom()  // 50% sorted, 50% random
{
    sort(p,p+(n/2));	
}

void  Pinakas::fillArrayASC()  // sorted ASC
{
	int k,j,i,min;
	for (i=0; i<n-1; i++)
	  {
	  	k = i;
	  	min = p[i];
	  	  for(j = i+1; j<n; j++)
	  	  {
	  	    if(p[j] < min)
			  {
			  	k = j;
			  	min = p[j];
			  }	
		  }
		  p[k] = p[i];
		  p[i] = min;
	  }
}

void  Pinakas::fillArrayDESC()  // sorted DESC
{
    int k,j,i,max;
	for (i=0; i<n-1; i++)
	  {
	  	k = i;
	  	max = p[i];
	  	  for(j = i+1; j<n; j++)
	  	  {
	  	    if(p[j] > max)
			  {
			  	k = j;
			  	max = p[j];
			  }	
		  }
		  p[k] = p[i];
		  p[i] = max;
	  }	
}



//methodoi taxinomisis


void Pinakas::bubbleSort()   //bubble sort
{
	int i,j,temp;
	
	for(i=1; i<n; i++)       
	    for(j=n-1; j>=i; j--)             
		    if(p[j-1] > p[j])               
			  {                    
			     temp = p[j-1];      
				 p[j-1] = p[j];
				 p[j] = temp;     
			  } 
} 

void Pinakas::selectSort()    //select sort
{
    int i,j,k,min;	
	
	for(i=0; i<n-1; i++)       
	   {         
	      k = i;         
		  min = p[i];         
		  for(j=i+1; j<n; j++)            
		     {              
			    if(p[j] < min)                
				  {                  
				     k = j;                  
					 min = p[j];                
				  }            
			 }         
		   p[k] = p[i];         
		   p[i] = min;       
	   } 
} 

void Pinakas::insertSort()     //insert sort
{
	int i,j,x;
	for(i=1; i<n; i++) 
        {
          x = p[i];
          j = i-1;
        while( j>=0 && p[j]>x)
          {
            p[j+1] = p[j];
            j = j-1;
          }
             p[j+1] = x;
        } 
}


void Pinakas::quickSort(int left,int right)     //quick sort
{
	
        int i, j, mid, x, temp;
          if (left < right)
             {
                i = left;
                j = right;
                mid = (left+right)/2;
                x = p[mid];
                  while (i < j)
                   {
                     while (p[i] < x)
                       i++;
                       while (p[j] > x)
                         j--;
                           if(i < j)
                             {
                               if(p[i] == p[j])
                                 {
                                    if(i<mid)
                                       i++;
                                         if(j>mid)
                                            j--;
                                 }
                                    else
                                     {
                                       temp = p[i];
                                       p[i] = p[j];
                                       p[j] = temp;
                                     }
                             }
                   }
                 quickSort(left,j-1);
                 quickSort(j+1,right);
          }
}

