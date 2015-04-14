#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <tchar.h>
#include <conio.h>
#include <cmath>
#include <cstdio>
#include <string>


class Comm
{
private :
	HANDLE hComm;
	OVERLAPPED m_ov;
	COMSTAT comstat;
	bool open;
	std::string filename;
	FILE *fp;
	int id;
	bool * state;
	LPCWSTR  com;
	public:
	Comm(bool *);
	~Comm();
	void ReceiveChar(); //从协调器读取数据函数
	bool WriteChar(BYTE* m_szWriteBuffer, DWORD m_nToSend);//向协调器发送数据
	bool ProcessErrorMessage(char* ErrorText);
	bool OpenPort(LPCWSTR port);//打开端口函数
	bool setuptimeout(DWORD ReadInterval, DWORD ReadTotalMultiplier, DWORD ReadTotalconstant, DWORD WriteTotalMultiplier, DWORD WriteTotalconstant);//设置无效时间
	bool setupdcb(int rate_arg);//设置DCB,先获取DCB配置，再设置，最后看是否设置完成
	HANDLE GethComm(); //获取当前句柄
	void WriteToFile(char *); //将解析完成的数据写入文件
	void getUsablePort();//得到可用端口
};

struct Coord{
	double x;
	double y;
};

Coord CalPoint(double* distance, char* fgetNo);//计算出点的坐标
void Calcu(unsigned int tote);
//DWORD WINAPI Commrece(LPVOID pParam);//接收串口线程
void GetRSSI(unsigned int i, double* RSSI, char* fgetNo);
void GetDistance(double* Distance, double* RSSI, char* fgetNo);//RSSI转换成距离
double RSSIToD(double RSSI);//将RSSI转换成distance
Coord CalPoin3(double* distance, char* fgetNo);//三个节点时
Coord CalPoin4(double* distance);//两各节点时
DWORD WINAPI Commrece(LPVOID pParam);//串口接收线程
