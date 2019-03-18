

#include "pch.h"
#include<ctype.h>
#include <iostream>

void jie_xi_mac(int a, int b, int c);
void jie_xi_ip(int a, int n[]);
void jie_xi_port(int a);
void jie_xi_data(int a);
void write_data();

int sport;
int dport;
int data_trans;
int smac[6];
int dmac[6];
int sip[4];
int dip[4];
char name[200] = "data_28.txt";
char txt[30] = "data_1.txt";
char pkt[30] = "data_1.pkt";


int main()
{
	int temp_smac_dmac[15];
	
	int temp1[11];
	char temp[30] = "data_1.pkt";
	//sprintf_s(pkt, 30, "data_%d.pkt", 1);
	short int wuyong;
	//int connent1[100];
	FILE* data;
	errno_t err;
	int value;
	for (value = 2; value < 3; value++)
	{
		//sprintf_s(pkt, 100, "data_%d.pkt", value);
		//printf("%s", temp);
		//sprintf_s(txt, 100, "data_%d.txt", value);
		if ((err = fopen_s(&data, pkt, "r")) != 0) {
			printf("无法打开此文件");
		}
		else
		{
			int i;
			for (i = 0; i < 3; i++) {
				fread(&temp_smac_dmac[i], 4, 1, data);
				printf("%x\n", temp_smac_dmac[i]);
			}
			jie_xi_mac(temp_smac_dmac[0], temp_smac_dmac[1], temp_smac_dmac[2]);
			for (i = 0; i < 1; i++)
			{
				fread(&wuyong, 2, 1, data);
			}
			/*dmac[0] = temp_smac_dmac[6];
			dmac[1] = temp_smac_dmac[7];
			dmac[2] = temp_smac_dmac[0];
			dmac[3] = temp_smac_dmac[1];
			dmac[4] = temp_smac_dmac[2];
			dmac[5] = temp_smac_dmac[3];
			smac[0] = temp_smac_dmac[8];
			smac[1] = temp_smac_dmac[9];
			smac[2] = temp_smac_dmac[10];
			smac[3] = temp_smac_dmac[11];
			smac[4] = temp_smac_dmac[4];
			smac[5] = temp_smac_dmac[5];*/
			for (i = 0; i < 11; i++) {
				fread(&temp1[i], 4, 1, data);
				//printf("%x\n", temp_smac_dmac[i]);
			}
			jie_xi_ip(temp1[3], sip);
			jie_xi_ip(temp1[4], dip);
			jie_xi_port(temp1[5]);
			jie_xi_data(temp1[10]);
			printf("%d", dmac[0]);
			printf("SMAC: %0x:%0x:%0x:%0x:%0x:%0x\n", smac[0], smac[1], smac[2], smac[3], smac[4], smac[5]);
			printf("DMAC: %0x:%0x:%0x:%0x:%0x:%0x\n", dmac[0], dmac[1], dmac[2], dmac[3], dmac[4], dmac[5]);
			printf("SIP: %d.%d.%d.%d\n", sip[0], sip[1], sip[2], sip[3]);
			printf("DIP: %d.%d.%d.%d\n", dip[0], dip[1], dip[2], dip[3]);
			printf("SPORT: %d\n", sport);
			printf("DPORT: %d\n", dport);
			printf("DATA: %d\n", data_trans);
			write_data();
			fclose(data);
			/*printf("%d\n", 1 << 2);
			int i;
			for (i = 0; i < 3; i++) {
				fread(&connent1[i], 4, 1, data);
				printf("%x\n", connent1[i]);
				danZiJie(connent1[i]);
			}
			printf("\n");

			for ( i = 0; i < 1; i++)
			{
				fread(&connent[i], 2, 1, data);
				printf("%d\n", connent[i]);
			}
			for (i = 0; i < 11; i++) {
				fread(&connent1[i], 4, 1, data);
				danZiJie(connent1[i]);
				//shuangZiJie(connent1[i]);
				printf("\n");
			}
			for (i = 0; i < 1; i++) {
				fread(&connent1[i], 4, 1, data);
				//danZiJie(connent1[i]);
				shuangZiJie(connent1[i]);
				printf("\n");
			}*/
		}
	}

	system("pause");
}


