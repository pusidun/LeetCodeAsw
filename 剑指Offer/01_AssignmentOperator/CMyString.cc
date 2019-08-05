#include<string.h>
#include<stdio.h>

class CMyString
{
public:
	CMyString(char* pData = nullptr);
	CMyString(const CMyString& str);
	~CMyString();

	CMyString& operator=(const CMyString& );

	void Print();
//private:
	char* m_pData;
};

//copy operator
CMyString& CMyString::operator=(const CMyString& str)
{
	if(m_pData != &str)
	{
		CMyString tmpData(str);
		
		char *ptmp = tmpData.m_pData;
		tmpData.m_pData = m_pData;
		m_pData = ptmp;
	}
	return *this;
}

CMyString::CMyString(char* pData = nullptr)
{
	if(!pData)
	{
		m_pData = new char[1];
		char[0] = '\0';
	}
	else
	{
		int len = strlen(pData);
		m_pData = new char[len + 1];
		strcpy(m_pData, pData);
	}
}

CMyString::CMyString(const CMyString& str)
{
	int len = strlen(str);
	m_pData = new char[len + 1]	;
	strcpy(m_pData, str);
}

~CMyString::CMyString()
{
	delete[] m_pData;
}

void CMyString::Print()
{
	printf("%s\n", m_pData);
}

//=================TEST====================

int main()
{
	char* text = "hello!"
	CMyString str1(text);
	CMyString str2, str3;
	str2 = str1;
	printf("%s\n", str2);

	str1 = str1;
	printf("%s\n", str1);

	str3 = str2 = str1;
	printf("%s\n", str3);

	return 0;
}