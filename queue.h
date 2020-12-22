#include<stdlib.h>
#include<stdint.h>
#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include"appconst.h"

typedef struct _coust_q_ Custq;

typedef struct _queue_ Queue;

typedef struct _share_info_ Share;

typedef struct  _queue_result_ QueueResult;

struct _coust_q_ {
    char name[STR_LEN];
};

struct _share_info_ {
    char name[STR_LEN];
    char date[STR_LEN];
    int32_t price;
    int32_t quantity;
};

struct _queue_ {
    uint32_t size;
    uint32_t count;
    uint32_t rear;
    uint32_t front;
    Share* shares[SHARE_Q_LEN];
};



struct _queue_result_ {
    int32_t data;
    uint32_t status;
};

Queue queue_new (uint32_t size);
uint8_t queue_full(Queue *q);
uint8_t queue_empty(Queue *q);
Queue* queue_add(Queue *q, QueueResult *res, char name[], char date[], int32_t price, int32_t quantity);
Queue* queue_delete(Queue *q, QueueResult *res);
uint32_t queue_length(Queue *q);
Queue* queue_delete_partial(Queue *q, QueueResult *res,char name[STR_LEN], int32_t quantity);


#endif // QUEUE_H_INCLUDED
