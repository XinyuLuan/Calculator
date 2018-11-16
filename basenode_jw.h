#ifndef BASENODE_JW
#define BASENODE_JW
#include <cstdlib>

class baseNodeJW
{
    public:
        baseNodeJW();
        virtual ~baseNodeJW();
        virtual baseNodeJW& operator=(const baseNodeJW &other);
//this section does not apply
        virtual bool operator<(const baseNodeJW &x) const;
        virtual bool operator<=(const baseNodeJW &x) const;
        virtual bool operator>(const baseNodeJW &x) const;
        virtual bool operator>=(const baseNodeJW &x)const;
        virtual bool operator==(const baseNodeJW &x) const;
        virtual bool operator!=(const baseNodeJW &x) const;
        baseNodeJW*& nextNode();
        baseNodeJW*& prevNode();
        void * getValue() const;
        void setValue(void *ptr);
        void * getPiority();
        void setPriority(void * ptr);

    protected:

    private:
        void *value;
        void *priority;
        baseNodeJW *next, * prev;
        //void copy(const baseNodeJW *other);

};
baseNodeJW::baseNodeJW()
{
    value = priority = next = prev = NULL;
}

baseNodeJW::~baseNodeJW()
{
    //delete value;
    value = priority = next = prev = NULL;
}

//void baseNodeJW::copy(const baseNodeJW* other)
//{
//    //this->value = other->getValue();
//    this->next = NULL;
//}

baseNodeJW*& baseNodeJW::nextNode()
{
    return next;
}

baseNodeJW*& baseNodeJW::prevNode()
{
    return prev;
}

void* baseNodeJW::getValue() const
{
    return value;
}

void baseNodeJW::setValue(void *ptr)
{
    value = ptr;
}


void baseNodeJW::setPriority(void * ptr)
{
     priority= ptr;
}

void * baseNodeJW::getPiority(){
  return priority;
}

baseNodeJW& baseNodeJW::operator=(const baseNodeJW &other)
{
  //if(this!=&other)
  //   copy(&other);
  return *this;
}

bool baseNodeJW::operator<(const baseNodeJW &x) const
{
    return value < x.getValue();
}

bool baseNodeJW::operator<=(const baseNodeJW &x) const
{
  return value <= x.getValue();
}

bool baseNodeJW::operator>(const baseNodeJW &x) const
{
  return value >x.getValue();
}

bool baseNodeJW::operator>=(const baseNodeJW &x)const
{
  return value >= x.getValue();
}

bool baseNodeJW::operator==(const baseNodeJW &x) const
{
  return value == x.getValue();
}

bool baseNodeJW::operator!=(const baseNodeJW &x) const
{
  return value!=x.getValue();
}
#endif // BASENODE_JW

