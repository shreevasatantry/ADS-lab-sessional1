#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "MMB.h"
#include<string.h>

void test(){

    Slist s1 = slist_new();
    Slist *list= &s1;
    assert (count_cust(list) == 0);

    list = open_acc(list,"Ram","",32,"ABCD1234A","SB","9865478523",2000,"BKWXYZSB1234");
    assert(list->head->data.initial_depo == 2000); //  account with 2000 initial deposit and type="SB" is created
    list = open_acc(list,"amar","",28,"ABCD1244N","SB","9865478523",3000,"BKWXYZSB1233");
    assert (list->head->data.age == 28); // Second account is created
    list = open_acc(list,"antony","",48,"XYZD1244N","STUDENT","9865478523",0,"BKWXYZST1233"); // student can have initial amout as 0
    assert(strcmp(list->head->data.acc_type,"STUDENT")==0);
    list = open_acc(list,"antony","ravi",48,"XYZD1244N","JOINT","9865478523",2200,"BKWXYZJT2233");
    assert(strcmp(list->head->data.joint_name,"ravi")==0);// account is joint so we are taking 2 names
    //##########################################################################################################

}


int main()
{
    test();
    return 0;
}
