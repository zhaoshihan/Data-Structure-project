#pragma once
#ifndef LIST_H
#define LIST_H

class Node
{
public:
	Node() = default;
	int getLink();
	int getData();

	void setLink(int num);
	void setData(int num);

private:
	int link;
	int data;
};


int Node::getLink()
{
	return this->link;
}
int Node::getData()
{
	return this->data;
}

void Node::setLink(int num)
{
	this->link = num;
}

void Node::setData(int num)
{
	this->data = num;
}


#endif
