template <typename T>
class CMyStack
{
public:
	CMyStack() = default;
	CMyStack(CMyStack<T> && other)
	{
		m_firstNode = std::move(other.m_firstNode);
		m_lastNode = other.m_lastNode;
		m_size = other.m_size;
		other.m_lastNode = nullptr;
		other.m_size = 0;
	}

	struct Node
	{
		Node(const T & data, Node * prev, std::unique_ptr<Node> && next)
			: data(data), prev(prev), next(std::move(next))
		{
		}
		T data;
		Node *prev;
		std::unique_ptr<Node> next;
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
	std::unique_ptr<Node> m_firstNode = nullptr;
	Node * m_lastNode = nullptr;
	size_t m_size;
};

template <typename T>
void CMyStack<T>::Push(const T &value)
{
	auto newNode = std::make_unique<Node>(value, m_lastNode, nullptr);
	Node *newLastNode = newNode.get();
	if (m_lastNode)
	{
		m_lastNode->next = std::move(newNode);
	}
	else // empty list
	{
		m_firstNode = std::move(newNode);
	}
	m_lastNode = newLastNode;
	++m_size;
}

template <typename T>
void CMyStack<T>::Pop()
{
	if (m_firstNode.get() == m_lastNode)
	{
		m_lastNode = nullptr;
		m_firstNode = nullptr;
	}
	else
	{
		m_lastNode = m_lastNode->prev;
		m_lastNode->next = nullptr;
	}
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
		throw std::bad_alloc();
	}
	return m_lastNode->data;
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
	CMyStack<T> tmp;
	tmp.m_size = otherStack.GetStackSize();
	for (auto it = otherStack.m_firstNode.get(); it != nullptr; it = it->next.get())
	{
		tmp.Push(it->data);
	}
	std::swap(tmp, *this);
	return *this;
}

template <typename T>
CMyStack<T> & CMyStack<T>::operator=(CMyStack<T> && otherStack)
{
	if (&otherStack != this)
	{
		Clear();
		m_firstNode = std::move(otherStack.m_firstNode);
		m_lastNode = otherStack.m_lastNode;
		m_size = otherStack.m_size;
		otherStack.m_lastNode = nullptr;
		otherStack.m_size = 0;
	}
	return *this;
}
