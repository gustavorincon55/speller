// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


#include "dictionary.h"





//function that makes a new node on the trie. And check if the node will be needed.
int makeNode(char *word);
//variable that keep the count of the words founded on the dictionary.
int wordCounter;

//node used in the trie.
typedef struct node
{
    bool isWord;
    struct node *alpha[28];
} node;

//create the start of the trie.
node *dataRoot;
node *nodeBuffer;

//Function that will unload the trie.
bool unloader(node *ptr);

//function that will initialize the node with the array memebers as NULL, and the isWord as FALSE.
bool makeStruct(node **ptr);



// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int hashCode = 0;
    nodeBuffer = dataRoot;

    //  using the trie this formula will check none by none. if it hits a NULL pointer it means that the word
    //does not exist. If at the end of the loop the last node has a isWord property as TRUE then it means the word is correct.
    for(int i = 0; i < strlen(word); i++)
    {

        switch(tolower(word[i]))
        {
        case 'a':
            hashCode = 0;
            break;
        case 'b':
            hashCode = 1;
            break;
        case 'c':
            hashCode = 2;
            break;
        case 'd':
            hashCode = 3;
            break;
        case 'e':
            hashCode = 4;
            break;
        case 'f':
            hashCode = 5;
            break;
        case 'g':
            hashCode = 6;
            break;
        case 'h':
            hashCode = 7;
            break;
        case 'i':
            hashCode = 8;
            break;
        case 'j':
            hashCode = 9;
            break;
        case 'k':
            hashCode = 10;
            break;
        case 'l':
            hashCode = 11;
            break;
        case 'm':
            hashCode = 12;
            break;
        case 'n':
            hashCode = 13;
            break;
        case 'o':
            hashCode = 14;
            break;
        case 'p':
            hashCode = 15;
            break;
        case 'q':
            hashCode = 16;
            break;
        case 'r':
            hashCode = 17;
            break;
        case 's':
            hashCode = 18;
            break;
        case 't':
            hashCode = 19;
            break;
        case 'u':
            hashCode = 20;
            break;
        case 'v':
            hashCode = 21;
            break;
        case 'w':
            hashCode = 22;
            break;
        case 'x':
            hashCode = 23;
            break;
        case 'y':
            hashCode = 24;
            break;
        case 'z':
            hashCode = 25;
            break;
        case '\'':
            hashCode = 26;
            break;
        }

        if(nodeBuffer->alpha[hashCode] == NULL)
        {
            return false;
        }
        else
        {
            nodeBuffer = nodeBuffer->alpha[hashCode];
        }
    }

    if(nodeBuffer->isWord == true)
    {
        return true;
    }

    //if the true return was not reached it means that no word was found and thus the word is not correct.
    return false;

}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{

    //takes a pointer of a pointer of a node and will make it point to a initialized node pointer.
    makeStruct(&dataRoot);

    nodeBuffer = dataRoot;

    //open the dictionary
    FILE *Fdictionary = fopen(dictionary,"r");

    wordCounter = 0;

    if(Fdictionary != NULL)
    {

        char word[46];

        while(fscanf(Fdictionary,"%s", word) == 1)
        {
            makeNode(word);
            wordCounter++;
        }
        fclose(Fdictionary);

        return true;
    }

    fclose(Fdictionary);

    // if the dictionary could not be opened then return false.
    return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    //The wordCounter variable has kept the count all along. No need no use a new function.
    return wordCounter;

}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{

    return unloader(dataRoot);
}






/* *********************** NEW FUNCTIONS *************** */





//return a node
int makeNode(char *word)
{
    int hashCode = 0;

    //  using the alpha array on the nodes this will find the correct position in that array per every letter on the word
    // in a way that it will follow the trie and will get on to another "level" with each letter.
    for(int i = 0; i < strlen(word); i++)
    {

        switch(tolower(word[i]))
        {
        case 'a':
            hashCode = 0;
            break;
        case 'b':
            hashCode = 1;
            break;
        case 'c':
            hashCode = 2;
            break;
        case 'd':
            hashCode = 3;
            break;
        case 'e':
            hashCode = 4;
            break;
        case 'f':
            hashCode = 5;
            break;
        case 'g':
            hashCode = 6;
            break;
        case 'h':
            hashCode = 7;
            break;
        case 'i':
            hashCode = 8;
            break;
        case 'j':
            hashCode = 9;
            break;
        case 'k':
            hashCode = 10;
            break;
        case 'l':
            hashCode = 11;
            break;
        case 'm':
            hashCode = 12;
            break;
        case 'n':
            hashCode = 13;
            break;
        case 'o':
            hashCode = 14;
            break;
        case 'p':
            hashCode = 15;
            break;
        case 'q':
            hashCode = 16;
            break;
        case 'r':
            hashCode = 17;
            break;
        case 's':
            hashCode = 18;
            break;
        case 't':
            hashCode = 19;
            break;
        case 'u':
            hashCode = 20;
            break;
        case 'v':
            hashCode = 21;
            break;
        case 'w':
            hashCode = 22;
            break;
        case 'x':
            hashCode = 23;
            break;
        case 'y':
            hashCode = 24;
            break;
        case 'z':
            hashCode = 25;
            break;
        case '\'':
            hashCode = 26;
            break;
        }


        if(nodeBuffer->alpha[hashCode] != NULL)
        {
            //if the array location is initialize the get to another "level".
            nodeBuffer = nodeBuffer->alpha[hashCode];
        } else //if(nodeBuffer->alpha[hashCode] == NULL)
        {
            //if the array location is null then initialize the array location.
            makeStruct(&nodeBuffer->alpha[hashCode]);

            nodeBuffer = nodeBuffer->alpha[hashCode];

        }


    }

    //  Once the trie "path" is found and the las letter was taken in to account it means that the word is complite and
    //the isWord property is set to true.
    nodeBuffer->isWord = true;

    //reset the nodeBuffer to point to the dataRoot.
    nodeBuffer = dataRoot;

    return 0;
}



bool makeStruct(node **ptr)
{
    //create a sort of "buffer" node to initialize all the node.
    node *newNode = malloc(sizeof(node));

    for(int i = 0; i < 27; i++)
    {
        newNode->alpha[i] = NULL;
    }

    newNode->isWord = false;
    if(*ptr !=NULL) { free(*ptr);}
    //maybe this does't make sense because the pointer of the node pointer was not created using malloc.
    //if(ptr != NULL) { free(ptr);}

    *ptr = newNode;



    return true;
}

bool unloader(node *ptr)
{

    //for each location on the alpha array check if there is a pointer that is not NULL.
    for(int i = 0; i < 27; i++)
    {
        if(ptr->alpha[i] != NULL)
        {

            unloader(ptr->alpha[i]);

        }

        //if the pointer in the array is null it doesn't matter. What needs to be checked are the ones that have memory allocated.
    }
    if(ptr != NULL)
    {
        free(ptr);
    }

    return true;
}
