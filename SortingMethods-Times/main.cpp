#include "RandMT.h"
#include "Pinakas.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <time.h>
using namespace std;

int main(int argc, char** argv)
 {

 	Pinakas aker, ant1,ant2,ant3,ant4;
 	int array,i,a;
 	unsigned long meg;
 	double sec1,sec2,sec3,sec4;
 	clock_t ct0,ct1;
 	RandMT myRandom;
	RandMT(time(NULL));
 	
 	
 	cout<< "Student"
	    <<endl
	    <<"======="
	    <<endl
	    <<"Name: KARAPILIAFIS GEORGIOS"
	    <<endl
	    <<"AEM: 4679"
	    <<endl
	    <<endl
	    <<"Computer characteristics"
	    <<endl
	    <<"========================"
	    <<endl
	    <<"CPU: Intel<R>"
	    <<endl
	    <<"     Core 2 Duo 2.66 Ghz"
	    <<endl
	    <<"RAM: 4 GB"
	    <<endl
	    <<"========================"
	    <<endl
	    <<"Array size? ";
	cin >>meg;
    aker.setArraySize(meg);
    aker.createArray();
	
	cout<<"Array types"
	    <<endl
	    <<"==========="
	    <<endl
	    <<"   1. Random 100%"
	    <<endl
	    <<"   2. Sorted 50%, Random 50%"
	    <<endl
	    <<"   3. Sorted ASC"
	    <<endl
	    <<"   4. Sorted DESC"
	    <<endl
	    <<"Choose array type:";
	cin >> array;
	a=0;
	
	while (a==0){
		if (array == 1) //100% random
		{
			a=1;
			aker.fillArrayRandom();
		}
		else if (array == 2) // 50% sorted, 50% random
		{
			a=1;
			aker.fillArraySortedandRandom();
		}
		else if (array == 3) // sorted ASC
		{
			a=1;
			aker.fillArrayASC();
		}
		else if (array == 4) // sorted DESC
		{
			a=1;
			aker.fillArrayDESC();
		}
		else
		{
			cout << "Please give a valid type of array : ";
			cin  >> array;
		}
	}
	
	ant1.setArraySize(meg);
	ant1.createArray();
	ant2.setArraySize(meg);
	ant2.createArray();
	ant3.setArraySize(meg);
	ant3.createArray();	
    ant4.setArraySize(meg);
	ant4.createArray();
	aker.copyArray(ant1); 
	aker.copyArray(ant2); 
	aker.copyArray(ant3); 
	aker.copyArray(ant4);   
	ofstream outfile("TIMES.txt");
	cout << "Sorting ==> ";
	
	cout << "Bubble... ";
	    ct0 = clock();
	    ant1.bubbleSort();
	    ct1 = clock();
	    sec1 = (double) (ct1-ct0)/CLOCKS_PER_SEC;
	
	cout << "Select... ";
	    ct0=clock();
	    ant2.selectSort();
	    ct1 = clock();
	    sec2 = (double) (ct1-ct0)/CLOCKS_PER_SEC;
			 
	cout << "Insert... ";
	    ct0=clock();
	    ant3.insertSort();
	    ct1 = clock();
	    sec3 = (double) (ct1-ct0)/CLOCKS_PER_SEC;
	
	cout << "Quick... ";
	    ct0=clock();
	    ant4.quickSort(0, meg-1);
	    ct1 = clock();
	    sec4 = (double) (ct1-ct0)/CLOCKS_PER_SEC;
			    
    cout  << "Finished!" << endl;
	if (array == 1)
	{
	    outfile << "ARRAY SIZE = " << meg << ",    ARRAY TYPE = Random 100%" << endl;
	}
    else if (array == 2)
	{
  	    outfile << "ARRAY SIZE = " << meg << ",    ARRAY TYPE = 50% Sorted, 50% Random" << endl;
	}
	else if (array == 3)
	{
	    outfile << "ARRAY SIZE = " << meg << ",    ARRAY TYPE = Sorted ASC" << endl;
	}
	else if (array == 4)
	{
	    outfile << "ARRAY SIZE = " << meg << ",    ARRAY TYPE = Sorted DESC" << endl;
	}
	
	outfile << "         EXECUTION TMES (seconds)" << endl;
	outfile << "BubbleSort SelectSort InsertSort QuickSort" << endl;
	outfile << "========== ========== ========== =========" << endl;
	outfile << fixed << setprecision(3) 
	        << "     " 
			<< sec1 
			<< "      "  
			<< sec2 
			<< "      " 
			<< sec3 
			<< "     " 
			<< sec4 
			<< endl;
	outfile.close();	
	
    aker.freeArrayMem();   //apodesmefsi mnimis
	ant1.freeArrayMem(); 
	ant2.freeArrayMem();
	ant3.freeArrayMem();
	ant4.freeArrayMem();	
 	
	return 0;
}
