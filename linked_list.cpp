#include <iostream>

using namespace std;

typedef struct node {
    int number;             // some data
    struct node *next; // pointer to another node
} node;

int main(void) {

    node *list = NULL;
    node *n = (node *)malloc(sizeof(node)); // n points to a node
    if (n == NULL) {
        return 1;
    }

    //(*n).number = 1;
    n->number = 1; // same as the above line "go to n and access number"
    n->next = NULL;
    list = n; // now list points to this node (first element of list)
    
    // add another node to the list
    n = (node*)malloc(sizeof(node));
    if (n == NULL) {
        free(list);
        return 1;
    }
    n->number = 2;
    n->next = NULL;
    list->next = n;
    
    // add another one
    n = (node*)malloc(sizeof(node));
    if (n == NULL) {
        free(list->next);
        free(list);
        return 1;
    }
    n->number = 3;
    n->next = NULL;
    list->next->next = n;


    
    // now lets print these values
    for (node *tmp = list; tmp != NULL; tmp = tmp->next) {
        cout << tmp->number << endl;
    }





    // free(list->next->next);
    // free(list->next);
    // free(list);
    // lets free in a better way
    while (list != NULL) {
        node *tmp = list->next;
        free(list); // I can now free list (i.e. free the address at which list points)
        list = tmp;
    }

    return 0;
}
