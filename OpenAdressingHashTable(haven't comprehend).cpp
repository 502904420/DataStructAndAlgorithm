#include "OpenAdressingHashTable.h"
#include "DataStructAndAlgorithm.h"

OpenAdressingHashTable::OpenAdressingHashTable(int size) : capacity(size) {
	data = new int[size];
	for (int i = 0; i < size; i++) {
		data[i] = -1;
	}
}


OpenAdressingHashTable::~OpenAdressingHashTable() {
	delete[] data;
}

//ͨ���������������ֵ��ȥ
bool OpenAdressingHashTable::search(int element,int& pos,int &times) {
	pos = hash(element);
	times = 0;
	while (data[pos] != -1 && data[pos] != element) {
		times++;
		if (times < capacity) {
			pos = (pos + 1) % capacity;
		}
		else
		{
			return false;
		}
	}
	if (element == data[pos]) {
		return true;
	}
	else
	{
		return false;
	}
	return 0;
}


int OpenAdressingHashTable::insert(int element) {
	int pos,times;
	if (search(element, pos, times))
	{
		return 2;
	}
	else
	{
		if (times < capacity / 2)
		{
			data[pos] = element;
			return 1;
		}
		else
		{
			recreate();
			return 0;
		}
	}
}


void OpenAdressingHashTable::recreate() {
	cout << "recreate" << endl;
	int *temp = data;
	int backup_capactiy = capacity;
	capacity *= 2;
	data = new int[capacity];
	for (int i = 0; i < capacity; i++) {
		data[i] = -1;
	}
	//insert֮ǰһ��Ҫ��capacity����Ϊ��ȷ��ֵ
	for (int i = 0; i < backup_capactiy; i++) {
		//�����recreate�Ĺ������ַ���recreate��ô��
		if (temp[i] != -1) {
			insert(temp[i]);
		}
	}
	delete[] temp;
}

int OpenAdressingHashTable::hash(int element) {
	return element % capacity;
}