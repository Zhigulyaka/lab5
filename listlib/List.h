#pragma once
#ifndef _LIST_
#define _LIST_

#include <iostream>

using namespace std;

template <class T>
class ListElem
{
protected:
    T data;
    ListElem<T>* next;
    ListElem<T>* prev;
public:
    ListElem(T _data);
    ~ListElem();
    T GetData();
    ListElem<T>* GetNext();
    ListElem<T>* GetPrev();

    void SetData(T _data);
    void SetNext(ListElem<T>* _next);
    void SetPrev(ListElem<T>* _prev);
    template <class T>
    friend ostream& operator<< (ostream& ostr, const ListElem<T>& A);
    template <class T>
    friend istream& operator >> (istream& istr, ListElem<T>& A);


};
template<class T>
inline ostream& operator<<(ostream& ostr, const ListElem<T>& A)
{
    ostr << A.data;
    return ostr;
}

template<class T>
inline istream& operator>>(istream& istr, ListElem<T>& A)
{
    istr >> A.data;
}
template<class T>
inline void ListElem<T>::SetData(T _data)
{
    data = _data;
}

template<class T>
inline void ListElem<T>::SetNext(ListElem* _next)
{
    next = _next;

}

template<class T>
inline void ListElem<T>::SetPrev(ListElem* _prev)
{
    prev = _prev;
}

template<class T>
inline ListElem<T>::ListElem(T _data)
{
    data = _data;
    next = nullptr;
    prev = nullptr;
}

template<class T>
inline ListElem<T>::~ListElem()
{
    next = nullptr;
    prev = nullptr;
}

template<class T>
inline T ListElem<T>::GetData()
{
    return data;
}

template<class T>
inline ListElem<T>* ListElem<T>::GetNext()
{
    return next;
}

template<class T>
inline ListElem<T>* ListElem<T>::GetPrev()
{
    return prev;
}

template <class T>
class List
{
protected:
    ListElem<T>* root;
    ListElem<T>* end;
    int count;
public:
  
    List();
    ~List();
    List(List<T>& other);

  void Ins(ListElem<T>* d, T elem);
  void InsFirst(T elem);
  void InsLast(T elem);

  List<T>& operator =(List<T>& other);

  ListElem<T>* GetFirst();
  ListElem<T>* GetLast();
  ListElem<T>* GetMiddle(T elem);

  bool IsFull() const;
  bool IsEmpty() const;

  void DelFirst();
  void DelLast();
  void Del(ListElem<T>* d);

  template <class T>
  friend ostream& operator<< (ostream& ostr, const List<T> &A);
  template <class T>
  friend istream& operator >> (istream& istr, List<T> &A);

  int GetCount();
  void DelList();

  void Rotate();
  void DelMax();
};



template <class T>
ostream& operator<< (ostream& ostr, const List<T> &A) 
{
  ListElem<T>* i=A.root;
  while(i!= nullptr)
  {
    ostr << *i << "->";
    i = i->GetNext();
    if (i == nullptr)
        ostr << "NULL"<< endl;
  }
  return ostr;
}

template <class T>
istream& operator >> (istream& istr, List<T> &A)
{
   
    int count;
    istr >> count;
  for (int i = 0; i < count; i++) 
  {
      T d;
    istr >> d;
    A.InsLast(d);
  }
  return istr;
}


template <class T>
List<T>::List()
{
  root = nullptr;
  count = 0;
  end = nullptr;
}

template <class T>
List<T>::List(List<T>& other)
{
    root = nullptr;
    end = nullptr;
  count = other.count;
  ListElem<T>* i = other.root;
  if (i != nullptr)
  {
      this->InsFirst(i->GetData());
      i = i->GetNext();
  }

  while (i != nullptr)
  {
      this->InsLast(i->GetData());
      i = i->GetNext();
  }
}
template<class T>
inline void List<T>::Ins(ListElem<T>* d, T elem)
{
    ListElem<T>* tmp = new ListElem<T>(elem);
    tmp->SetNext(d->GetNext());
    tmp->SetPrev(d);
    d->GetNext()->SetPrev(tmp);
    count++;
}
template<class T>
inline void List<T>::InsFirst(T elem)
{
    ListElem<T>* tmp = new ListElem<T>(elem);
    tmp->SetPrev(0);

    tmp->SetNext(root);
    if (root == nullptr)
        end = tmp;
    root = tmp;
    count++;
}
template<class T>
inline void List<T>::InsLast(T elem)
{
    ListElem<T>* tmp = new ListElem<T>(elem);
    if ((end == root)&&(root!= nullptr))
        root->SetNext(tmp);
    if(end!= nullptr)
    end->SetNext(tmp);
    tmp->SetPrev(end);
    tmp->SetNext(nullptr);
    end = tmp;
    count++;
}
template <class T>
List<T>::~List()
{
    this->DelList();
    
}

