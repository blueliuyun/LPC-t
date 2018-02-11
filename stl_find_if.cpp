/****************************************************************
* 	@2018-02-11 find	find_if
*	(1) map 提供的 find 成员函数仅限于 查找关键字满足条件的记录，不支持
*		值域的比较；
*	(2) 若要在值域中查找记录，需要使用 find_if 函数；
*		template <class InputIterator, class Predicate> 
*		InputIterator find_if(InputIterator first, InputIterator last,Predicate pred) 
*		{	 
*       	while (first != last && !pred(*first)) ++first; 
*       	return first; 
*		}
*		find_if() 第 3 个形参 可以是一个处理用的函数
* 	
*		// TEMPLATE FUNCTION find_if
*		template<class _InIt, class _Pr> inline
*		_InIt find_if(_InIt _First, _InIt _Last, _Pr _Pred)
*		{	// find first satisfying _Pred
*			_DEBUG_RANGE(_First, _Last);
*			_DEBUG_POINTER(_Pred);	
*			for (; _First != _Last; ++_First)
*    			if (_Pred(*_First))
*      				break;
*  			return (_First);
*		}	
* 
*	(3) class map_finder {}; 它的核心就是重载的()运算符，并最终在 if (_Pred(*_First)) 代码处执行 () 重载的调用 
*		因为每个容器迭代器的*运算符得到的结果都是该容器的 value_type 值， i.e.  (*_First)
*		所以该运算符的形参就是 map 迭代器指向的 value_type 类型的引用。
*	(4) STL的源代码对 map 的 value_type 类型定义。 
*		template <class Key, class T, class Compare = less<Key>, class Alloc = alloc>
*		class map
*		{
*		public:
*			typedef Key key_type;
*			typedef pair<const Key, T> value_type;
*			......
*		}; 
*		从上面的定义可以看出，map的value_type是std::pair<const Key, t>类型，它的first值就是关键字，second值保存map的值域 
*
*/

#include <map> 
#include <string>

using namespace std;

class map_finder
{
public:
	map_finder(const std::string &cmp_string):m_s_cmp_string(cmp_string){}
	bool operator()(const std::map<int, std::string>::value_type &pair) 
	{
		return pair.second == m_s_cmp_string;
	}
private:
	const std::string m_s_cmp_string;
};

int main()
{
    std::map<int, std::string> my_map;
    my_map.insert(std::make_pair(10, "china"));
    my_map.insert(std::make_pair(20, "usa"));
    my_map.insert(std::make_pair(30, "english"));
    my_map.insert(std::make_pair(40, "hongkong"));    
    my_map.insert(std::make_pair(90, "uk"));
    
    std::map<int, std::string>::iterator it = my_map.end();
    map_finder mf("english");
    it = std::find_if(my_map.begin(), my_map.end(), mf); //map_finder("english"));
    if (it == my_map.end())
       printf("not found\n");       
    else
       printf("found key:%d value:%s\n", it->first, it->second.c_str());
       
    system("pause");
    return 0;        
}

