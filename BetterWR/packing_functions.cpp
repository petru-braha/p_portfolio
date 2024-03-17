#include <stdio.h>
#include <string.h>
#include <filesystem>
#include <direct.h>
#define MAX 300

bool is_folder(char path[])
{
    if (std::filesystem::exists(std::filesystem::path(path)) && std::filesystem::path(path).extension() == "")
        return true;
    return false;
}

char* reverseArray(char arr[], int length)
{
    int index_start = 0;
    int index_end = length - 1;

    while (index_start < index_end)
    {
        // Swap characters at start and end indices
        char temp = arr[index_start];
        arr[index_start] = arr[index_end];
        arr[index_end] = temp;

        // Move indices towards the center
        index_start++;
        index_end--;
    }
    return arr;
}

char* get_FILEname(char source_path[])
{
    char file_name[MAX]="";
    memset(file_name, 0, sizeof file_name);
    for (int i = strlen(source_path) - 1; i; i--)
    {
        if (source_path[i] == 47)
        {
            if (i != strlen(source_path) - 1)
                break;
        }
        else
            file_name[strlen(file_name)] = source_path[i];
    }
    file_name[strlen(file_name)] = '\0';
    char* reversedArray = reverseArray(file_name, strlen(file_name));
    strcpy(file_name, reversedArray);
    file_name[strlen(file_name)] = '\0';
    return file_name;
}
