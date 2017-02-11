class CStringStack
{
public:
	CStringStack() = default;
	CStringStack(const CStringStack & other);
	CStringStack(CStringStack && other);
	~CStringStack();
	struct Node
	{
		Node(const std::string & data, std::unique_ptr<Node> & next)
			: data(data), next(std::move(next))
		{
		}
		std::string data;
		std::unique_ptr<Node> next;
	};

	void Push(const std::string &value);
	void Pop();
	size_t GetStackSize() const;
	void Clear();
	bool IsEmpty() const;
	CStringStack Reverse() const;
	std::string GetTopElement() const;
	CStringStack & operator=(const CStringStack & otherStack);
	CStringStack & operator=(CStringStack && otherStack);

private:
	std::unique_ptr<Node> m_topElem = nullptr;
	size_t m_size;
};
