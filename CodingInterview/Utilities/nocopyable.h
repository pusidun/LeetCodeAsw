#ifndef _UTILITIES_NOCOPYABLE_H_
#define _UTILITIES_NOCOPYABLE_H_

class nocopyable{
protected:
	nocopyable(const nocopyable& ) = delete;
	nocopyable& operator=(const nocopyable& ) = delete;

public:
	nocopyable() = default;
	~nocopyable() = default;
};

#endif
