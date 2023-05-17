/*
������ ��������� �������� ������������ ϸ�� ��������� �� 151 ������. � ��� ����� ��������.
*/

/*
������ 1.1. �������: 
������� ���������� ������, ���������� ����� �����.

*/


#include<iostream>							//����������� ���������� �����-������
using namespace std;


struct list {								//���������� ������ ����������� ��� list ��������� �������
	int inf;
	list* next;
	list* prev;
};


void push(list *&h, list *&t, int x) {		//������� �������� � 
	list* r = new list;						//������� ����� �������
	r->inf = x;								//�������������� ���� inf = x
	r->next = NULL;							//������ ���������(?)

	if (!h && !t) {							//���� ���������� ������ �����
		r->prev = NULL;							//��� � ������, � �����
		h = r;
	}

	else {
		t->next = r;						//r - ��������� ��� ������
		r->prev = t;								//������ r - �����
	}

	t = r;
}

void print(list *&h, list *&t, int x) {
	list* p = h;
	cout << "����� ����������� ����������� ������:" << endl;
	while (p) {
		cout << p->inf << ' ' << endl;
		p = p->next;
	}
}

list* find(list *&h, list *&t, int x) {
	list* p = h;
	while (p) {
		if (p->inf == x) {
			break;
		}
		p = p->next;
	}
	return p;
}


void insert_after(list *&h, list *&t, list *r, int y) {
	list *p = new list;
	p->inf = y;

	if (r == t) {
		p->next = NULL;
		p->prev = r;
		r->next = p;
		t = p;
	}

	else {
		r->next->prev = p;
		p->next = r->next;
		p->prev = r;
		r->next = p;
	}
}


void del_node(list*& h, list*& t, list* r) {				//�������� �������� �� �������
	if (r == h && r == t) {
		h = t = NULL;
	}
	else if (r == h) {
		h = h->next;
		h->prev = NULL;
	}
	else if (r == t) {
		t = t->prev;
		t->next = NULL;
	}
	else {
		r->next->prev = r->prev;
		r->prev->next = r->next;
	}
	delete r;
}

void del_list(list*& h, list*& t) {
	while (h) {
		list* p = h;
		h = h->next;
		h->prev = NULL;
		delete p;
	}
}

int main() {							//������� �������
	setlocale(LC_ALL, "RUS");

	int n;								//���������� ����� �����
	cout << "n = ";
	cin >> n;							//������ ���������� ����� �����
	cout << endl;

	list * head = NULL;				//�������������
	list* tail = NULL;
	int x;
	for (int i = 0; i < n; i++) {		//������� ����
		cin >> x;						//������ �����
		push(head, tail, x);					//��������� ����
	}
	
	system("Pause");					//�����
	return 0;							//����� ���������
}
