#include <iostream>
using namespace std;

template <typename T>
class Mynode{
    T m_data;
    //Mynode *m_prev;//上一个
    Mynode *m_next;//下一个
public:
    Mynode(T &x=0)
    {
        m_data = x;
        //m_prev = NULL;
        m_next = NULL;
    }
};

/*template <typename T>
class Myiterator{
    Mynode<T> *m_pnode;
public:
    Myiterator(Mynode<T> x):m_pnode(x){}
};*/

template <typename T>
class Mylist{
    Mynode<T> *m_plist;//头节点
    Mynode<T> *m_last;//尾节点
public:
    
    Mylist()
    {
        m_plist = new Mynode<T>;
        m_last = m_plist;
    }
    ~Mylist()
    {
        Mynode<T> *ptmp = m_plist;
        for(; ptmp; ptmp = ptmp->m_next)
            delete ptmp;
    }
    //容器元素的个数
    int Size(void)
    {
        Mynode<T> *ptmp = m_plist;
        int num = 0;
        while(ptmp->m_next != NULL)
        {
            num++;
            ptmp = ptmp->m_next;
        }
        return num;
    }
    //判断容器是否为空
    bool Empty()
    {
        if(m_last == m_plist)
            return true;
        else
            return false; 
    }
    //在容器尾部增加一个元素
    void PushBack(T x)
    {
        Mynode<T> *ptmp = new Mynode<T>(x);
        if(m_plist == m_last)
        {
            m_plist->m_next = ptmp;
            m_last = ptmp;
        }
        else
        {
            m_last->m_next = ptmp;
            m_last = ptmp;
        }
    }
    class Myiterator{
        Mynode<T> *m_pnode;
    public:
        Myiterator(Mynode<T>* x):m_pnode(x){}
        //重载!=
        bool operator !=(const Myiterator &x)
            return m_pnode != x.m_pnode;
        //重载 后++
        Myiterator<T>  operator ++(void)  
        {  
            iterator<T> tmp = *this;  
            m_pnode = m_pnode->m_pNext;  
            return tmp;  
        }
        //重载 *
        T &operator *(void)
		{ 
            return m_pnode->m_data; 
		}
    };
    typedef T* iterator;
    //首元素
    iterator Begin(void)  
    {  
        return m_plist->m_next;  
    }
    //尾部
    iterator End(void)  
    {  
        return m_last->m_next;  
    }
};

int main(void)
{
    Mylist<int> lStr;  
    cout << "lStr Size: " << lStr.Size() << endl;  
    cout << "lStr Empty: " << lStr.Empty() << endl;  
      
    Mylist<int>::iterator itr;  
    for (itr = lStr.Begin(); itr != lStr.End(); itr++)  
    {  
        cout << *itr << '\t';  
    }
    cout << endl;  

    lStr.PushBack(1);  
    lStr.PushBack(2);  
    lStr.PushBack(3);  
    lStr.PushBack(4);  
    lStr.PushBack(5);  
    lStr.PushBack(6);  
   
    cout << "lStr Size: " << lStr.Size() << endl;  
    cout << "lStr Empty: " << lStr.Empty() << endl;  
          
    for (itr = lStr.Begin(); itr != lStr.End(); itr++)  
    {  
        cout << *itr << '\t';  
    }   
    cout << endl;
} 
