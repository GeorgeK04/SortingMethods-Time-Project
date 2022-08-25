#ifndef PINAKAS_H
#define PINAKAS_H

class Pinakas
{
	private:
		    int  *p;  
			int  n;     
	public:
	       void  setArraySize(int  n1); 
	       void  createArray(); 
	       void  printArray();
	       void  fillArrayRandom();  
	       void  fillArraySortedandRandom();
	       void  fillArrayASC();
	       void  fillArrayDESC();
	       void copyArray(Pinakas ant); 
		   void bubbleSort(); 
		   void selectSort();  
		   void insertSort();
		   void quickSort(int left,int right);
	       void  freeArrayMem(); 
	       
};

#endif
