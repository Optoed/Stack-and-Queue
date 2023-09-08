// ConsoleApplication1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

//#include "stdafx.h"
#include <iostream>
#include <string.h>

using namespace std;

//����������� ��� ������, ����� ������ - ��������� �� ������ ������ ������ ��� ���
enum StatusEr
{
	Err, OK
};

//�������� ������ �����
class Fish
{
public:
	Fish(int weight, int age, bool gender, bool predatory, string habitat, string KPFC, int cost, bool poisonous); // ����������� - ������ ������, ����, ��� � ��� ��������, ������� ���� ��� ��������, 
											  // ��� ��� �������, ��� �� ����� ���� ����� � ������ �������, ����������, � ������� ����� � ��� ��������
	Fish() { Status = Err; }				  // ����������� �� ��������� - ����������� ��� ������ � ����������� - ����� ������ ��� �������� ������������� �������, 
											  // ������� �� ����� ������������ � ������ �������!
	~Fish();
//�������/��������� - ������ �������� �������� (����, �������������� �������)
	string getPoroda();
	int getYearBirth();
	int getVes();
	string getColor();
	string getName();
// �����������
	bool getStatus(); //������ ��� ������ ������ � ������ - ������, � ����� �� � ��� ��������
//�������/������������ - ���������� (��������) �������� �������� (����, �������������� �������), ���� ��� ���������
	bool setUpVes(int v); //����� ����� ��������� ���
	bool setDownVes(int v); //����� ����� ��������� ���
	bool setName(string nm); //����� ���� ���, ��� �������� ���
//��������
	void Go();    // ����� ����
	void Voice(); // ����� ������� 
	void Print(); //����� ���������� � ���������� �������, � ���������� ����� �������� �� ���������� ���������� ������!

private:
	string Poroda;
	int YearBirth;
	int Ves;
	string Color;
	string Name;
	int Status; //� ����� �� � ������ ��������, ��� ���� ������� ������������ ���������

	bool ChangeVes(int v); //��������� ����� ������, ���������� �����! ������ ��� ����, ����� ������ ������� ��������� �� ������������ ������� �������� ��� �����
};

//����������
Fish::Fish(string p, string cl, int v, int yb)
{
	if (p == "" || cl == "" || v <= 0 || yb <= 0) //������ ������������ �������� ����� - ������ ����� ������ �� �������� ������, ����� ������ ���� ��� ������������
		Status = Err;
	else {
		Poroda = p;
		YearBirth = yb;
		Ves = v;
		Color = cl;
		Name = "���������� ���";
		Status = OK; // �� � �������, ����� �������
	}
}

Fish::~Fish()
{
}

string Fish::getPoroda()
{
	if (Status == OK) return Poroda;
	else return "";
}

int Fish::getYearBirth()
{
	if (Status == OK) return YearBirth;
	else return 0;
}

int Fish::getVes()
{
	if (Status == OK) return Ves;
	else return 0;
}

string Fish::getColor() 
{
	if (Status == OK) return Color;
	else return "";
}

string Fish::getName()
{
	if (Status == OK) return Name;
	else return "";
}

bool Fish::getStatus()
{
	return Status;
}


bool Fish::ChangeVes(int v)
{
	int tmpV = Ves + v;
	bool result = (tmpV >= 0); //�� ����� � ����� ���� ������������� ���
	if (result) Ves = tmpV; // ��� ������� ������������� � ��������� �� �������� v
	return result; // ��� �� ���������, � ����� ������ ����
}

bool Fish::setUpVes(int v) //����� ����� ��������� ���
{
	if (Status == OK)
		if (v <= 0) //�������� ����������� ������ ������������� ��� ��������� ����, � ��������� ������ ����� ������ ���������� ���� �������� ��� ����������
			return false;
		else return ChangeVes(v);
	else false;
}

bool Fish::setDownVes(int v) //����� ����� ��������� ���
{
	if (Status == OK) 
		if (v <= 0) //�������� ����������� ������ ������������� ��� ��������� ����, � ��������� ������ ����� ������ ����������� ���� �������� ��� ����������
			return false;
		else return ChangeVes(-v);
	else false;
}

bool Fish::setName(string nm) //����� ���� ���, ��� �������� ���
{
	if (Status == OK)
		if (nm  == "")   // ������ ���� ����� ������ ���
			return false;
		else { 
			Name = nm;
			return true;
		}
	else false;
}

