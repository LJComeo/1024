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

class NonInherit final//C++11��ʹ��final�ؼ��ֵ���Ͳ��ܱ��̳���
{};


int main()
{



	return 0;
}