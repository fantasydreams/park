#include "include\mysql.h"
#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include <vector>

#pragma comment(lib,"libMysql.lib")
#pragma comment(lib, "wsock32.lib")  
#pragma comment(lib, "Advapi32.lib")



#if defined _DEBUG
#pragma comment(lib,"mysqlclient_debug.lib")
#else
#pragma comment(lib,"mysqlclient.lib")
#endif

struct Node_Coordinate
{
	int Node_id;  //�ڵ�ID
	int x;  //x����
	int y;   //y����
	int z;  //z����
};


class Node
{
public:
	Node();
	~Node();
	std::vector<Node_Coordinate> N_Coordinate;  //�洢�ն˽ڵ�ID
private:
	MYSQL* mysql = NULL;
	MYSQL_RES* res = NULL;
	MYSQL_ROW record;
	bool conncetsql(); //�������ݿ�
	void GetNodeToDo();  //���ڵ��¼�����߼����ָ��
	void Active();  //����ڵ�
	void Dormant();  //���߽ڵ�
	bool quary(char, char *); //��ѯ
	void print();  //���Ժ���
	void CoordinateWriteToSql(); //���ն˽ڵ�����д�����ݿ�
	void CoordinateQuery(int, int, int, int);
};




