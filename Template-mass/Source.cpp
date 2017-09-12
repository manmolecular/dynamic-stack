#include <iostream>
#include <string>

/*
	Динамический стек с произвольным типом элементов класса

	"Я сделаю свой стек, с блекджеком и костылями!
*/

template <class type> class type_stack
{
	private:
		type *stack_ptr;						//указатель на стек
		int size;								//размер для резервации
		int top;								//положение вершины стека
	public:
		type_stack(int def);					//конструктор с задачей дефолтного кол-ва элементов
		type_stack(type_stack<type> &rhs);		//копирующий конструктор
		~type_stack();							//деструктор
		void push_value(type value);			//добавляем элемент на вершину
		void pop_value();						//удаляем элемент 
		int get_size();							//узнаем размер (по памяти)
		int get_top();							//узнаем размер (по факту - вершина)
		int is_empty();							//проверяем на пустоту
		type get_elem(int num);					//получить элемент
		void print_stack();						//печатаем стек
};

template <class type> type_stack <type>::type_stack(type_stack<type> &rhs)
{
	size = rhs.get_size();
	top = rhs.get_top();
	stack_ptr = new type[size];
	for (int i = 0; i < top; i++)
	{
		stack_ptr[i] = rhs.get_elem(i);
	}
}

template <class type> type type_stack <type>::get_elem(int num)
{
	if (num <= top)
	{
		return stack_ptr[top - 1 - num];
	}
}

template <class type> type_stack <type>::type_stack(int def)
{
	size = def;
	stack_ptr = new type[size];
	top = 0;
}

template <class type> type_stack <type>::~type_stack()
{
	delete[] stack_ptr;
}

template <class type> void type_stack <type>::push_value(type value)
{
	if(top < size)
	{
		stack_ptr[top] = value;
		top++;
	}
}

template <class type> void type_stack <type>::pop_value()
{
	if(top > 0)
	{
		top--;
	}
}

template <class type> int type_stack <type>::get_size()
{
	return size;
}

template <class type> int type_stack <type>::get_top()
{
	return top;
}

template <class type> int type_stack <type>::is_empty()
{
	if (top > 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

template <class type> void type_stack <type>::print_stack()
{
	for (int i = top - 1; i >= 0; i--)
	{
		std::cout << stack_ptr[i] << std::endl;
	}
}

int main()
{
	type_stack<int> ints(10);
	for (int i = 0; i < 10; i++)
	{
		ints.push_value(i);
	}
	ints.pop_value();
	std::cout << "Stack of ints contains: " << std::endl;
	ints.print_stack();
	std::cout << "Size of stack (memory for elements): " << ints.get_size()*sizeof(int) << " bytes / " << ints.get_size() << " elements" << std::endl;
	std::cout << "Size of stack (from 0 to top): " << ints.get_top()*sizeof(int) << " bytes / " << ints.get_top() << " elements" << std::endl << std::endl;

	type_stack<char> chars(10);
	chars.push_value('l');
	chars.push_value('k');
	std::cout << "Stack of chars contains: " << std::endl;
	chars.print_stack();
	std::cout << "Size of stack (memory for elements): " << chars.get_size() << std::endl;
	std::cout << "Size of stack (from 0 to top): " << chars.get_top() << std::endl << std::endl;

	type_stack<double> doubles(10);
	doubles.push_value(2.46);
	doubles.push_value(4.48);
	doubles.pop_value();
	std::cout << "Stack of doubles contains: " << std::endl;
	doubles.print_stack();
	std::cout << "Size of stack (memory for elements): " << doubles.get_size() << std::endl;
	std::cout << "Size of stack (from 0 to top): " << doubles.get_top() << std::endl << std::endl;

	type_stack<double> doubles_copy(doubles);
	doubles_copy.push_value(6.66);
	doubles_copy.push_value(21.567);
	doubles_copy.push_value(1.58);
	doubles_copy.push_value(7.48);
	std::cout << "Stack of doubles copy contains: " << std::endl;
	doubles_copy.print_stack();
	std::cout << "Size of stack (memory for elements): " << doubles_copy.get_size() << std::endl;
	std::cout << "Size of stack (from 0 to top): " << doubles_copy.get_top() << std::endl << std::endl;
	return 0;
}