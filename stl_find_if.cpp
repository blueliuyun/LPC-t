/****************************************************************
* 	@2018-02-11 find	find_if
*	(1) map �ṩ�� find ��Ա���������� ���ҹؼ������������ļ�¼����֧��
*		ֵ��ıȽϣ�
*	(2) ��Ҫ��ֵ���в��Ҽ�¼����Ҫʹ�� find_if ������
*		template <class InputIterator, class Predicate> 
*		InputIterator find_if(InputIterator first, InputIterator last,Predicate pred) 
*		{	 
*       	while (first != last && !pred(*first)) ++first; 
*       	return first; 
*		}
*		find_if() �� 3 ���β� ������һ�������õĺ���
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
*	(3) class map_finder {}; ���ĺ��ľ������ص�()��������������� if (_Pred(*_First)) ���봦ִ�� () ���صĵ��� 
*		��Ϊÿ��������������*������õ��Ľ�����Ǹ������� value_type ֵ�� i.e.  (*_First)
*		���Ը���������βξ��� map ������ָ��� value_type ���͵����á�
*	(4) STL��Դ����� map �� value_type ���Ͷ��塣 
*		template <class Key, class T, class Compare = less<Key>, class Alloc = alloc>
*		class map
*		{
*		public:
*			typedef Key key_type;
*			typedef pair<const Key, T> value_type;
*			......
*		}; 
*		������Ķ�����Կ�����map��value_type��std::pair<const Key, t>���ͣ�����firstֵ���ǹؼ��֣�secondֵ����map��ֵ�� 
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

