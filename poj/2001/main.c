#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct trieNode trie;

struct trieNode
{
    int count;
    trie *next[26];
    char c;
};

char strs[1024][25];

void insert(trie *root, char str[25])
{
    int len = strlen(str);
    int i, id;
    for ( i = 0; i < len; i++)
    {
        id = str[i] - 'a';
        if ( root->next[id] == NULL )
        {
            root->next[id] = (trie *)malloc(sizeof(trie));
            memset(root->next[id], 0, sizeof(trie));
            root->next[id]->c = str[i];
        }
        root = root->next[id];
        root->count++;
    }
}

void find(trie *root, char str[25])
{
    int len = strlen(str);
    int i, id;
    printf("%s ", str);
    for ( i = 0; i < len; i++)
    {
        id = str[i] - 'a';
        if ( root->count == 1 )
        {
            break;
        }
        root = root->next[id];
        printf("%c", str[i]);
    }
}

int main()
{
    int i, j, k, strMount;
    trie *root = (trie *)malloc(sizeof(trie));
    memset(root, 0, sizeof(trie));
    memset(strs, 0, sizeof(strs));
    i = 0;
    while( scanf("%s", strs[i]) != EOF )
    {
        insert(root, strs[i]);
        i++;
    }
    strMount = i;
    for ( i = 0; i < strMount; i++)
    {
        find(root, strs[i]);
        printf("\n");
    }
    return 0;
}
