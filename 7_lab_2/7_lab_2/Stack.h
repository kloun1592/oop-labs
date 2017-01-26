template <typename T>
class CMyStack
{
public:
	CMyStack(int maxSize);
	CMyStack(const CMyStack<T> &);
	CMyStack(const CMyStack<T> &&);
	~CMyStack();

	void Push(const T &);
	void Pop();
	void PrintStack();
	int GetStackSize() const;
	T *GetPtr() const;
	int GetTop() const;
	void Clear();
	bool IsEmpty() const;
	T GetTopElement() const;
	CMyStack<T> & operator=(const CMyStack<T> & otherStack);
	CMyStack<T> & operator=(CMyStack<T> && otherStack);
private:
	T *m_stackPtr;
	int m_size;
	int m_top = 0;
};

template <typename T>
CMyStack<T>::CMyStack(int maxSize)
	:m_size(maxSize)
{
	m_stackPtr = new T[m_size * 2];
}

template <typename T>
CMyStack<T>::CMyStack(const CMyStack<T> & otherStack)
	:m_size(otherStack.GetStackSize())
{
	m_stackPtr = new T[m_size];
	m_top = otherStack.GetTop();

	for (int i = 0; i < m_top; i++)
	{
		m_stackPtr[i] = otherStack.GetPtr()[i];
	}
}

template<typename T>
CMyStack<T>::CMyStack(const CMyStack<T> && otherStack)
	:m_size(otherStack.GetStackSize())
{
	m_stackPtr = new T[m_size];

	for (int i = 0; i < otherStack.GetTop(); i++)
	{
		m_stackPtr[m_top++] = otherStack.GetPtr()[i];
	}
}

template <typename T>
CMyStack<T>::~CMyStack()
{
	delete[] m_stackPtr;
}

template <typename T>
void CMyStack<T>::Push(const T &value)
{
	assert(m_top < m_size);
	m_stackPtr[m_top++] = value;
}


template <typename T>
void CMyStack<T>::Pop()
{
	assert(m_top > 0);
	--m_top;
	m_stackPtr[m_top] = T();
}

template <typename T>
void CMyStack<T>::PrintStack()
{
	for (int i = m_top - 1; i >= 0; i--)
	{
		std::cout << m_stackPtr[i] << std::endl;
	}
}

template <typename T>
int CMyStack<T>::GetStackSize() const
{
	return m_size;
}

template <typename T>
T *CMyStack<T>::GetPtr() const
{
	return m_stackPtr;
}

template <typename T>
int CMyStack<T>::GetTop() const
{
	return m_top;
}

template<typename T>
T CMyStack<T>::GetTopElement() const
{
	return m_top != 0 ? m_stackPtr[m_top - 1] : throw std::bad_alloc();
}

template<typename T>
void CMyStack<T>::Clear()
{
	while (!IsEmpty())
	{
		Pop();
	}
}

template<typename T>
bool CMyStack<T>::IsEmpty() const
{
	return m_top == 0;
}

template<typename T>
CMyStack<T>& CMyStack<T>::operator=(const CMyStack<T>& otherStack)
{
	int newSize = m_size + otherStack.GetStackSize();
	T *tempStack = new T[newSize];
	for (int i = 0; i <= m_top - 1; i++)
	{
		tempStack[i] = m_stackPtr[i];
	}
	delete[] m_stackPtr;
	m_size = newSize;
	m_stackPtr = tempStack;
	for (int i = 0; i < otherStack.GetTop(); i++)
	{
		m_stackPtr[m_top++] = otherStack.GetPtr()[i];
	}
	return *this;
}

template <typename T>
CMyStack<T> & CMyStack<T>::operator=(CMyStack<T> && otherStack)
{
	Clear();
	for (int i = 0; i < otherStack.GetTop(); i++)
	{
		m_stackPtr[m_top++] = otherStack.GetPtr()[i];
	}
	return *this;
}