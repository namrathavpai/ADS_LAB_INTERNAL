#include<stdlib.h>
#include<stdint.h>
#include"queue.h"
#include<assert.h>
#include<string.h>

int count=0;

Queue queue_new(uint32_t size){
    size = (size > 0 && size < COUST_Q_LEN)? size: COUST_Q_LEN;
    Queue q1 = {size, 0, 0, 0, {NULL,NULL,0,0}};
    return q1;
}

uint8_t queue_full(Queue *q){
    assert(q != NULL);
    return (q->count == q->size);
}

uint8_t queue_empty(Queue *q){
    assert(q != NULL);
    return (q->count == 0);
}

Queue* queue_add(Queue *q, QueueResult *res, char name[STR_LEN], char date[10], int32_t price, int32_t quantity) {
    assert(q != NULL);
    if (q->count < q->size){
            for (count=0;count<SHARE_Q_LEN;count++){
                if(strcmp(q->shares->name,name)==0){
                    q->shares[0]->name[STR_LEN] = name[STR_LEN];
                    q->shares->date[10] = date[10];
                    q->shares->price = price;
                    q->shares->quantity = quantity;
                    q->rear = (q->rear + 1) % q->size;
                    ++q->count;
                    res->status = Q_OK;
                }
            }
    } else {
        res->status = Q_FULL;
    }

    return q;
}

//Queue* queue_delete(Queue *q, QueueResult *res){
//    assert(q != NULL);
//    if (q->count != 0){
//        res->data = q->shares[q->front]->name[STR_LEN];
//        q->front = (q->front + 1) % q->size;
//        --q->count;
//        res->status = Q_OK;
//    } else {
//        res->status = Q_EMPTY;
//    }
//    return q;
//}
//
//Queue* queue_delete_partial(Queue *q, QueueResult *res,char name[STR_LEN], int32_t quantity){
//    assert(q != NULL);
//    if (q->count != 0){
//            for(count=0;count<SHARE_Q_LEN;count++){
//                if(strcmp(q->shares[count]->name,name)== 0) {
//                    res->data = q->shares[count]->name[STR_LEN];
//                    q->shares[count]->quantity = q->shares[count]->quantity-quantity;
//                }
//            }
//    }
//    return q;
//}
//
//Queue* queue_add_partial(Queue *q, QueueResult *res,char name[STR_LEN], int32_t quantity){
//    assert(q != NULL);
//    if (q->count != 0){
//            for(count=0;count<SHARE_Q_LEN;count++){
//                if(strcmp(q->shares[count]->name,name)== 0) {
//                    res->data = q->shares[count]->name[STR_LEN];
//                    q->shares[count]->quantity = q->shares[count]->quantity+quantity;
//                }
//            }
//    }
//    return q;
//}

uint32_t queue_length(Queue *q) {
    assert(q != NULL);
    return q->count;
}