void jie_xi_mac(int a, int b, int c) {
	int n[4];
	int temp = ~((~0) << 8);
	//printf("%d\n", (a & (temp << 8)) >> 8);
	int i;
	for (i = 0; i < 4; i++)
	{
		//printf("%u\n", (a & (temp << (8 * i))) >> (8 * i));
		printf("%d\n", (a & temp));
		n[i] = a & temp;
		a = a >> 8;
	}
	dmac[5] = n[0];
	dmac[4] = n[1];
	dmac[3] = n[2];
	dmac[2] = n[3];
	for (i = 0; i < 4; i++)
	{
		//printf("%u\n", (a & (temp << (8 * i))) >> (8 * i));
		printf("%d\n", (b & temp));
		n[i] = b & temp;
		b = b >> 8;
	}
	dmac[1] = n[0];
	dmac[0] = n[1];
	smac[5] = n[2];
	smac[4] = n[3];
	for (i = 0; i < 4; i++)
	{
		//printf("%u\n", (a & (temp << (8 * i))) >> (8 * i));
		printf("%d\n", (c & temp));
		n[i] = c & temp;
		printf("ni  %d\n", n[i]);
		c = c >> 8;
	}
	smac[3] = n[0];
	smac[2] = n[1];
	smac[1] = n[2];
	smac[0] = n[3];
	printf("n3  %d\n", n[3]);
	printf("dmac0  %d\n", dmac[0]);
}


void jie_xi_ip(int a, int n[])
{
	int temp = ~((~0) << 8);
	//printf("%d\n", (a & (temp << 8)) >> 8);
	int b = a;
	int i;
	for ( i = 0; i < 4; i++)
	{
		//printf("%u\n", (a & (temp << (8 * i))) >> (8 * i));
		printf("%d\n", (b & temp));
		n[i] = b & temp;
		b = b >> 8;
	}
	
}
void jie_xi_port(int a)
{
	int n[4];
	int temp = ~((~0) << 8);
	//printf("%d\n", (a & (temp << 8)) >> 8);
	int b = a;
	int i;
	for (i = 0; i < 4; i++)
	{
		//printf("%u\n", (a & (temp << (8 * i))) >> (8 * i));
		printf("%d\n", (b & temp));
		n[i] = b & temp;
		b = b >> 8;
	}
	dport = (n[2] << 8) + n[3];
	sport = (n[0] << 8) + n[1];
}

void jie_xi_data(int a)
{
	int n[4];
	int temp = ~((~0) << 8);
	//printf("%d\n", (a & (temp << 8)) >> 8);
	int b = a;
	int i;
	for (i = 0; i < 4; i++)
	{
		//printf("%u\n", (a & (temp << (8 * i))) >> (8 * i));
		printf("%d\n", (b & temp));
		n[i] = b & temp;
		b = b >> 8;
	}
	data_trans = (n[0] << 24) + (n[1] << 16) + (n[2] << 8) + n[3];
}

void write_data() {
	FILE *fp;
	errno_t err;
	if ((err = fopen_s(&fp, txt, "w")) != 0) {
		printf("无法打开此文件");
	}
	else
	{
		fprintf(fp, "SMAC: %0x:%0x:%0x:%0x:%0x:%0x\n", smac[0], smac[1], smac[2], smac[3], smac[4], smac[5]);
		fprintf(fp, "DMAC: %0x:%0x:%0x:%0x:%0x:%0x\n", dmac[0], dmac[1], dmac[2], dmac[3], dmac[4], dmac[5]);
		fprintf(fp, "SIP: %d.%d.%d.%d\n", sip[0], sip[1], sip[2], sip[3]);
		fprintf(fp, "DIP: %d.%d.%d.%d\n", dip[0], dip[1], dip[2], dip[3]);
		fprintf(fp, "SPORT: %d\n", sport);
		fprintf(fp, "DPORT: %d\n", dport);
		fprintf(fp, "DATA: %d\n", data_trans);
	}
	fclose(fp);
}