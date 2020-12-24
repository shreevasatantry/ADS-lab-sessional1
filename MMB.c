#include <stdint.h>
#include "MMB.h"
#include<assert.h>
#include<string.h>
#include<stdio.h>

Slist slist_new()
{
    Slist s1 = {NULL,NULL,0};
    return s1;
}
uint32_t count_cust(const Slist *list){
    assert(list != NULL);
    return list->length;
}

static Node* _get_new_node_(char32_t *name,char32_t joint_name,int32_t age,char32_t *pan,char32_t *acc_type,char32_t *phone,int32_t initial_depo,char32_t acc_no)
{

        Node *newnode = (Node*)malloc(sizeof(Node));
        if (strcmp(acc_type,"SB")==0 && initial_depo >= 2000){
        newnode->data.name = name;
        newnode->data.joint_name = "";
        newnode->data.age = age;
        newnode->data.pan = pan;
        newnode->data.acc_type = acc_type;
        newnode->data.phone = phone;
        newnode->data.initial_depo = initial_depo;
        newnode->data.acc_no = acc_no;
        newnode->next = NULL;
        //printf("%ld",newnode->data.phone);
        return newnode;
        }
        else if (strcmp(acc_type,"STUDENT")==0 && initial_depo >= 0){
        newnode->data.name = name;
        newnode->data.joint_name = "";
        newnode->data.age = age;
        newnode->data.pan = pan;
        newnode->data.acc_type = acc_type;
        newnode->data.phone = phone;
        newnode->data.initial_depo = initial_depo;
        newnode->data.acc_no = acc_no;
        newnode->next = NULL;
        //printf("%ld",newnode->data.phone);
        return newnode;
        }
        else if(strcmp(acc_type,"JOINT")==0 && initial_depo >= 2200)
        {
        newnode->data.name = name;
        newnode->data.joint_name = joint_name;
        newnode->data.age = age;
        newnode->data.pan = pan;
        newnode->data.acc_type = acc_type;
        newnode->data.phone = phone;
        newnode->data.initial_depo = initial_depo;
        newnode->data.acc_no = acc_no;
        newnode->next = NULL;
        }
}

Slist* open_acc(Slist *list,char32_t *name,char32_t *joint_name,int32_t age,char32_t *pan,char32_t *acc_type,char32_t *phone,int32_t initial_depo,char32_t acc_no){
    assert(list != NULL);
    Node* newnode = _get_new_node_(name,joint_name,age,pan,acc_type,phone,initial_depo,acc_no);

    if (newnode != NULL)

    newnode->next = list->head;
    list->head=newnode;

    if(list->tail == NULL)
    {
        list->tail = newnode;
    }
    ++list->length;

    assert( (list->length == 1 && list->head == list->tail) ||
            (list->length > 1 && list->head != list->tail)
          );
    return list;

}
