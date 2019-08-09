### Singletion lazy

```
class Singletion:public nocopyable
{
protected:
	Singletion();
public:
	Singletion* getInstance();
private:
	Singletion* m_pInstance;
}
```

线程不安全的实现
```
Singletion* Singletion::getInstance()
{
	if(m_pInstance == nullptr)
		m_pInstance = new Singletion();
	return m_pInstance;
}
```

双重锁实现
```
pthread_mutex_t Singletion::lck_;

Singletion* Singletion::getInstance()
{
	if(m_pInstance == nullptr)
	{
		pthread_mutex_lock(&lck_);
		if(m_pInstance == nullptr)
			m_pInstance = new Singletion();
		pthread_mutex_unlock(&lck_);
	}
	return m_pInstance;
}
```
实际上由于CPU重排,这种方法也是不安全的.
一般说来是先开辟内存，再调用构造函数，然后返回地址给指针。由于重排，后2个操作可能颠倒，上面这种写法就会导致用户得到一个未构造的对象。

解决方法：

1. 内存屏障
```
Singletion* Singletion::getInstance()
{
	if(m_pInstance == nullptr)
	{
		pthread_mutex_lock(&lck_);
		if(m_pInstance == nullptr)
		{
			Singletion* temp = new Singletion();
			barrier();
			m_pInstance = temp;
		}
		pthread_mutex_unlock(&lck_);
	}
	return m_pInstance;
}
```

2. c++11解决
见参考

3. pthread_once
陈硕《Linux多线程服务端编程》书上提供的方法
```
template<typename T>
class Singleton:nocopyable
{
public:
	static T& instance()
	{
		pthread_once(&ponce_, &Singleton::init);
		return *value_;
	}

private:
	Singleton();
	~Singleton();

	static void init()
	{
		value_ = new T();
	}

private:
	static pthread_once_t ponce_;
	static T* value_;
};

template<typename T>
pthread_once_t Singleton<T>::ponce_ = PTHREAD_ONCE_INIT;

template<typename T>
T* Singleton<T>::value_=NULL;
```

参考：
https://thorns.cn/2019/03/09/DCLP.html
https://www.oschina.net/translate/double-checked-locking-is-fixed-in-cpp11?cmp&p=1
https://preshing.com/20130930/double-checked-locking-is-fixed-in-cpp11/
https://github.com/chenshuo/muduo