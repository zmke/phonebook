#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "phonebook_bst.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */
bst *findName(char lastName[], bst* root)
{
    bst* temp = root;
    while (temp != NULL) {
        int val = strcasecmp(lastName, temp->lastName);
        if(val == 0)
            return temp;
        else if(val < 0)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;
    return e;
}

bst *list_to_BST(entry *pHead)
{
    int listLen = 0;
    entry *cur = pHead;
    while(cur) {
        listLen++;
        cur = cur->pNext;
    }
    return build(&pHead, listLen);
}

bst *build(entry **pHead, int listLen)
{
    if(listLen <= 0)
        return NULL;

    bst *left = build(pHead, listLen/2);
    bst *root = (bst *) malloc(sizeof(bst));
    strcpy(root->lastName, (*pHead)->lastName);
    root->left = left;
    *pHead = (*pHead)->pNext;
    root->right = build(pHead, listLen-listLen/2-1);
    return root;
}
