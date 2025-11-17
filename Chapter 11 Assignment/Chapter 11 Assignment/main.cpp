// Names: Hayden Martinez, David Derramadero, Allison Avila
// Date : 11/17/2025
// Chapter 11 - Assignments 

#include <iostream>
#include "input.h"
#include "MaxHeap.h"
#include "MinHeap.h"
#include <vector>
#include <algorithm>

using namespace std;

void Option1();
void Option1A();
void Option1B();
void Option2();
void Option3();
void print(const vector<int>& vec);
void displayHeap(const vector<int>& heap);
vector<int> intersectMaxHeap(MaxHeap<int> heap1, MaxHeap<int> heap2);
vector<int> intersectMinHeap(MinHeap<int> heap1, MinHeap<int> heap2);
vector<int> unionMaxHeap(MaxHeap<int> heap1, MaxHeap<int> heap2);
vector<int> unionMinHeap(MinHeap<int> heap1, MinHeap<int> heap2);

int main()
{
	do
	{
		system("cls");
		cout << "\n\tCMPR131 Chapter 11: Heaps (11/17/25)";
		cout << "\n\t" << string(80, char(205));
		cout << "\n\t\t1> Heap Using Vector";
		cout << "\n\t\t2> Union and Intersect of Heaps";
		cout << "\n\t\t3> Heap in C++ STL";
		cout << "\n\t" << string(80, char(196));
		cout << "\n\t\t0> Exit";
		cout << "\n\t" << string(80, char(205));
		switch (inputInteger("\n\t\tOption: ", 0, 3))
		{
		case 1: Option1(); break;
		case 2: Option2(); break;
		case 3: Option3(); break;
		case 0: exit(0);
		}
		cout << "\n\n"; system("pause");
	} while (true);

	return 0;
}

void Option1()
{
	do
	{
		system("cls");
		cout << "\n\t1> Heap Using Vector";
		cout << "\n\t" << string(80, char(205));
		cout << "\n\t\tA> Min Heap";
		cout << "\n\t\tB> Max Heap";
		cout << "\n\t" << string(80, char(196));
		cout << "\n\t\t0> Exit";
		cout << "\n\t" << string(80, char(205));

		switch (toupper(inputChar("\n\t\tOption: ", static_cast<string>("ab0"))))
		{
		case 'A': Option1A(); break;
		case 'B': Option1B(); break;
		case 0: return;
		}
		cout << "\n\n"; system("pause");
	} while (true);

	return;
}

void Option1A()
{
	MinHeap<int> numbers;

	do
	{
		system("cls");
		cout << "\n\tA> Min Heap";
		cout << "\n\t" << string(80, char(205));
		cout << "\n\t\t1. Size";
		cout << "\n\t\t2. Empty";
		cout << "\n\t\t3. Push";
		cout << "\n\t\t4. Front";
		cout << "\n\t\t5. Pop";
		cout << "\n\t\t6. Display";
		cout << "\n\t" << string(80, char(196));
		cout << "\n\t\t0> Exit";
		cout << "\n\t" << string(80, char(205));

		switch (inputInteger("\n\t\tOption: ", 0, 6))
		{
		case 1:
		{
			cout << "\n\t\tSize of the heap: " << numbers.size();
		}
		break;
		case 2:
		{
			if (numbers.empty() == true)
			{
				cout << "\n\t\tThe heap is empty.";
			}
			else
			{
				cout << "\n\t\tThe heap is not empty.";
			}
		}
		break;
		case 3:
		{
			int push = inputInteger("\n\t\tEnter an integer element to push onto the heap: ");

			numbers.push(push);
		}
		break;
		case 4:
		{
			cout << "\n\t\tThe first element of the heap: " << numbers.front();
		}
		break;
		case 5:
		{
			if (numbers.empty() == true)
			{
				cout << "ERROR: Push an integer element into the heap first.\n";
			}
			else
			{
				numbers.pop();
				cout << "\n\t\tThe first element of the heap has been removed.";
			}
		}
		break;
		case 6:
		{
			if (numbers.empty() == true)
			{
				cout << "ERROR: Push an integer element into the heap first.\n";
			}
			else
			{
				cout << "\n\t\t" << numbers;
			}
		}
		break;
		case 0: return;
		}
		cout << "\n\n"; system("pause");
	} while (true);

	return;
}

