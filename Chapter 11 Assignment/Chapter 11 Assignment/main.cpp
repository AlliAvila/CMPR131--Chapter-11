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
		case 0: return;
		}
		cout << "\n\n"; system("pause");
	} while (true);

	return;
}
void Option2()
{
	do
	{
		system("cls");
		cout << "\n\t2> Union and intersect Heap";
		cout << "\n\t" << string(80, char(205));
		cout << "\n\t\tA> Union two max Heaps";
		cout << "\n\t\tB> Intersect two max Heaps";
		cout << "\n\t\tC> Union two mmin Heaps";
		cout << "\n\t\tD> Intersect two min Heaps";
		cout << "\n\t" << string(80, char(196));
		cout << "\n\t\t0> Exit";
		cout << "\n\t" << string(80, char(205));

		switch (toupper(inputChar("\n\t\tOption: ", static_cast<string>("abcd0"))))
		{
		case 'A': break;
		case 'B': break;
		case 'C': break;
		case 'D': break;
		case 0: return;
		}
		cout << "\n\n"; system("pause");
	} while (true);

	return;
}

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
			make_heap(heaperJeepers.begin(), heaperJeepers.end());
			cout << "\n\t\tThe dymaic array has been created into a heap ";
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
			if (is_heap(heaperJeepers.begin(), heaperJeepers.end()))
			{
				int element = inputInteger("\n\t\tEnter an integer element to into the heap: ",true);
				heaperJeepers.push_back(element);
				push_heap(heaperJeepers.begin(), heaperJeepers.end());
				cout << "\n\t\tElement " << element << " pushed into the heap.";
			}
			else
				cout << "\n\t\tERROR: The dynamic array is not a heap. Please create a heap first.";
		}break;
		case 'F':
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
		}break;
		case 'G':
		{
			if (is_heap(heaperJeepers.begin(), heaperJeepers.end()))
			{
				cout << "\n\t\tBefore the sorted heap: ";
				print(heaperJeepers);

				sort_heap(heaperJeepers.begin(), heaperJeepers.end());
				cout << "\n\t\tSorted heap: ";
				print(heaperJeepers);
			}
			else
				cout << "\n\t\tERROR: The dynamic array is not a heap. Please create a heap first.";
		}break;
		case 'H':
		{
			if (is_heap(heaperJeepers.begin(), heaperJeepers.end()))
			{
				cout << "\n\t\tThe dynamic array is a heap :D";
			}
			else
				cout << "\n\t\tThe dynamic array is not a heap :( .";

		}break;
		case 'I':
		{
			cout << "\n\t\tThe heap elements in container are: ";
			auto heapEnd = is_heap_until(heaperJeepers.begin(), heaperJeepers.end());

			for (auto i = heaperJeepers.begin(); i != heapEnd; i++)
				cout << *i << " ";


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

void print(const vector<int>& vec)
{
	for (int element : vec)
		cout << element << " ";
}
