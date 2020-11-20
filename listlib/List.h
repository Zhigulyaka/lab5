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
    next = 0;
    prev = 0;
}

template<class T>
inline ListElem<T>::~ListElem()
{
    next = 0;
    prev = 0;
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
};



template <class T>
ostream& operator<< (ostream& ostr, const List<T> &A) 
{
  ListElem<T>* i=A.root;
  while(i!=0)
  {
    ostr << *i << endl;
    i = i->GetNext();
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
  root = 0;
  count = 0;
  end = 0;
}

template <class T>
List<T>::List(List<T>& other)
{
  count = other.count;
  ListElem<T>* i = other.root;
  ListElem<T>* j = (*this).root;
  ListElem<T>* k = 0;
  while (i != 0)
  {
      j = new ListElem<T>(* i);
      j->SetNext(0);
      if (k != 0)
      {
          k = j->SetNext(j);
          j = j->SetPrev(k);
      }
      p = j;
      if (root == 0)
          root = j;
      end = j;
      i = i->next;
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
    if (root == 0)
        end = tmp;
    root = tmp;
    count++;
}
template<class T>
inline void List<T>::InsLast(T elem)
{
    ListElem<T>* tmp = new ListElem<T>(elem);
    if ((end == root)&&(root!=0))
        root->SetNext(tmp);
    if(end!=0)
    end->SetNext(tmp);
    tmp->SetPrev(end);
    tmp->SetNext(0);
    end = tmp;
    count++;
}
template <class T>
List<T>::~List()
{
    if (this->root != 0)
    {
         ListElem<T>* i = (*this).root;
         ListElem<T>* k = 0;
         while (i != 0)
         {
             k = i;
             i = i->GetNext();
             delete k;
         }

         this->root = 0;
         this->end = 0;
         count = 0;
    }
    
}

template <class T>
List<T>& List<T>::operator =(List<T>& other)
{
    if (this == &other)
        return (*this);
    if (this->root != 0)
    {
        ListElem<T>* i = (*this).root;
        ListElem<T>* k = 0;
        while (i != 0)
        {
            k = i;
            i = i->GetPrev();
            delete k;
        }

        this->root = 0;
        this->end = 0;
        count = 0;
    }

    count = other.count;
    ListElem<T>* i = other.root;
    ListElem<T>* j = (*this).root;
    ListElem<T>* k = 0;
    while (i != 0)
    {
        j = new ListElem<T>(*i);
        j->SetNext(0);
        if (k != 0)
        {
            k = j->SetNext(j);
            j = j->SetPrev(k);
        }
        k = j;
        if (root == 0)
            root = j;
        end = j;
        i = i->next;
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
    if (this->root != 0)
    {
        ListElem<T>* i = (*this).root;
        ListElem<T>* k = 0;
        while (i != 0)
        {
            if (i->GetData() == elem)
            {
                break;
            }
            i = i->GetNext();
            
        }

        if (i == 0)
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
    return (count==0);
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
    end->SetNext(0);
    count--;
    delete tmp;
}

template<class T>
inline void List<T>::Del(ListElem<T>* d)
{
    if ((*this).IsEmpty())
        throw logic_error("list_is_empty");
    if(d->GetPrev()!=0)
    d->GetPrev()->SetNext(d->GetNext());
    if (d->GetNext() != 0)
    d->GetNext()->SetPrev(d->GetPrev());
    count--;
    delete d;
}

#endif