void Option1B()
{
	MaxHeap<int> numbers;

	do
	{
		system("cls");
		cout << "\n\tB> Max Heap";
		cout << "\n\t" << string(80, char(205));
		cout << "\n\t\t1. Size";
		cout << "\n\t\t2. Empty";
		cout << "\n\t\t3. Push";
		cout << "\n\t\t4. Front";
		cout << "\n\t\t5. Pop";
		cout << "\n\t\t6. Display";
		cout << "\n\t" << string(80, char(196));
		cout << "\n\t\t0> Exit";
		cout << "\n\t" << string(80, char(205));

		switch (inputInteger("\n\t\tOption: ", 0, 6))
		{
		case 1:
		{
			cout << "\n\t\tSize of the heap: " << numbers.size();
		}
		break;
		case 2:
		{
			if (numbers.empty() == true)
			{
				cout << "\n\t\tThe heap is empty.";
			}
			else
			{
				cout << "\n\t\tThe heap is not empty.";
			}
		}
		break;
		case 3:
		{
			int push = inputInteger("\n\t\tEnter an integer element to push onto the heap: ");

			numbers.push(push);
		}
		break;
		case 4:
		{
			cout << "\n\t\tThe first element of the heap: " << numbers.front();
		}
		break;
		case 5:
		{
			if (numbers.empty() == true)
			{
				cout << "ERROR: Push an integer element into the heap first.\n";
			}
			else
			{
				numbers.pop();
				cout << "\n\t\tThe first element of the heap has been removed.";
			}
		}
		break;
		case 6:
		{
			if (numbers.empty() == true)
			{
				cout << "ERROR: Push an integer element into the heap first.\n";
			}
			else
			{
				cout << "\n\t\t" << numbers;
			}
		}
		break;
		case '0': return;
		}
		cout << "\n\n"; system("pause");
	} while (true);

	return;
}
//Precondition: Receives input for two sets of MaxHeaps
//Postcondition:Returns the intersect heap of the two MaxHeaps
vector<int> intersectMaxHeap(MaxHeap<int> heap1, MaxHeap<int> heap2)
{
	vector<int> intersection;
	// Check each element in heap1 to see if it exists in heap2
	while (!heap1.empty())
	{
		int element = heap1.front();
		if (heap2.find(element))
		{
			intersection.push_back(element);
		}
		heap1.pop();
	}
	// Create a max heap from the intersection vector
	make_heap(intersection.begin(), intersection.end());
	return intersection;
}

//Precondition:  Receives input for two sets of MinHeaps
//Postcondition: Returns the intersect heap of the two MinHeaps
vector<int> intersectMinHeap(MinHeap<int> heap1, MinHeap<int> heap2)
{
	vector<int> intersection;
	// Check each element in heap1 to see if it exists in heap2
	while (!heap1.empty())
	{
		int element = heap1.front();
		if (heap2.find(element))
		{
			intersection.push_back(element);
		}
		heap1.pop();
	}
	// Create a min heap from the intersection vector
	make_heap(intersection.begin(), intersection.end(), greater<int>()); //greater<int>() extracts the smallest element first
	return intersection;
}

//Precondition: Receives input for two sets of MaxHeaps
//Postcondition: Returns the merged heap of the two MaxHeaps
vector<int> unionMaxHeap(MaxHeap<int> heap1, MaxHeap<int> heap2)
{
	vector<int> merged;
	// Add elements from the first heap
	while (!heap1.empty())
	{
		merged.push_back(heap1.front());
		heap1.pop();
	}
	// Add elements from the second heap
	while (!heap2.empty())
	{
		merged.push_back(heap2.front());
		heap2.pop();
	}
	// Create a max heap from the merged vector
	make_heap(merged.begin(), merged.end());
	return merged;
}

//Precondition: Receives input for two sets of MinHeaps
//Postcondition: Returns the merged heap of the two MinHeaps
vector<int> unionMinHeap(MinHeap<int> heap1, MinHeap<int> heap2)
{
	vector<int> merged;
	// Add elements from the first heap
	while (!heap1.empty())
	{
		merged.push_back(heap1.front());
		heap1.pop();
	}
	// Add elements from the second heap
	while (!heap2.empty())
	{
		merged.push_back(heap2.front());
		heap2.pop();
	}
	// Create a min heap from the merged vector
	make_heap(merged.begin(), merged.end(), greater<int>()); //greater<int>() extracts the smallest element first
	return merged;
}

