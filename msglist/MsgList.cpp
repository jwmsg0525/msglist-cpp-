//
//  MsgList.cpp
//  msglist
//
//  Created by Jaewan Jeong on 2018. 4. 16..
//  Copyright © 2018년 Jaewan Jeong. All rights reserved.
//

#include "MsgList.hpp"

MsgList::MsgList()
{
    
    
    
}

void MsgList::setLastOfList(node* target)
{
    lastOfList = target;
}

void MsgList::setFirstOfList(node *target)
{
    firstOfList = target;
}

void MsgList::setP_node(node *target, node *source)
{
    source->p_node = target;
}
void MsgList::setN_node(node *target, node *source)
{
    source->n_node = target;
}

node* MsgList::nodeCreate()
{
    node* newNode = new node;
    
    
    return newNode;
}

void MsgList::free_node(node *target)
{
    target->~node();
}


node* MsgList::getLastOfList()
{
    return lastOfList;
}

node* MsgList::getFirstOFList()
{
    return firstOfList;
}


node* MsgList::find_node(int position)
{
    int positioniter = position%sizeOfList;
    node* crnt = getFirstOFList();
    for(;positioniter!=0&&position>0;positioniter--)
    {
        crnt = crnt->n_node;
    }
    
    for(;positioniter!=0&&position <0;positioniter++)
    {
        crnt = crnt->p_node;
    }
  
    return crnt;
}

node* MsgList::find_node(int primary, int position)
{
    int positioniter = position%sizeOfList;
    node* crnt = find_node(primary);
    for(;positioniter!=0&&position > 0;positioniter--)
    {
        crnt = crnt->n_node;
    }
    for(;positioniter!=0&&position < 0;positioniter++){
        crnt = crnt->p_node;
    }
    return crnt;
}

int MsgList::find_position(int data)
{   int cnt = 0;
    for(node* i = getFirstOFList() ; ;i=i->n_node,cnt++)
    {
        if(i->data == data)
        {
            break;
        }
        if(i == getLastOfList())
        {
            if(i->data != data)
                cnt = NULL; break;
        }
    }
    return cnt;
    
}

int MsgList::find_position(int primary, int data)
{
    node * nowp = find_node(primary);
    int cnt = primary ;
    for(;;nowp = nowp->n_node,cnt++)
    {
        if(nowp->data == data)
        {
            break;
        }
        if(nowp == getLastOfList())
        {
            if(nowp->data != data)
                cnt = NULL; break;
        }
    }
    return cnt;
}

int MsgList::insert(int data)
{
    
    if(sizeOfList <= limitOfList || !limitOfList)
    {
        node* nowp = getLastOfList();
        node* newNode = nodeCreate();
        newNode->data = data;
        if(sizeOfList==0)
        {
            setFirstOfList(newNode);
            setLastOfList(newNode);
            setP_node(getLastOfList(), newNode);
            setN_node(getFirstOFList(), newNode);
            sizeOfList++;
            return  0;
        }
        setP_node(nowp, newNode);
        setN_node(newNode, nowp);
        setLastOfList(newNode);
        setP_node(getLastOfList(), getFirstOFList());
        setN_node(getFirstOFList(), getLastOfList());
        
        
        sizeOfList++;
        return 0;
        
        
    }
    else
    {
        return -1;
    }
    
    
}

int MsgList::insert(int position,int data)
{
    
    if(sizeOfList == 0)
    {
        insert(data);
        return 0;
    }
    
    if(sizeOfList <= limitOfList || !limitOfList)
    {
        node* nowp = find_node(position);
        node* newNode = nodeCreate();
        newNode->data = data;
        setP_node(nowp->p_node, newNode);
        setN_node(newNode, nowp->p_node);
        setP_node(newNode, nowp);
        setN_node(nowp, newNode);
        if(position % sizeOfList == 0)
        {
            setFirstOfList(newNode);

        }
        sizeOfList++;
        return 0;
        
        
    }
    else
    {
        return -1;
    }
}

