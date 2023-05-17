/*
������ ��������� �������� ������������ ϸ�� ��������� �� 151 ������. � ��� ����� ��������.
*/

/*
������ 1.1. �������: 
������� ����, ��������� �� ����� �����.
������� ��� ������������� ��������, ������� ������ �� ������ ���������.
������� ���������� ��������� ������ ��������� � �������� ����� ���������
(��������, �������� ��������� ����� ������: 1 2 3 1 2 4 1. ���������: 1 2 3 4.)
*/


#include<iostream>					//����������� ���������� �����-������
using namespace std;


struct stack {						//���� ����������� ��� struct ��������� �������
	int inf;
	stack * next;
};


void push(stack * &h, int x) {		//������� ���������� �������� � ����
	stack * r = new stack;			//������ ����� �������
	r -> inf = x;					//�������������� ���� inf = x
	r -> next = h;					//C�������� ��������� �������� h
	h = r;							//������ r �������� �������
}


int pop(stack * &h) {				//������� �������� �������� �� ����� (� ����������� ��� ��������)
	int i = h -> inf;				//�������� ������� ��������
	stack * r = h;					//��������� �� ������ �����
	h = h -> next;					//��������� ��������� �� ��������� �������
	delete r;						//������� ������ �������
	return i;						//���������� ��������
}


void reverse(stack * &h) {			//������� "���������" �����
	stack * head1 = NULL;			//������������� ��������� �����

	while (h)						//���� ���� �� ����
		push(head1, pop(h));		//������������ �� ������ ����� � ������

	h = head1;						//�������������� ���������
}


stack * result(stack * &h) {		//������� ������ ����������
	stack * res = NULL;				//�������������
	stack * h1 = NULL;				//�������������

	while (h) {						//���� ���� �� ����
		int x = pop(h);				//������� ������ ������� � ���������� ��� ��������
		push(res, x);				//���������� � ��������� res

		while (h) {					//���� ���� �� ����
			int y = pop(h);			//������� ������� �� ����� � ���������� ��� ��������
			if (y != x)				//���� �� �� ����� x
				push(h1, y);		//���������� � ����� ����
		}

		reverse(h1);				//�������������� ���� h1
		h = h1;						//�������������� ��������� (h, �.�. head, - ������ ��� h1)
		h1 = NULL;					//�������������� ��������� (�������� h1)
	}

	reverse(res);					//�������������� ����-��������� res
	return res;						//���������� ����-��������� res
}




int main() {						//������� �������
	int n;							//���������� ����� �����
	cout << "n = ";
	cin >> n;						//������ ���������� ����� �����
	cout << endl;

	stack * head = NULL;			//�������������
	int x;

	for (int i = 0; i < n; i++) {	//������� ����
		cin >> x;					//������ �����
		push(head, x);				//��������� ����
	}

	reverse(head);					//�������������� ����, ����� ��� ��� �������, � ������� �� ������� �����

	stack * res = result(head);		//��������� (����, ��� �� ������� ��� ������������� �����)
	cout << endl;
	while (res)						//���� res �� ������ ������
		cout << pop(res) << " ";	//������� �� ����� �������� ����� res �������� pop(...)
	cout << endl;
	
	system("Pause");				//�����
	return 0;						//����� ���������
}
