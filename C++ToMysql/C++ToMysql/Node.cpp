#include "Node.h"


Node::Node()
{
	mysql = mysql_init(mysql);
	if (conncetsql())
		std::cout << "yes"<<std::endl;
	else
		std::cout << "no"<<std::endl;
	if (quary('0',-1))
		print();
}

Node::~Node()
{
	if (res)
		mysql_free_result(res);
	if (mysql)
		mysql_close(mysql);
}

inline bool Node::conncetsql()
{
	if (mysql_real_connect(mysql, "localhost", "root", "lsw19940816", "park", 3306, NULL, NULL))  //���������ݿ�
		return true;  //�ɹ�������
	else
		return false;  //���򷵻ؼ�
}


void Node::GetNodeToDo()
{
	while (true)
	{
		quary(9, -1);
		if (res)
			Active();  //�������
		else
			Sleep(100);  //�߳���ʱ������
		quary(0, -1);
		if (res)
			Dormant();  //���߲���
		else
			Sleep(100);  //�߳���ʱ������
	}
}

bool Node::quary(char var,long int id = -1)
{
	mysql_query(mysql, "set names utf8");
	if ('0' == var)  //�õ���Ҫ���߽ڵ��id
	{
		//select POINT_id from point where todo = 0
		mysql_query(mysql, "select POINT_id from point where todo = 0");
		if (!(res = mysql_use_result(mysql)))
		{
			std::cout << "some little problem��" << mysql_error(mysql);
			return false;
		}
		return true;
	}
	if (var == '9')//�õ���Ҫ����ڵ��id
	{
		mysql_query(mysql, "select POINT_id from point where todo = 9");
		if (!(res = mysql_use_result(mysql)))
		{
			std::cout << "some little problem��" << mysql_error(mysql);
			return false;
		}
		return true;
	}
	if (var == '1' && id > 0) //���ڵ��״̬��Ϊ�����κβ���
	{
		char qury[200];
		_itoa_s(id, qury, 10);
		std::string s = std::string(qury);
		std::string qurysql = "update point set todo = 1 where POINT_id = " + s;
		if (mysql_query(mysql, qurysql.c_str()))
			return true;
		else
			return false;
	}
	return false;  //��ֹ�����������
}


void Node::print()
{
	while (record = mysql_fetch_row(res))
		std::cout << *record << std::endl;
}

void Node::CoordinateWriteToSql()
{
	while (true)
	{
		if (N_Coordinate.begin() != N_Coordinate.end())  //һ�ζ���������Ҫд�����Ϣ���̹߳�����������Ϣд�����ݿ������
		{
			for (std::vector<Node_Coordinate>::iterator iter = N_Coordinate.begin(); iter != N_Coordinate.end(); iter++)
				CoordinateQuery(iter->Node_id, iter->x, iter->y, iter->z); //������Ϣ���º�������
		}
		else
			Sleep(1000);  //�߳���ʱ������
	}
}

void Node::CoordinateQuery(int N_id, int posX, int posY, int posZ)
{
	char str[100];
	_itoa_s(posX, str, 10);    //��ʼ��ʼ����Ҫд��ڵ��λ����Ϣ
	std::string PositionX(str);
	_itoa_s(posY, str, 10);
	std::string PositionY(str);
	_itoa_s(posZ, str, 10);
	std::string PositionZ(str);
	_itoa_s(N_id, str, 10);
	std::string Node_id(str);  
	std::string query = "update point set posX = " + PositionX + " and posY = " + PositionY + " and posZ = " + PositionZ + " where POINT_id = " + Node_id;
	mysql_query(mysql, "set names utf8");
	mysql_query(mysql, query.c_str());  //����λ����Ϣ����
}

void Node::Active()
{

}

void Node::Dormant()
{

}