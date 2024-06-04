#include "DLIST.h"

DLIST::DLIST(const char* file_name)
{
    std::ifstream data_file(file_name);
    ptrFile file = new File(data_file);
    first_node(file);
    while (!data_file.eof())
    {
        file = new File(data_file);
        insert_after(tail, file);
    }
    data_file.close();
}

DLIST::~DLIST()
{
    while (!empty())
        remove(head);
}

void DLIST::first_node(ptrFile file)
{
    head = new DNODE(file);
    tail = head;
}

void DLIST::print(std::ostream& stream)
{
    ptrDNODE p = head;
    while (p)
    {
        (p->info)->print();
        p = p->next;
    }
}

void DLIST::insert_after(ptrDNODE ptr, ptrFile file)
{
    ptrDNODE ptr1 = new DNODE(file, ptr->next, ptr);
    if (ptr == tail)
        tail = ptr1;
    else
        ptr->next->prev = ptr1;
    ptr->next = ptr1;
}

bool DLIST::empty()
{
    return head == nullptr;
}

void DLIST::remove(ptrDNODE& ptr)
{
    ptrDNODE p = ptr;
    if (ptr == head)
    {
        head = p->next;
        ptr = head;
        if (p->next)
            p->next->prev = nullptr;
    }
    else
        if (ptr == tail)
        {
            tail = p->prev;
            ptr = tail;
            if (p->prev)
                p->prev->next = nullptr;

        }
        else
        {
            ptr = ptr->next;
            p->next->prev = p->prev;
            p->prev->next = p->next;
        }
    delete p;
}