//Precondition: Receives a heap input 
//Postcondition: Displays the contents of the inserted heap
void displayHeap(const vector<int>& heap)
{
	for (const int& val : heap)
	{
		cout << val << " ";
	}

	cout << "\n\t\t";
}

//Precondition: Utilizes MaxHeap.h and MinHeap.h
//Postcondition: Presents the Merged and Intersected Heaps of two min/max heaps
void Option2()
{
	MaxHeap<int> max1;
	max1.push(12);
	max1.push(5);
	max1.push(6);
	max1.push(2);
	MaxHeap<int> max2;
	max2.push(12);
	max2.push(9);
	max2.push(6);
	MinHeap<int> min1;
	min1.push(2);
	min1.push(5);
	min1.push(6);
	min1.push(12);
	MinHeap<int> min2;
	min2.push(12);
	min2.push(9);
	min2.push(6);
	vector<int> mergedMax;
	vector<int> intersectMax;
	vector<int> mergedMin;
	vector<int> intersectMin;

	do
	{
		system("cls");
		cout << "\n\t2> Union and intersect Heap";
		cout << "\n\t" << string(80, char(205));
		cout << "\n\t\tA> Union two max Heaps";
		cout << "\n\t\tB> Intersect two max Heaps";
		cout << "\n\t\tC> Union two min Heaps";
		cout << "\n\t\tD> Intersect two min Heaps";
		cout << "\n\t" << string(80, char(196));
		cout << "\n\t\t0> Exit";
		cout << "\n\t" << string(80, char(205));

		switch (toupper(inputChar("\n\t\tOption: ", static_cast<string>("abcd0"))))
		{
		case 'A':
			cout << "\n\t\tMax Heap 1 : " << max1;

			cout << "\n\n\t\tMax Heap 2 : " << max2;

			mergedMax = unionMaxHeap(max1, max2);

			cout << "\n\n\t\tMerged max heap: ";
			displayHeap(mergedMax);


			break;
		case 'B':
			cout << "\n\t\tMax Heap 1 : " << max1;

			cout << "\n\n\t\tMax Heap 2 : " << max2;

			intersectMax = intersectMaxHeap(max1, max2);

			cout << "\n\n\t\tIntersected max heap: ";
			displayHeap(intersectMax);
			break;
		case 'C':
			cout << "\n\t\t Min Heap 1: " << min1;
			cout << "\n\n\t\t Min Heap 2: " << min2;

			mergedMin = unionMinHeap(min1, min2);

			cout << "\n\n\t\tMerged min heap: ";
			displayHeap(mergedMin);


			break;
		case 'D':
			cout << "\n\t\t Min Heap 1: " << min1;
			cout << "\n\n\t\t Min Heap 2: " << min2;

			intersectMin = intersectMinHeap(min1, min2);

			cout << "\n\n\t\tIntersected min heap: ";
			displayHeap(intersectMin);
			break;
		case '0': return;
		}
		cout << "\n\n"; system("pause");
	} while (true);

	return;
}