template <class T>
List<T>& List<T>::operator =(List<T>& other)
{
    
    if (this == &other)
        return (*this);
    this->DelList();

    count = other.count;
    ListElem<T>* i = other.root;
    if (i != nullptr)
    {
    this->InsFirst(i->GetData());
    i = i->GetNext();
    }

    while (i != nullptr)
    {
        this->InsLast(i->GetData());
        i = i->GetNext();
    }
}

template<class T>
inline ListElem<T>* List<T>::GetFirst()
{
    if ((*this).IsEmpty())
        throw logic_error("list_is_empty");
    return root;
}

template<class T>
inline ListElem<T>* List<T>::GetLast()
{
    if ((*this).IsEmpty())
        throw logic_error("list_is_empty");
    return end;
}

template<class T>
inline ListElem<T>* List<T>::GetMiddle(T elem)
{
    if ((*this).IsEmpty())
        throw logic_error("list_is_empty");
    if (this->root != nullptr)
    {
        ListElem<T>* i = (*this).root;
        while (i != nullptr)
        {
            if (i->GetData() == elem)
            {
                break;
            }
            i = i->GetNext();
            
        }

        if (i == nullptr)
            throw logic_error("not_found");
        else
            return i;
    }
}


template <class T>
int List<T>::GetCount()
{
  return count;
}

template<class T>
inline void List<T>::DelList()
{
    if (this->root != nullptr)
    {
        ListElem<T>* i = (*this).root;
        ListElem<T>* k = nullptr;
        while (i != nullptr)
        {
            k = i;
            i = i->GetNext();
            delete k;
        }

        this->root = nullptr;
        this->end = nullptr;
        count = 0;
    }
}

template<class T>
inline void List<T>::Rotate()
{
    if ((*this).IsEmpty())
        throw logic_error("list_is_empty");
    if(root==end)
        throw logic_error("list_has_one_element");
    if (this->root != nullptr)
    {
        ListElem<T>* i = (*this).root;
        ListElem<T>* j = (*this).end;
        ListElem<T>* t;
        int k = 0;
        while (i < j)
        {
            k = i->GetData();
            i->SetData(j->GetData());
            j->SetData(k);
            i=i->GetNext();
            j = j->GetPrev();
        }
    }
}

template<class T>
inline void List<T>::DelMax()
{
    if ((*this).IsEmpty())
        throw logic_error("list_is_empty");
    if (this->root != nullptr)
    {
        ListElem<T>* i = (*this).root;
        T m = i->GetData();
        ListElem<T>* k = nullptr;
        while (i != nullptr)
        {
            if (m < i->GetData())
            {
                k = i;
                m = i->GetData();
            }
            i = i->GetNext();
        }
        if (k == root)
        {
            this->DelFirst();
        }
        if (k == end)
        {
            this->DelLast();
        }
        else
            this->Del(k);
        count--;
    }
}

template<class T>
inline bool List<T>::IsFull() const
{
    try
    {
        ListElem<T>* tmp = new ListElem<T>(d);
        delete tmp;
        return false;
    }
    catch (...)
    {
        return true;
    }
}

template<class T>
inline bool List<T>::IsEmpty() const
{
    return (count== 0);
}

template<class T>
inline void List<T>::DelFirst()
{
    if ((*this).IsEmpty())
        throw logic_error("list_is_empty");
    ListElem<T>* tmp = root;
    root = root->GetNext();
    count--;
    delete tmp;
}

template<class T>
inline void List<T>::DelLast()
{
    if ((*this).IsEmpty())
        throw logic_error("list_is_empty");
    ListElem<T>* tmp = end;
    end = end->GetPrev();
    end->SetNext(nullptr);
    count--;
    delete tmp;
}

template<class T>
inline void List<T>::Del(ListElem<T>* d)
{
    if ((*this).IsEmpty())
        throw logic_error("list_is_empty");
    if(d->GetPrev()!= nullptr)
    d->GetPrev()->SetNext(d->GetNext());
    if (d->GetNext() != nullptr)
    d->GetNext()->SetPrev(d->GetPrev());
    count--;
    delete d;
}

#endif