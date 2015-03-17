#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)
// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

// trie node
typedef struct trie_node
{
    int value;
    int print;
    struct trie_node *children[ALPHABET_SIZE];
}trie_node_t;

// trie ADT
typedef struct trie
{
    trie_node_t *root;
//    int print;
    int count;
}trie_t;

// Returns new trie node (initialized to NULLs)
trie_node_t *getNode(void)
{
    trie_node_t *pNode = NULL;

    pNode = (trie_node_t *)malloc(sizeof(trie_node_t));

    if( pNode )
    {
        int i;

        pNode->value = 0;
        pNode->print = 1;
        for(i = 0; i < ALPHABET_SIZE; i++)
        {
            pNode->children[i] = NULL;
        }
    }
    else
        printf("Memory Allocation Error!!!!\n");
    return pNode;
}

// Initializes trie (root is dummy node)
void initialize(trie_t *pTrie)
{
    pTrie->root = getNode();
    pTrie->count = 0;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
void insert(trie_t *pTrie, char key[])
{
    int level;
    int length = strlen(key);
    int index;
    trie_node_t *pCrawl;
    pTrie->count++;
    pCrawl = pTrie->root;

    for( level = 0; level < length; level++ )
    {
        index = CHAR_TO_INDEX(key[level]);
        if( !pCrawl->children[index] )
        {
            pCrawl->children[index] = getNode();
        }

        pCrawl = pCrawl->children[index];
    }

    // mark last node as leaf
    pCrawl->value = pTrie->count;
}

// Returns non zero, if key presents in trie
int search(trie_t *pTrie, char key[])
{
    int level;
    int length = strlen(key);
    int index;
    trie_node_t *pCrawl;

    pCrawl = pTrie->root;

    for( level = 0; level < length; level++ )
    {
        index = CHAR_TO_INDEX(key[level]);

        if( !pCrawl->children[index] )
        {
            return 0;
        }
        pCrawl = pCrawl->children[index];
    }
return (0 != pCrawl && pCrawl->value);
}
void print(trie_t *pTrie,char key[])
{
    int level;
    int length = strlen(key);
    int index;
    trie_node_t *pCrawl;

    pCrawl = pTrie->root;

    for( level = 0; level < length; level++ )
    {
        index = CHAR_TO_INDEX(key[level]);
        pCrawl = pCrawl->children[index];
        if(level==0 && pCrawl->print==1)
          printf("Keywords starting with %c\n",key[0]);
        if(pCrawl->print==1)
        {
            printf("-%c",key[level]);
            pCrawl->print=0;
        }
        else if(pCrawl->print==0)
            printf("  ");
    }
    printf("\n");
}
// Driver
int main()
{
    // Input keys (use only 'a' through 'z' and lower case)
    //char keys[][8] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};

    char p[1000000],found[32][30],s[1000000],filename[100];
    char keyword[][30]={"auto","break","case","char","const","continue","default","do","double","else",
                        "enuum","extern","float","for","goto","if","int","long","register","return","short",
                        "signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};
    trie_t trie;
    initialize(&trie);
    int i,arr[26],m=0,j,k,flag,index;
    for(i=0;i<26;i++)
        arr[i]=0;
    for(i = 0; i < ARRAY_SIZE(keyword); i++)
    {
        insert(&trie, keyword[i]);
    }
    printf("Enter filename with .txt extension\n");
    scanf("%s",filename);
    printf("\n");
    FILE *fp=fopen(filename,"r");
    if (fp == NULL)
      {
            printf("File not found\n");
            exit(1);
      }
    while (fgets(s,sizeof(s), fp) != NULL) {
           printf("%s\n", s);
           k=0;
    for(i=0;i<strlen(s);i++)
    {
      if(s[i]>='a' && s[i]<='z')
         p[k++]=s[i];
      else
      {
          p[k]='\0';
          flag=search(&trie,p);
          if(flag)
          {
            for(j=0;j<m;j++)
            {
                if(!strcmp(found[j],p))
                    break;
            }
            if(j==m)
            {
            for(j=0;j<=k;j++)
            found[m][j]=p[j];
            m++;
            }
          k=0;
        }
     }
    }
    p[k]='\0';
    flag=search(&trie,p);
    if(flag)
      {
            for(j=0;j<m;j++)
            {
                if(!strcmp(found[j],p))
                    break;
            }
            if(j==m)
            {
            for(j=0;j<=k;j++)
            found[m][j]=p[j];
            m++;
            }
      }
    }
    printf("\n");
    for(i=0;i<m;i++)
    {
      if(!arr[found[i][0]-'a'])
      {
       print(&trie,found[i]);
       arr[found[i][0]-'a']=1;
       for(j=0;j<m;j++)
        {
          if(found[i][0]==found[j][0] && j!=i)
            print(&trie,found[j]);
        }
        printf("\n\n");
      }
    }
    return 0;
}
