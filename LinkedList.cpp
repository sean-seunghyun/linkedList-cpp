//LinkedList.cpp
#include"LinkedList.h"
#include <iostream>
using namespace std;

int CompareIntegers(void *one, void *other);


int main(int argc, char* argv[]) {
	LinkedList<Long> linkedList;
	LinkedList<Long>::Node *index;
	Long key;
	Long count;
	LinkedList<Long>::Node* (*indexes);
	Long i = 0;

	index = linkedList.AppendFromHead(10);
	cout << linkedList.GetAt(index) << endl;

	cout << linkedList[0] << endl;

	index = linkedList.AppendFromHead(1);
	cout << linkedList.GetAt(index) << endl;

	index = linkedList.InsertAfter(index, 4);
	cout << linkedList.GetAt(index) << endl;

	index = linkedList.InsertBefore(index, 40);
	cout << linkedList.GetAt(index) << endl;

	key = 1;
	index = linkedList.LinearSearchUnique(&key, CompareIntegers);
	cout << linkedList.GetAt(index) << endl;

	index = linkedList.AppendFromHead(4);
	cout << linkedList.GetAt(index) << endl;
	cout << "==================" << endl;
	
	key = 4;
	linkedList.LinearSearchDuplicate(&key, &indexes, &count, CompareIntegers);
	while (i < count) {
		cout << linkedList.GetAt(indexes[i]) << endl;
		i++;
	}
	if (indexes != 0) {
		delete[] indexes;
	}
	cout << "==================" << endl;
	index = linkedList.Last();
	cout << linkedList.GetAt(index) << endl;

	index = linkedList.First();
	cout << linkedList.GetAt(index) << endl;

	index = linkedList.Previous();
	cout << linkedList.GetAt(index) << endl;

	index = linkedList.Next();
	cout << linkedList.GetAt(index) << endl;

	index = linkedList.Delete(index);
	if (index == 0) {
		cout << "���������." << endl;
	}

	index = linkedList.DeleteFromHead();
	if (index == 0) {
		cout << "���������." << endl;
	}

	index = linkedList.DeleteFromTail();
	if (index == 0) {
		cout << "���������." << endl;
	}
	
	linkedList.DeleteAllItems();
	return 0;
}


//���⼭�� one�� ����ü�� �ƴ϶� object�� �ٷ� ����Ŵ, one�� ����ü�� �ʵ��� �켱 ����ü�� �����ϰ� if������ �ʵ带 ��������.
int CompareIntegers(void *one, void *other) {
	Long *one_ = (Long*) one;
	Long *other_ = (Long*)other;
	int ret;

	if (*one_ > *other_) {
		ret = -1;
	}

	if (*one_ == *other_) {
		ret = 0;
	}

	if (*one_ < *other_) {
		ret = 1;
	}

	return ret;
}