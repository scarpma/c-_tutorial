#include <cstdlib>
#include <iostream>

using namespace std;

typedef struct node {
    int number;
    node *next;
}node;

typedef struct List { // container for list nodes
    node *first;
    node *last;
    int len;
}list;

// print list with cycle
void printList(node* list) {
    int len = 0;
    node *current = list;
    for (node *tmp = list; tmp != NULL; tmp = tmp->next) {
        cout << tmp->number << " ";
        len++;
    }
    cout << endl;
    cout << "lenght: " << len << endl;
    return;
}

int main(void) {
    
    node *list, *tmp, *last;
    cout << "size of node: " << sizeof(node) << endl;

    // build list with cycle
    for (int i=0; i<23; i++) {
        tmp = (node*)malloc(sizeof(node));
        if (i == 0) {
            list = tmp;
        }
        tmp->number = i * 8 - 2;
        tmp->next = NULL;
        last->next = tmp; // store location of last added element
        last = tmp;
    }

    printList(list);
    
    List list2;
    list2.first = list;
    list2.last = last;
    list2.len = 23;

    // free list with cycle
    while (list != NULL) {
        tmp = list->next;
        free(list);
        list = tmp;
    }

    return 0;
}
