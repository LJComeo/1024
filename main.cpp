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
		cout << "我是父类的函数" << endl;
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
		cout << "我是子类的函数" << endl;
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
	string _name = "小李子";
	int _num = 111;
};
//protected类型：只能在派生类里面访问
class Student : public Person
{
protected:
	int _num = 999;
public:
	void Print()
	{
		cout << "姓名：" << _name << endl;
		cout << "省份证号：" << Person::_num << endl;
		cout << "学号：" << _num << endl;
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
	//1.子类对象可以赋值给父类对象/指针/引用
	Person pobj = sobj;
	Person* pp = &sobj;
	Person& rp = sobj;

	//2.基类对象不能赋值给派生类对象
	//sobj = pobj;

	//3.基类的指针可以通过强制类型转换赋值给派生类的指针
	pp = &sobj;
	Student* ps1 = (Student*)pp;//这种情况转换是可以的
	ps1->_No = 10;

	pp = &pobj;
	Student* ps2 = (Student*)pp;//这种情况转换时虽然可以，但是会存在越界访问的问题
	ps2->_No = 10;
	*/		



	return 0;
}