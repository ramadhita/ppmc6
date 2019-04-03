#include "function.h"

char* getGroup(int matkul, int index)
{
    char *group;
    group = malloc(2 * sizeof(char));
    group[0] = '\0';
    group[1] = '\0';
    group[2] = '\0';
    switch(matkul)
    {
        case 1:
            group[0] = (char)64 + (int)(ceil((double)index / 2));
            group[1] = (char)(50 - index % 2);
            break;
        case 2:
            if (index == 7)
            {
                group[0] = 'C';
            }
            else
            {
                group[0] = (char)(64 + (int)ceil((double)index / 3));
                if(index % 3 == 0)
                {
                    group[1] = '3';
                }
                else
                {
                    group[1] = (char)(51 - index % 3);
                }

            }
            break;
        case 3:
            group[0] = index + 64;
            break;
        default:
            break;
    }
    return group;
}

char* getAsisten(char list[2])
{
    if ((int)list[0] < 65 || (int)list[0]>73)
    {
        return "";
    }
    else
    {
        char *asisten;
        asisten = malloc(3*sizeof(char));
        asisten[0] = list[0];
        asisten[1] = ',';
        asisten[2] = list[1];
        asisten[3] ='\0';
        return asisten;
    }
}

char* getMatkul(int index)
{
    switch (index)
    {
    case 1:
        return "EL2205-";
        break;
    case 2:
        return "EL2208-";
        break;
    case 3:
        return "EB2200-";
        break;
    default:
        return "";
        break;
    }
}

char* getHari(int index)
{
    switch (index)
    {
    case 0:
        return "Senin";
        break;
    case 1:
        return "Selasa";
        break;
    case 2:
        return "Rabu";
        break;
    case 3:
        return "Kamis";
        break;
    case 4:
        return "Jumat";
        break;
    default:
        return "Senin";
        break;
    }
}
