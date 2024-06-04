#include "DLIST.h"

void task(DLIST& list)
{
    ptrDNODE ptr = list.get_head();
    while (ptr)
    {
        if (ptr->info->get_spec()[0] == '~')
            list.remove(ptr);
        else
            ptr = ptr->next;
    }
}

int main()
{
    DLIST list("files.txt");
    list.print();
    std::cout << "===================\n";
    task(list);
    list.print();
}