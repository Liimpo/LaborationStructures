#include "CircularDoubleDirectedList.h"
#include <iostream>

using namespace std;
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	CircularDoubleDirectedList<int> aList;
	aList.addAtCurrent(5);
	//aList.moveCurrent();
	aList.addAtCurrent(7);
	aList.addAtCurrent(6);
	aList.changeDirection();
	//cout << aList.getElementAtCurrent() << endl;
	/*aList.addAtCurrent(4);
	cout << aList.getElementAtCurrent() << endl;
	aList.removeAtCurrent();
	cout << aList.getElementAtCurrent() << endl;*/
	for (int i = 0; i < aList.size(); i++)
	{
		cout << aList.getElementAtCurrent() << endl;
		aList.moveCurrent();
	}
	system("pause");
	return 0;
}