void Fish::Go()    // ����� ����. ������ ����� ������ ���������� ����� (��, ������� �������)
{
	if (Status == OK) {
		cout << Name.c_str() << " ����� ������\n";
		cout << "@  \n";
		cout << "   @\n";
		cout << "@  \n";
		cout << "   @\n";
	}
}

void Fish::Voice() // ����� �������. ������� ����� ������ ���������� ����� (��, ������� �������)
{
	if (Status == OK) {
		cout << Name.c_str() <<" ������ " << "M-r-r-r!\n";
	}
}

void Fish::Print() // ����� ���������� � ���������� ������� ������ �����. ������� ����� ���������� ������ � ���������� �����
{
	if (Status == OK) {
		cout << "\n��������� ������ �����: " << "��� - " << Fish::getName() << ", ������ - " << Poroda.c_str() << ",\n";
		cout << "��� �������� - " << YearBirth << ", ��� - " << Ves << ".\n";
		cout << "�� ��, � ���� ������� - " << Color.c_str() << "\n\n";
	}
}

int main()
{
	bool check = false;
	cout << check << endl << endl;

	setlocale(LC_ALL, "Russian");
	//����������� ��������� �����
	cout << "������� 1-� ������ ����� � ���������� � ���\n"; 
	Fish Cat1("sdsd", "sdsd", -2, 2016); // ������� ��������� ������ �����, �� ������ �������� �������� ���
	//�������� � ��� ����������
	cout << Cat1.getStatus() << endl;
		Cat1.setName("������");
		Cat1.getVes();
		Cat1.Print();
		Cat1.Voice();
		Cat1.Go();
		if (Cat1.setDownVes(-5))
			cout << Cat1.getName().c_str() << " ������� �� " << Cat1.getVes() << " ��. \n";
		else cout << "������ ����� ��� ���������� ���� ���� " << Cat1.getName().c_str() << "!\n";

	
	
	cout << "\n������� 2-� ������ ����� � ���������� � ���\n"; // ������� ��������� ������ �����
	Fish Cat2("����", "�����", 2, 2015);

		Cat2.setName("������");
		Cat2.Print();
		Cat2.Voice();
		Cat2.Go();
		int StepV; //��� ��������� ����

		StepV = -1; //�������� �� �����, �� �� ���������
		if (Cat2.setDownVes(StepV))
			cout << Cat2.getName().c_str() << " ������� �� " << Cat2.getVes() << " ��. \n";
		else cout << "������ ����� ��� ���������� ���� ���� "<< Cat2.getName().c_str() << "!\n";
		StepV = 1;//�������� �� ����� ���������
		if (Cat2.setDownVes(StepV))
			cout << Cat2.getName().c_str() << " ������� �� " << Cat2.getVes() << " ��. \n";
		else cout << "������ ����� ��� ���������� ���� ���� " << Cat2.getName().c_str() << "!\n";

		StepV = -1; // ����� �������, �� �� ���������
		if (Cat2.setUpVes(StepV))
			cout << Cat2.getName().c_str() << " ���������� �� " << Cat2.getVes() << " ��. \n";
		else cout << "������ ����� ��� ���������� ���� ���� " << Cat2.getName().c_str() << "!\n";
		StepV = 1; //������ ���������
		if (Cat2.setUpVes(StepV))
			cout << Cat2.getName().c_str() << " ���������� �� " << Cat2.getVes() << " ��. \n";
		else cout << "������ ����� ��� ���������� ���� ���� " << Cat2.getName().c_str() << "!\n";


	cout << "\n������� 3-� ������ ����� � ���������� � ���\n"; // ������� ��������� ������ �����
	Fish Cat3("������", "�����", 3, 2001);

	Cat3.Print();

	//� ������ ��� ����� ����� ���-�� ������ ������!
	cout << "\n\n � ������ ��� ����� ����� ���-�� ������ ������!\n\n";
	Fish* lFish;
	lFish = new Fish[3];
	
	lFish[0] = Cat1;
	lFish[1] = Cat2;
	lFish[2] = Cat3;

	for (int i = 0; i < 3; i++)  
		{
			lFish[i].Voice();
			lFish[i].Go();
		}

	system("pause");
    return 0;
}

