/*
	单例模式 饿汉实现 
*/
#include<cstdio>
#include"../Utilities/nocopyable.h"

class Singleton:public nocopyable
{
public:
	static Singleton* getInstance();

protected:
	Singleton();

private:
	static Singleton* instance;
};

Singleton::Singleton()
{}

Singleton* Singleton::instance = new Singleton();

Singleton* Singleton::getInstance()
{
	return instance;
}

int main()
{
	Singleton* instance1 = Singleton::getInstance();
	printf("instance1 addr:%x\n", instance1);
	Singleton* instance2 = Singleton::getInstance();
	printf("instance2 addr:%x\n", instance2);
}
