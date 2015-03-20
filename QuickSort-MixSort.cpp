//	Anthony Worden
//	Homework #3
//	Sorting
//	3/19/15
///////////////////

#include<iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>    

using namespace std;

class SortClass	//Class used to sort a random vector list of integers.
{
public:
	//HeapSort vector
	void reheapDown(vector<int> &vec, int root, int bottom);
	void HeapSort(vector<int> &vec);
	
	void QuickSort(vector<int> &vec); //QuickSort vector

	void MixSort(vector<int> &vec, int &depth);
};


void SortClass::HeapSort(vector<int> &vec)
	//Create a heap
{
	 int index;

    // Convert the vector of values into a heap.
	 for (index = vec.size()/2 - 1; index >= 0; index--)
		 reheapDown(vec, index, vec.size()-1);

    // Sort the vector.
    for (index = vec.size()-1; index >=1; index--)
    {
		swap(vec[0], vec[index]);
		reheapDown(vec, 0, index-1);
    }
	
}

void SortClass::reheapDown(vector<int> &vec, int root, int bottom)
	//Post-Heap property is maintained aka reheapdown
{
	int maxChild;
	int rightChild;
	int leftChild;

	leftChild = 2*root+1;
	rightChild = 2*root +2;
	

	if(leftChild <= bottom)
	{
		if(leftChild == bottom)
			maxChild = leftChild;
		else
		{
			if (vec[leftChild] <= vec[rightChild])
				maxChild = rightChild;
			else
				maxChild = leftChild;
		}

		if(vec[root] < vec[maxChild])
		{
			swap(vec[root], vec[maxChild]);
			reheapDown(vec, maxChild, bottom);
		}
	}

}

void SortClass::QuickSort(vector<int> &vec)
  //create a sorted vector using the QuickSort alogrithm
{
	if (vec.size() > 1)
	{
		int pivot;
		vector<int> larger;
		vector<int> smaller;	//buckets
		vector<int> equal;

		pivot = (vec.front()+vec.back()) / 2; //Make pivot

		for(int i = 0; i < vec.size(); i++) //sort into buckets
		{
			if (vec[i] > pivot)
				larger.push_back(vec[i]);
			else if(vec[i] < pivot)
				smaller.push_back(vec[i]);
			else
				equal.push_back(vec[i]);
		}

		QuickSort(smaller);	//Recursively solve buckets
		QuickSort(larger);

		move(smaller.begin(), smaller.end(),vec.begin());
		move(equal.begin(), equal.end(),vec.begin()+smaller.size());	//cacatenate buckets
		move(larger.begin(), larger.end(),vec.end()-larger.size());
	}
	
}

void SortClass::MixSort(vector<int> &vec, int &depth)
	//Combination of QuickSort and HeapSort.
	//Start with QuickSort, after a certain depth of recursion is reached use HeapSort
{
	depth--; //Decrement depth.

	if (depth <= 0)
	{
		//cout << "Successful switched to HeapSort." << endl; //Visual check if HeapSort is used.
		HeapSort(vec);
	}
	else
		{
			if (vec.size() > 1)
			{
				int pivot;
				vector<int> larger;
				vector<int> smaller;	//buckets
				vector<int> equal;

				pivot = (vec.front()+vec.back()) / 2; //Make pivot

				for(int i = 0; i < vec.size(); i++) //sort into buckets
				{
					if (vec[i] > pivot)
						larger.push_back(vec[i]);
					else if(vec[i] < pivot)
						smaller.push_back(vec[i]);
					else
						equal.push_back(vec[i]);
				}

				MixSort(smaller, depth);	//Recursively solve buckets
				MixSort(larger, depth);

				move(smaller.begin(), smaller.end(),vec.begin());
				move(equal.begin(), equal.end(),vec.begin()+smaller.size());	//cacatenate buckets
				move(larger.begin(), larger.end(),vec.end()-larger.size());
			}
		}
}


/////////////////

int main()
//Tester function for the various sorts.
{
	SortClass x;
	vector<int> MyVector1; //vector for HeapSort
	vector<int> MyVector2; //vector for QuickSort
	vector<int> MyVector3; //vector for MixSort

	int depth; //depth of when MixSort starts using HeapSort

	srand (time(NULL));	//Seed random number generator in order to create lists of integers.
	
	
	

	cout << "TESTING DIFFERENT SORTING ALGORITHMS" << endl << endl;
	cout << "****************************************" << endl;

	/*	HEAP SORT
		DRIVER
	*/
	for (int i = 0; i < 10; i++)	//Create a random list of integers <100 for HeapSort
	{
		int x = rand() % 100;
		MyVector1.push_back(x);
	}

	MyVector1.push_back(MyVector1.front()); //gurantee at least one duplicate in the list

	cout << "Random list for heap:";
	for (vector<int>::iterator it = MyVector1.begin(); it != MyVector1.end(); ++it)
		cout << ' ' << *it;
	cout << endl << endl;

	x.HeapSort(MyVector1);	//Sort the vector using HeapSort

	cout << "HeapSort result:";
	for (vector<int>::iterator it = MyVector1.begin(); it != MyVector1.end(); ++it)
		cout << ' ' << *it;//output sorted vector
	cout << endl << endl;
	
	cout << "****************************************" << endl;



	/*	QUICK SORT
		DRIVER
	*/
	for (int i = 0; i < 10; i++)	//Create a random list of integers <100 for QuickSort
	{
		int x = rand() % 100;
		MyVector2.push_back(x);
	}
	MyVector2.push_back(MyVector2.front()); //gurantee at least one duplicate in the list

	cout << "Random list for QuickSort:";
	for (vector<int>::iterator it = MyVector2.begin(); it != MyVector2.end(); ++it)
		cout << ' ' << *it;
	cout << endl << endl;
	
	x.QuickSort(MyVector2);		//Sort the vector using QuickSort

	cout << "QuickSort Result:";
	for (vector<int>::iterator it = MyVector2.begin(); it != MyVector2.end(); ++it)
		cout << ' ' << *it;//output sorted vector
	cout << endl << endl;
	
	cout << "****************************************" << endl;



	/*	MIX SORT
		DRIVER
	*/
	for (int i = 0; i < 10; i++)	//Create a random list of integers <100 for MixSort
	{
		int x = rand() % 100;
		MyVector3.push_back(x);
	}
	MyVector3.push_back(MyVector3.front()); //gurantee at least one duplicate in the list

	cout << "Random list for MixSort:";
	for (vector<int>::iterator it = MyVector3.begin(); it != MyVector3.end(); ++it)
		cout << ' ' << *it;
	cout << endl << endl;

	depth = 5;	//change the value of depth to determine when MixSort starts using HeapSort

	 //OR INPUT OWN DEPTH.
	/*cout << "Input desired depth as an integer to determine when MixSort sorts using HeapSort" << endl;
		cin >> depth; 
	*/
	x.MixSort(MyVector3, depth);	//Sort the vectro using MixSort

	cout << "MixSort Result:";
	for (vector<int>::iterator it = MyVector3.begin(); it != MyVector3.end(); ++it)
		cout << ' ' << *it;	//output sorted vector
	cout << endl << endl;

	return 0;

}
