#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
  List *lista = NULL;
  lista = (List *) malloc (sizeof(List));
  
     return lista;
}

void * firstList(List * list) {
  list->current = list->head;
  if (list->current == NULL) return NULL;
  
  
  return (list->current->data);
}

void * nextList(List * list) {
  if (list->current == NULL) return NULL;
  list->current = list->current->next;

  if (list->current == NULL) return NULL;
  return list->current->data;
}

void * lastList(List * list) {
  if (list->tail == NULL || list->current == NULL) return NULL;
  list->current = list->tail;
  return list->current->data ;
}

void * prevList(List * list) {
  if (list->current == NULL ||list->current->prev == NULL) return NULL;
  list->current = list->current->prev;
  
    return list->current->data;
}

void pushFront(List * list, void * data) {
  Node *n = createNode(data);
  
  if (list->head == NULL) {
    list->head = n;
    list->current = n;
    list->tail = n;
  }
    
  else {
    n->next = list->head;
    list->head->next = n;
    list->head = n;
  }
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
  Node *n = createNode(data);
  
  if (list->current->next == NULL){
    list->current->next = n;
    n->prev = list->current;
    list->tail = n;
  }
  else{
    n->prev = list->current;
    n->next = list->current->next;
    list->current->next->prev = n;
    list->current->next = n;
  }
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {

  list->current->next->prev = list->current->prev;
  list->current->prev->next = list->current->next;

  void *dato = list->current->data;
  list->current = list->current->next;
  
    return dato;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}