int MsgList::insert(int primary, int position, int data)
{
    
    if(sizeOfList == 0)
    {
        insert(data);
        return 0;
    }
    
    if(sizeOfList <= limitOfList || !limitOfList)
    {
        node* nowp = find_node(primary,position);
        node* newNode = nodeCreate();
        newNode->data = data;
        setP_node(nowp->p_node, newNode);
        setN_node(newNode, nowp->p_node);
        setP_node(newNode, nowp);
        setN_node(nowp, newNode);
        if((primary+position) % sizeOfList == 0)
        {
            setFirstOfList(newNode);

        }
        sizeOfList++;
        return 0;
        
        
    }
    else
    {
        return -1;
    }
    
}

int MsgList::remove()
{
    if(sizeOfList <= 0)
    {
        return -1;
    }
    node* nowp = getLastOfList();
    setN_node(getFirstOFList(), nowp->p_node);
    setLastOfList(nowp->p_node);
    free_node(nowp);
    sizeOfList--;
    return 0;
}

int MsgList::remove_p(int position)
{
    if(sizeOfList <= 0)
    {
        return -1;
    }
    if((position)%sizeOfList == sizeOfList-1)
    {
        return remove();
    }
    node* nowp = find_node(position);
    setP_node(nowp->p_node, nowp->n_node);
    setN_node(nowp->n_node, nowp->p_node);
    if(position%sizeOfList == 0)
    {
        setFirstOfList(nowp->n_node);
    }

    free_node(nowp);
    sizeOfList--;
    return 0;
}
int MsgList::remove_p(int primary, int position)
{
    if(sizeOfList <= 0)
    {
        return -1;
    }
    if((position+primary)%sizeOfList == sizeOfList-1)
    {
        return remove();
    }
    
    node* nowp = find_node(primary,position);
    
    setP_node(nowp->p_node, nowp->n_node);
    setN_node(nowp->n_node, nowp->p_node);
    if((position+primary)%sizeOfList == 0)
    {
        setFirstOfList(nowp->n_node);
    }
    
    free_node(nowp);
    sizeOfList--;
    return 0;
}
int MsgList::remove_d(int data)
{
    if(sizeOfList <= 0)
    {
        return -1;
    }
    
    int position =  find_position(data);
    if(position && (position)%sizeOfList == sizeOfList-1)
    {
        return remove();
    }
    node* nowp = find_node(position);
    setP_node(nowp->p_node, nowp->n_node);
    setN_node(nowp->n_node, nowp->p_node);
    free_node(nowp);
    if(position%sizeOfList == 0)
    {
        setFirstOfList(nowp->n_node);
    }
    sizeOfList--;
    return 0;
    
}
int MsgList::remove_d(int primary, int data)
{
    if(sizeOfList == 0)
    {
        return -1;
    }
    int position =  find_position(primary, data);
    if(position&&(position)%sizeOfList == sizeOfList-1)
    {
        return remove();
    }
    node* nowp = find_node(position);
    setP_node(nowp->p_node, nowp->n_node);
    setN_node(nowp->n_node, nowp->p_node);
    free_node(nowp);
    if(position%sizeOfList == 0)
    {
        setFirstOfList(nowp->n_node);
    }
    sizeOfList--;
    return 0;
}

void MsgList::free_all()
{
    while(remove()!=-1);
}


int MsgList::modify(int data)
{
    node* nowp = getLastOfList();
    nowp->data= data;
    return 0;
}

int MsgList::modify_p(int position, int data)
{
    node* nowp = find_node(position);
    nowp->data = data;
    return 0;
}
 int MsgList::modify_p(int primary, int position, int data)
{
    node* nowp = find_node(primary, position);
    nowp->data = data;
    return 0;
}
int MsgList::modify_d(int target, int source)
{
    int position = find_position(target);
    if(position)
    {
        node* nowp = find_node(position);
        nowp->data  = source;
        return 0;
    }
    else
    {
        return -1;
    }
}
int MsgList::modify_d(int primary, int target, int source)
{
    int newPosition = find_position(primary, target);
    if(newPosition)
    {
        node* nowp = find_node(newPosition);
        nowp -> data = source;
        return 0;
    }
    else
    {
        return -1;
    }
}




MsgList::~MsgList(){
    free_all();
}
