#include <iostream>
using namespace std;

class NonIngerit
{
public:
	static NonInherit GetInstance()
	{
		return NonInherit();
	}
private:
	NonInherit()
	{}
};

class NonInherit final//C++11中使用final关键字的类就不能被继承了
{};


int main()
{



	return 0;
}