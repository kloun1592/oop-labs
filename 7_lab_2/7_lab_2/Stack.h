template <typename T>
class CMyStack
{
public:
	CMyStack() = default;
	CMyStack(CMyStack<T> const& other);
	CMyStack(CMyStack<T> && other);
	~CMyStack();
	struct Node
	{
		Node(const T & data, std::shared_ptr<Node> const& next)
			: data(data), next(next)
		{
		}
		T data;
		std::shared_ptr<Node> next;
	};
	
	void Push(const T &value);
	void Pop();
	size_t GetStackSize() const;
	void Clear();
	bool IsEmpty() const;
	T GetTopElement() const;
	CMyStack<T> & operator=(const CMyStack<T> & otherStack);
	CMyStack<T> & operator=(CMyStack<T> && otherStack);
private:
	std::shared_ptr<Node> m_topElem = nullptr;
	size_t m_size;
};

template<typename T>
inline CMyStack<T>::CMyStack(CMyStack<T> const& other)
{
	CMyStack<T> tmp;
	for (auto it = other.m_topElem.get(); it != nullptr; it = it->next.get())
	{
		tmp.Push(it->data);
	}
	std::swap(tmp, *this);
}

template <typename T>
CMyStack<T>::CMyStack(CMyStack<T> && other)
{
	m_topElem = std::move(other.m_topElem);
	m_size = other.m_size;
	other.m_topElem = nullptr;
	other.m_size = 0;
}

template<typename T>
CMyStack<T>::~CMyStack()
{
	Clear();
}

template <typename T>
void CMyStack<T>::Push(const T &value)
{
	auto newNode = std::make_shared<Node>(value, m_topElem);
	m_topElem = newNode;
	++m_size;
}

template <typename T>
void CMyStack<T>::Pop()
{
	if (IsEmpty())
	{
		throw std::logic_error("Stack is empty");
	}
	m_topElem->data.~T();
	m_topElem = m_topElem->next;
	--m_size;
}

template <typename T>
size_t CMyStack<T>::GetStackSize() const
{
	return m_size;
}

template<typename T>
T CMyStack<T>::GetTopElement() const
{
	if (IsEmpty())
	{
		throw std::logic_error("Stack is empty");
	}
	return m_topElem->data;
}

template<typename T>
bool CMyStack<T>::IsEmpty() const
{
	return m_size == 0;
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
CMyStack<T>& CMyStack<T>::operator=(const CMyStack<T>& otherStack)
{
	if (&otherStack != this)
	{
		CMyStack<T> tmp(otherStack);
		std::swap(tmp, *this);
	}
	return *this;
}

template <typename T>
CMyStack<T> & CMyStack<T>::operator=(CMyStack<T> && otherStack)
{
	if (&otherStack != this)
	{
		Clear();
		m_topElem = std::move(otherStack.m_topElem);
		m_size = otherStack.m_size;
		otherStack.m_size = 0;
	}
	return *this;
}
