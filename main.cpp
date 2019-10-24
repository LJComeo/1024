#include <iostream>
#include <string>
using namespace std;

/*
class TestBase
{
public:
	int m_a;

	TestBase(int i) :
		m_a(i)
	{

	}

	void func(int i)
	{
		cout << "���Ǹ���ĺ���" << endl;
	}
};

class Test :public TestBase
{
public:
	int m_a;
	Test(int a, int b) :
		TestBase(a),
		m_a(b)
	{

	}
	void func()
	{
		cout << "��������ĺ���" << endl;
	}
};
*/

/*
class Person
{
protected:
	string _name = "peter";
	int _age = 18;
public:
	void Print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
};

class Student :public Person
{
protected:
	int _stuid;
};

class Teacher : public Person
{
protected:
	int _jobid;
};
*/
/*
class Person
{
public:
	void Print()
	{
		cout << _name << endl;
	}
protected:
	string _name;
private:
	int _age;
};

class Student : public Person
{
protected:
	int _stunum;
};
*/

/*
class Person
{
protected:
	string _name;
	string _sex;
	int _age;
};
class Student : public Person
{
public:
	int _No;
};
*/

/*
class Person
{
protected:
	string _name = "С����";
	int _num = 111;
};
//protected���ͣ�ֻ�����������������
class Student : public Person
{
protected:
	int _num = 999;
public:
	void Print()
	{
		cout << "������" << _name << endl;
		cout << "ʡ��֤�ţ�" << Person::_num << endl;
		cout << "ѧ�ţ�" << _num << endl;
	}
};
*/

/*
class A
{
public:
	void fun()
	{
		cout << "func()" << endl;
	}
};
class B : public A
{
public:
	void fun()
	{
		//A::fun();
		cout << "func(int i) ->" << endl;
	}
};
*/

class Person
{
protected:
	string _name;
public:
	Person(const char * name = "peter")
		: _name(name)
	{
		cout << "Person()" << endl;
	}
	Person(const Person& p)
		: _name(p._name)
	{
		cout << "Person(const Person& p)" << endl;
	}

	Person& operator=(const Person& p)
	{
		cout << "Person operator=(const Person& p)" << endl;
		if (this != &p)
			_name = p._name;
		return *this;
	}
	~Person()
	{
		cout << "~Person()" << endl;
	}
};

class Student : public Person
{
protected:
	int _num;
public:
	Student(const char * name, int num)
		:Person(name),
		_num(num)
	{
		cout << "Student()" << endl;
	}

	Student(const Student& s)
		: Person(s),
		_num(s._num)
	{
		cout << "Student(const Student& s)" << endl;
	}

	Student& operator = (const Student& s)
	{
		cout << "Student& operator = (const Student& s)" << endl;
		if (this != &s)
		{
			Person::operator=(s);
			_num = s._num;
		}
		return *this;
	}

	~Student()
	{
		cout << "~Student()" << endl;
	}


};
int main()
{
	Student s1("jack", 18);
	Student s2(s1);
	Student s3("rose", 17);
	s1 = s3;
	
	/*
	B * b = new B();
	A * a = b;
	b->fun();
	a->fun();
	*/

	/*
	Student sobj;
	//1.���������Ը�ֵ���������/ָ��/����
	Person pobj = sobj;
	Person* pp = &sobj;
	Person& rp = sobj;

	//2.��������ܸ�ֵ�����������
	//sobj = pobj;

	//3.�����ָ�����ͨ��ǿ������ת����ֵ���������ָ��
	pp = &sobj;
	Student* ps1 = (Student*)pp;//�������ת���ǿ��Ե�
	ps1->_No = 10;

	pp = &pobj;
	Student* ps2 = (Student*)pp;//�������ת��ʱ��Ȼ���ԣ����ǻ����Խ����ʵ�����
	ps2->_No = 10;
	*/		



	return 0;
}