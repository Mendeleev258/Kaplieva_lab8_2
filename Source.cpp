#include "DLIST.h"

int compare(File f1, File f2)
{
    return strcmp(f1.get_spec(), f2.get_spec());
}

int compare_special(File f1, File f2)
{
    int result{ -1 };
    if (f1.get_spec()[0] == '~' && f2.get_spec()[0] == '~')
        result = 0;
    else
        if (f1.get_spec()[0] != '~' && f2.get_spec()[0] == '~')
            result = 1;
    return result;
}

void task(DLIST& list)
{
    ptrDNODE ptr = list.get_head();
    while (ptr && ptr->info->get_spec()[0] == '~')
        list.remove(ptr);
}

int main()
{
    DLIST list("files.txt", compare_special);
    list.print();
    std::cout << "=============\n";
    task(list);
    list.print();
}