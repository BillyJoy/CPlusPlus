// Last Update:2013-09-22 20:09:38
/**
 * @file linker_list.c
 * @brief 
 * @author maoxing63570@gmail.com
 * @version 0.1.00
 * @date 2013-09-22
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LEN 20

typedef struct _tagItem
{
    char word[MAX_WORD_LEN];
    struct _tagItem* pNext;
}Item;

Item* AllocItem(const char* word)
{
    Item* item = malloc(sizeof(Item));
    if (item == NULL)
    {
        return NULL;
    }

    if (word != NULL)
    {
        memset(item, 0, sizeof(Item));
        memcpy(item->word, word, sizeof(item->word));
    }
    return item;
}

void PrintList(Item* head)
{
    if (head == NULL)
    {
        return;
    }

    Item* item = head->pNext;
    size_t count = 0;
    for (; item != NULL; item = item->pNext)
    {
        printf("%d %s\n", ++count, item->word);
    }
}

void FreeList(Item* head)
{
    if (head == NULL || head->pNext == NULL)
    {
        return;
    }

    Item* item = head->pNext;
    Item* prev = NULL;
    size_t count = 0;
    for (; item != NULL;) 
    {
        prev = item;
        item = item->pNext; 
        free(prev);
    }
}

bool InsertFront(Item* head, Item* item)
{
    if (head == NULL || item == NULL)
    {
        return false;
    }

    if (head->pNext == NULL)
    {
        head->pNext = item;
    }
    else
    {
        item->pNext = head->pNext;
        head->pNext = item;
    }

    return true;
}

Item* InsertBack(Item* item, Item* insert_item)
{
   if (item == NULL || insert_item == NULL)
   {
       return NULL;
   }

   
   item->pNext = insert_item;
   //if (item->pNext == NULL)
   //{
   //}
   //else
   //{
   //    item->pNext = insert_item;
   //}

   return insert_item;
}

int main(int argc, char* argv[])
{
    const char* const words[] = {"I", "Love", "Programming", "Programming", "for", "fun"};
    int i = 0;
    Item* head = AllocItem(NULL);
    if (head == NULL)
    {
        return -1;
    }

    Item* inserted_item = head;
    for (i = 0; i < 6; ++i)
    {
        Item* item = AllocItem(words[i]);
        if (item != NULL)
        {
            if (!(inserted_item = InsertBack(inserted_item, item)))
            {
                printf("warning, InsertFront failed!");
            }
        }
    }

    PrintList(head);
    FreeList(head);
    return 0;
}
