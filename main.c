#include <stdio.h>
#include <stdlib.h>
#include"queue.h"
#include<assert.h>
#include<stdio.h>



void test_add() {
    Queue q1 = queue_new(3);
    Queue *q = &q1;
    QueueResult res;

    q = queue_add(q, &res, "name1", "com1", 20, 100);
    q = queue_add(q, &res, "name1", "com2", 30, 50);
    q = queue_add(q, &res, "name3", "com3", 40, 25);
    assert(q->shares->name[STR_LEN] =="name1");
}


void test_Qdelete(){
    Queue q1 = queue_new(3);
    Queue *q = &q1;
    QueueResult res;

    q = queue_add(q, &res, "name1", "com1", 20, 100);
    q = queue_add(q, &res, "name1", "com2", 30, 50);
    q = queue_add(q, &res, "name3", "com3", 40, 25);

    q = queue_delete(q, &res);
    assert(res.data == "name1");
    assert(queue_length(q) == 2);
}

void test_Qdelete_par(){
    Queue q1 = queue_new(3);
    Queue *q = &q1;
    QueueResult res;

    q = queue_add(q, &res, "name1", "com1", 20, 100);
    q = queue_add_partial(q, &res, "name1", 100);
    assert(res.data == "name1");
}


    int main() {
    //test_empty();
    test_add();
    test_Qdelete();
    test_Qdelete_par();


    return 0;
}