//Precondition: Utilizes C++ STL heap functions
//postcondition: Demonstrates various heap operations using C++ STL
void Option3()
{
	vector<int>heaperJeepers;

	do
	{
		system("cls");
		cout << "\n\t3> Heap in C++ STL";
		cout << "\n\t" << string(80, char(205));
		cout << "\n\t\tA> create a dynamic array";
		cout << "\n\t\tB> push_back() an element";
		cout << "\n\t\tC> make_heap()";
		cout << "\n\t\tD> front()";
		cout << "\n\t\tE> push_heap()";
		cout << "\n\t\tF> pop_heap()";
		cout << "\n\t\tG> sort_heap()";
		cout << "\n\t\tH> is_heap()";
		cout << "\n\t\tI> is_heap_until()";
		cout << "\n\t\tJ> display";
		cout << "\n\t" << string(80, char(196));
		cout << "\n\t\t0> Exit";
		cout << "\n\t" << string(80, char(205));

		switch (toupper(inputChar("\n\t\tOption: ", static_cast<string>("abcdefghij0"))))
		{
		case 'A':
		{
			int size = inputInteger("\n\t\tEnter the size of the dynamic array: ");
			heaperJeepers.resize(size);

			for (int i = 0; i < heaperJeepers.size(); i++)
			{
				heaperJeepers[i] = rand() % 100 + 1;
			}

			cout << "\n\t\tDynamic array of size " << size << " created.";

		}break;
		case 'B':
		{
			int element = inputInteger("\n\t\tEnter an integer element to push_back() into the dynamic array: ");
			heaperJeepers.push_back(element);
			cout << "\n\t\tElement " << element << " pushed back into the dynamic array.";
		}break;
		case 'C':
		{
			if (!heaperJeepers.empty())
			{
				make_heap(heaperJeepers.begin(), heaperJeepers.end());
				cout << "\n\t\tThe dymaic array has been created into a heap ";
			}
			else
				cout << "\n\t\tThe dynamic array is empty :( fill it up";
		}break;
		case 'D':
		{
			if (heaperJeepers.empty())
				cout << "\n\t\tThe dynamic array is empty :( fill it up";
			else
				cout << "\n\t\tThe maximum element of heap: " << heaperJeepers.front();
		}break;
		case 'E':
		{
			if (!heaperJeepers.empty())
			{

				if (is_heap(heaperJeepers.begin(), heaperJeepers.end()))
				{
					int element = inputInteger("\n\t\tEnter an integer element to into the heap: ", true);
					heaperJeepers.push_back(element);
					push_heap(heaperJeepers.begin(), heaperJeepers.end());
					cout << "\n\t\tElement " << element << " pushed into the heap.";
				}
				else
					cout << "\n\t\tERROR: The dynamic array is not a heap. Please create a heap first.";
			}
			else
				cout << "\n\t\tThe dynamic array is empty :( fill it up";
		}break;
		case 'F':
		{
			if (!heaperJeepers.empty())
			{
				if (is_heap(heaperJeepers.begin(), heaperJeepers.end()))
				{
					cout << "\n\t\tCurrent heap: ";
					print(heaperJeepers);

					pop_heap(heaperJeepers.begin(), heaperJeepers.end());
					cout << "\n\t\tAfter calling pop_heap(): ";
					print(heaperJeepers);

					heaperJeepers.pop_back();
					cout << "\n\t\tRemoving the head element: ";
					print(heaperJeepers);
				}
				else
					cout << "\n\t\tERROR: The dynamic array is not a heap. Please create a heap first.";
			}
			else
				cout << "\n\t\tThe dynamic array is empty :( fill it up";
		}break;
		case 'G':
		{
			if (!heaperJeepers.empty())
			{
				
					cout << "\n\t\tBefore the sorted heap: ";
					print(heaperJeepers);

					sort_heap(heaperJeepers.begin(), heaperJeepers.end());
					cout << "\n\t\tSorted heap: ";
					print(heaperJeepers);

			}
			else
				cout << "\n\t\tThe dynamic array is empty :( fill it up";
		}break;
		case 'H':
		{
			if (!heaperJeepers.empty())
			{
				if (is_heap(heaperJeepers.begin(), heaperJeepers.end()))
				{
					cout << "\n\t\tThe dynamic array is a heap :D";
				}
				else
					cout << "\n\t\tThe dynamic array is not a heap :( .";
			}
			else
				cout << "\n\t\tThe dynamic array is empty :( fill it up";
		}break;
		case 'I':
		{
			if (!heaperJeepers.empty())
			{
				cout << "\n\t\tThe heap elements in container are: ";
				auto heapEnd = is_heap_until(heaperJeepers.begin(), heaperJeepers.end());

				for (auto i = heaperJeepers.begin(); i != heapEnd; i++)
					cout << *i << " ";
			}
			else
				cout << "\n\t\tThe dynamic array is empty :( fill it up";
		}break;
		case 'J':
		{
			if (heaperJeepers.empty())
				cout << "\n\t\tThe dynamic array is empty :( fill it up";
			else
				cout << "\n\t\tElements: "; print(heaperJeepers);
		}break;
		case '0': return;
		}
		cout << "\n\n"; system("pause");
	} while (true);

	return;

}

//Precondition: Receives a vector of integers
//Postcondition: Prints the elements of the vector
void print(const vector<int>& vec)
{
	for (int element : vec)
		cout << element << " ";
}
