//
//  MsgList.hpp
//  msglist
//
//  Created by Jaewan Jeong on 2018. 4. 16..
//  Copyright © 2018년 Jaewan Jeong. All rights reserved.
//

#ifndef MsgList_hpp
#define MsgList_hpp

#include <stdio.h>

typedef struct node{
    node * p_node;
    int data;
    node * n_node;
    
} node;






class MsgList{
private:
    int limitOfList = 0;
    int sizeOfList = 0;
    node * linkpoint = nullptr;
    node * lastOfList = nullptr;
    node * firstOfList = nullptr;

    void setLastOfList(node* target);
    void setFirstOfList(node* target);
    void setP_node(node* target, node* source);
    void setN_node(node* target, node* source);
    void free_node(node* target);
    void free_all();
    node * nodeCreate();
public:
    MsgList();
    node* getLastOfList();
    node* getFirstOFList();
    
    node* find_node(int position);
    node* find_node(int primary,int position);
    int find_position(int data);
    int find_position(int primary ,int data);
    
    int insert(int data);
    int insert(int position,int data);
    int insert(int primary, int position,int data);
    
    int remove();
    int remove_p(int position);
    int remove_p(int primary, int position);
    int remove_d(int data);
    int remove_d(int primary, int data);
    
    int modify(int data);
    int modify_p(int position,int data);
    int modify_p(int primary, int position, int data);
    int modify_d(int target, int source);
    int modify_d(int primary, int target, int source);

    
    
    
    ~MsgList();
    
    
};

#endif /* MsgList_hpp */
